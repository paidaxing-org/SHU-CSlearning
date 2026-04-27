import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("172.20.10.4", 6789);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             Scanner scanner = new Scanner(System.in)) {

            System.out.println("Connected to server");

            // 身份验证
            System.out.print(in.readLine());
            String username = scanner.nextLine();
            out.println(username);

            System.out.print(in.readLine());
            String password = scanner.nextLine();
            out.println(password);

            String response = in.readLine();
            if ("LOGIN_FAILED".equals(response)) {
                System.out.println("Login failed. Disconnecting...");
                return;
            }

            System.out.println("Login successful!");
            System.out.println("Choose an option:");
            System.out.println("1. Send text");
            System.out.println("2. Send file");
            System.out.print("Enter choice (1 or 2): ");

            String choice = scanner.nextLine();
            if ("1".equals(choice)) {
                out.println("TEXT");
                System.out.print("Enter your text: ");
                String text = scanner.nextLine();
                out.println(text);
                System.out.println("Server response: " + in.readLine());
            } else if ("2".equals(choice)) {
                out.println("FILE");
                System.out.print("Enter file path: ");
                String filePath = scanner.nextLine();
                File file = new File(filePath);
                if (!file.exists()) {
                    System.out.println("File not found!");
                    out.println("CANCEL");
                    return;
                }

                try (BufferedReader fileReader = new BufferedReader(new FileReader(file))) {
                    StringBuilder content = new StringBuilder();
                    String line;
                    while ((line = fileReader.readLine()) != null) {
                        content.append(line).append("\n");
                    }

                    out.println(file.getName());
                    out.println(content.length());
                    out.print(content.toString());
                    out.flush();
                    System.out.println("Server response: " + in.readLine());
                }
            }

            System.out.println("Press Enter to exit...");
            scanner.nextLine();
        } catch (IOException e) {
            System.out.println("Client exception: " + e.getMessage());
        }
    }
}
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class UDPClient {
    public static void main(String[] args) {
        final String SERVER_IP = "172.20.10.2"; // 服务器IP
        final int PORT = 6789;

        try (DatagramSocket socket = new DatagramSocket();
             Scanner scanner = new Scanner(System.in)) {

            InetAddress serverAddress = InetAddress.getByName(SERVER_IP);
            System.out.println("Connected to server at " + SERVER_IP + ":" + PORT);

            // 身份验证
            System.out.print("Enter username: ");
            String username = scanner.nextLine();
            System.out.print("Enter password: ");
            String password = scanner.nextLine();

            System.out.print("Enter your message: ");
            String message = scanner.nextLine();

            String fullMessage = username + ":" + password + ":" + message;
            byte[] sendData = fullMessage.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, PORT);
            socket.send(sendPacket);

            // 接收响应
            byte[] receiveData = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);

            String response = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("Server response: " + response);

            System.out.println("Press Enter to exit...");
            scanner.nextLine();
        } catch (IOException e) {
            System.out.println("Client exception: " + e.getMessage());
        }
    }
}
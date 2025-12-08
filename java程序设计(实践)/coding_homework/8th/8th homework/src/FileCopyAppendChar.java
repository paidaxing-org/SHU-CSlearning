import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class FileCopyAppendChar {
    public static void main(String[] args) {
        String sourceFile = "a.txt";
        String targetFile = "b.txt";
        FileReader reader = null;
        FileWriter writer = null;
        try {
            reader = new FileReader(sourceFile);
            writer = new FileWriter(targetFile, true);
            char[] buffer = new char[1024];
            int charsRead;
            System.out.println("开始从 " + sourceFile + " 读取字符数据并追加到 " + targetFile);
            while ((charsRead = reader.read(buffer)) != -1) {
                writer.write(buffer, 0, charsRead);
            }
            System.out.println("文件内容追加完成！");
        } catch (IOException e) {
            System.err.println("发生IO异常: " + e.getMessage());
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
                if (writer != null) {
                    writer.close();
                }
            } catch (IOException e) {
                System.err.println("关闭流时发生异常: " + e.getMessage());
            }
        }
    }
}
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
public class FileCopyAppend {
    public static void main(String[] args) {
        String sourceFile = "a.txt";
        String targetFile = "b.txt";
        FileInputStream fis = null;
        FileOutputStream fos = null;
        try {
            fis = new FileInputStream(sourceFile);
            fos = new FileOutputStream(targetFile, true);
            byte[] buffer = new byte[1024];
            int bytesRead;

            System.out.println("开始从 " + sourceFile + " 读取数据并追加到 " + targetFile);
            while ((bytesRead = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }
            System.out.println("文件内容追加完成！");
        } catch (IOException e) {
            System.err.println("发生IO异常: " + e.getMessage());
            e.printStackTrace();
        } finally {
            try {
                if (fis != null) {
                    fis.close();
                }
                if (fos != null) {
                    fos.close();
                }
            } catch (IOException e) {
                System.err.println("关闭流时发生异常: " + e.getMessage());
            }
        }
    }
}
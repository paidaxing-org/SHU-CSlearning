import java.sql.Date;
import java.time.LocalDate;
public class StudentApplication {
    public static void main(String[] args) {
        Undergraduate undergraduate = new Undergraduate();
        undergraduate.setInformation("王小二", '男', Date.valueOf("2003-6-1"), "上海大学", "21128981", "大学本科生", new double[]{89.5, 82, 87, 73}, false);
        Master master = new Master();
        master.setInformation("李燕", '女', Date.valueOf("2001-6-12"), "上海大学", "10306", "硕士研究生", new double[]{70, 52.5, 95, 88, 89, 91}, false);
        StudentDegree studentDegree = new StudentDegree();
        System.out.println("测试大学本科生学位授予情况：");
        studentDegree.issueDegree(undergraduate);
        System.out.println("测试硕士研究生学位授予情况：");
        studentDegree.issueDegree(master);
    }
}

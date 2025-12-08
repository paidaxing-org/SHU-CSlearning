import java.util.Date;

public class StudentApplication {
    public static void main(String[] args)  {
        Student student;

        String name = "王小二";
        char gender = '男';
        Date birthday = new Date(2005-1900,6,1);
        String school = "上海大学";
        String stuId = "23128981";
        String category = "大学本科生";
        double[] score = {89.5, 82, 87, 73};
        boolean status = false;
        Undergraduate undergraduate = new Undergraduate();
        undergraduate.setInformation(name, gender, birthday, school, stuId, category, score, status);
        undergraduate.computeAverage();
        System.out.println("学生姓名为："+ undergraduate.getName() + " 性别：" + gender + " 出生日期:" + birthday + " 学校：" + school + " 学号：" + stuId);
        if(undergraduate.getPass())
        {
            System.out.println("通过考试");
        }
        else
        {
            System.out.println("未通过考试");
        }
        System.out.println(undergraduate.getDegree());
        student = undergraduate;
        StudentDegree studentDegree = new StudentDegree();
        studentDegree.issueDegree(student);

        name="李燕";
        gender='女';
        Date birthday1= new Date(2003-1900,6,12);
        school="上海大学";
        stuId="10306";
        category="硕士研究生";
        double[] score1={70, 52.5, 95, 88, 89, 91};
        char thesisLevel='B';
        status=false;
        Master master = new Master();
        master.setInformation(name,gender,birthday1,school,stuId,category,score1,status);
        master.setLevel(thesisLevel);
        master.computeAverage();
        System.out.println("学生姓名为："+ master.getName() + " 性别：" + master.getGender() + " 出生日期:" + master.getBirthDay() + " 学校：" + master.getSchool() + " 学号：" + master.getStuId());
        if(master.getPass())
        {
            System.out.println("通过考试");
        }
        else
        {
            System.out.println("未通过考试");
        }
        System.out.println(master.getDegree());


        student = master;
        studentDegree.issueDegree(student);
    }
}

public class StudentDegree {
    public void printStudentInfo(Student student)
    {
        student.computeAverage();
        System.out.println("姓名：" + student.name + "性别：" + student.gender + "出生日期：" +student.birthDay);
        System.out.println("学校：" + student.school + "学号：" + student.stuId + "学生类别：" + student.category);
        System.out.println("平均分：" + student.computeAverage() );
    }

    public void issueDegree(Student student)
    {
        String sta = student.getDegree();
        System.out.println(sta);
    }
}

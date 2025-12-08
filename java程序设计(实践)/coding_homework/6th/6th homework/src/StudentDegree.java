public class StudentDegree {
    public void issueDegree(Manageable manage) {
        try {
            manage.printInfo();
            double average_num = manage.computeAverage();
            System.out.println("学生的平均成绩为 " + average_num);
        } catch (InvalidScoreException e1) {
            System.out.println("成绩异常: " + e1.getMessage());
        } catch (MasterException e2) {
            System.out.println("硕士生异常: " + e2.getMessage());
        } catch (Exception e3) {
            System.out.println("发生了异常: " + e3.getMessage());
        }
    }
}

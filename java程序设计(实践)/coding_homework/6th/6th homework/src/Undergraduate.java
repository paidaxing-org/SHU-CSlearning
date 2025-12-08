public class Undergraduate extends Student implements Manageable  {
    double aver;

    public String getDegree() {

        return (status==true)?Constants.ISSUE_MASTER_DEGREE:Constants.UNSATISFACTORY_ISSUE_UNDERGRADUATE_DEGREE;
    }

    public double computeAverage() throws InvalidScoreException {
        int sum = score.length;
        double alnum = 0.0;
        for (int i = 0; i < sum; i++) {
            if (score[i] < 0 || score[i] > 100) {
                throw new InvalidScoreException("出现异常分数值：" + score[i] + " 分数必须属于0~100！");
            }
            alnum += score[i];
        }
        aver = alnum / sum;
        return aver;
    }

    public boolean getPass() {
        status= (aver >= 60) ? true : false;
        return status;
    }

    public void printInfo() {
        System.out.println("学生姓名为："+ this.getName() + " 性别：" + this.getGender() + " 出生日期:" + this.getBirthDay() + " 学校：" + this.getSchool() + " 学号：" + this.getStuId() + " 学生类别：" + this.getCategory());
        System.out.println("颁发学位状况：" + (status ? "学士学位" : "未满足学士学位要求"));
    }


}

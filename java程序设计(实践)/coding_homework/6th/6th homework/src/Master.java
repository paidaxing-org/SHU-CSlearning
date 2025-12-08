public class Master extends Student implements Manageable {
        double aver;
        char thesisLevel;

        public double getAver() {
            return aver;
        }

        public void setAver(double aver) {
            this.aver = aver;
        }

        public char getThesisLevel() {
            return thesisLevel;
        }

        public void setThesisLevel(char thesisLevel) {
            this.thesisLevel = thesisLevel;
        }
        public String getDegree() {

            return (status==true)? Constants.ISSUE_MASTER_DEGREE: Constants.UNSATISFACTORY_ISSUE_MSTER_DEGREE;
        }

        public double computeAverage() throws Exception {
            int sum = score.length;
            double alnum = 0.0;
            for (int i = 0; i < sum; i++) {
                alnum += score[i];
            }
            aver = alnum / sum;
            return aver;
        }

    public boolean getPass() throws MasterException {
        if (thesisLevel < 'A' || thesisLevel > 'E') {
            throw new MasterException("等级为：" + thesisLevel + "，不合法。等级应该是A到E之间的！");
        }
        status = (aver >= 80) && (thesisLevel <= 'C');
        return status;
    }

        public void printInfo() {
            System.out.println("学生姓名为："+ this.getName() + " 性别：" + this.getGender() + " 出生日期:" + this.getBirthDay() + " 学校：" + this.getSchool() + " 学号：" + this.getStuId()+ " 学生类别：" + this.getCategory());
            System.out.println("颁发学位状况：" + (status ? "硕士学位" : "未满足硕士学位要求"));
        }

}
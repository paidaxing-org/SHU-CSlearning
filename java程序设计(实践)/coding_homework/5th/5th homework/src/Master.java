public class Master extends Student {
    double aver;
    char thesisLevel;
    public void setLevel(char Level){
        this.thesisLevel = Level;
    }
    public String getDegree() {
        return status?"颁发硕士学位":"不能颁发硕士学位";
    }

    public boolean getPass() {
        if(aver>=80.0&&thesisLevel=='C')
        {
            status = true;
            return true;
        }
        else
        {
            status = false;
            return false;
        }
    }

    public double computeAverage() {
        int sum = score.length;
        double alnum = 0.0;
        for (int i = 0; i < sum; i++) {
            alnum += score[i];
        }
        aver = alnum / sum;
        return aver;
    }
}

public class Undergraduate extends Student {

    double aver;

    public String getDegree() {
        return status?"颁发学士学位":"不能颁发学士学位";
    }

    public boolean getPass() {
        if(aver>=60.0)
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

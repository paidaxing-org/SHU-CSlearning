public class FiveNum100 {
    public static void main(String[] args) {
        int num=0;
        for(int i=1;i<=100;i++)
        {
            if(i%3==0)
            {
                System.out.println(i+"能被3整除");
                num++;
            }
            if(num>=5)
                break;
        }
    }
}

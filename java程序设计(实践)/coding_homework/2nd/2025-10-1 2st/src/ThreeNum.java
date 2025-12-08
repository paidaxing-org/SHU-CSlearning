import java.util.Scanner;
public class ThreeNum {
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        while(sum<3)
        {
            int a = sc.nextInt();
            if(a>=1&&a<=100)
            {
                sum++;
                System.out.println("输入正确！ 您目前输出正确了"+ sum +"次");
            }
            else
            {
                System.out.println("输入错误！ 您输入的数字为" + a +" 不在1~100范围之间。");
                System.out.println( "您目前输出正确了"+ sum +"次");
            }
        }
    }
}
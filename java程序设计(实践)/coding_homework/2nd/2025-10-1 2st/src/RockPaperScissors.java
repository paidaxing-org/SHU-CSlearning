import java.util.Scanner;
import java.util.Random;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入你想玩的次数：");
        int t = sc.nextInt();
        Random ran = new Random();
        while(t!=0)
        {
            System.out.println("请输入1、2、3，分别代表剪刀、石头、布");
            int playernum = sc.nextInt();
            switch (playernum)
            {
                case 1:
                    System.out.println("您出的是剪刀");
                    break;
                case 2:
                    System.out.println("您出的是石头");
                    break;
                case 3:
                    System.out.println("您出的是布");
                    break;

            }
            int computernum = ran.nextInt(3) + 1;
            int c1 = playernum * 100 + computernum;
            switch (computernum)
            {
                case 1:
                System.out.println("电脑出的是剪刀");
                break;
                case 2:
                System.out.println("电脑出的是石头");
                break;
                case 3:
                System.out.println("电脑出的是布");
                break;
            }
            switch (c1)
            {
                case 101: case 202: case 303:
                    System.out.println("啊哦，平局了，再来一局吧");
                    break;
                case 103: case 201: case 302:
                    System.out.println("恭喜，您赢了！");
                    break;
                case 102: case 203: case 301:
                    System.out.println("很遗憾，您这一局输了！");
                    break;
                default:
                    System.out.println("输入错误！请重新游戏！");
                    break;
            }
            t--;
        }
    }
}

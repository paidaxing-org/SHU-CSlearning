package subtask3;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Point p1,p2;
        System.out.println("请输入第一个点的x坐标与y坐标：");
        int x1,x2,y1,y2;
        x1 = sc.nextInt();
        y1 = sc.nextInt();
        p1 = new Point(x1,y1);
        System.out.println("请输入第二个点的x坐标与y坐标：");
        x2 = sc.nextInt();
        y2 = sc.nextInt();
        p2 = new Point(x2,y2);
        Line l=new Line(p1,p2);
        System.out.println("这条线段的距离为:"+l.CalDis());
    }
}

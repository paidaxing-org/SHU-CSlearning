package subtask1;

public class computePowerTest {
    public static void main(String[] args) {
        double x = 3.0;
        double y = 4.0;
        System.out.println("x 的值为：" + x + ", y的值为： " + y);
        computePower.compPower(x, y);
        System.out.println("x 的值为：" + x + ", y的值为： " + y);
        System.out.println();
        Parameter p = new Parameter(3.0, 4.0);
        System.out.println("p.a 的值为： " + p.a + ", p.b 的值为： " + p.b);
        computePower.compPower(p);
        System.out.println("p.a 的值为： " + p.a + ", p.b 的值为： " + p.b);
    }
}


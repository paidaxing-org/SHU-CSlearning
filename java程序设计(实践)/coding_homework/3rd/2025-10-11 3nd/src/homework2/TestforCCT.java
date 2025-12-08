package homework2;

public class TestforCCT {
    public static void main(String[] args) {
        Triangle t1 = new Triangle(2.0, 3.0, 4.0);
        if (t1.getIsTriangle()) {
            System.out.println("t1是三角形");
            System.out.println("三角形t1的周长为：" + t1.getC());
        } else {
            System.out.println("t1不是三角形");
        }
        t1.Modify_Triangle(2.0, 1.0, 1.0);
        if (t1.getIsTriangle()) {
            System.out.println("修改后t1是三角形");
            System.out.println("三角形t1的周长为：" + t1.getC());
        } else {
            System.out.println("修改后t1不是三角形");
        }
        Circle c1 = new Circle(2.0);
        System.out.println("c1圆的面积为：" + c1.getS());
        Cone cc = new Cone(c1, 5.0);
        System.out.println("cc圆锥的体积为：" + cc.getV());
        Circle c2 = new Circle(1.0);
        cc.setC(c2);
        System.out.println("修改后cc圆锥的体积为：" + cc.getV());
    }
}

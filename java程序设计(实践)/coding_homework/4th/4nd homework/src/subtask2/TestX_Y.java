package subtask2;

public class TestX_Y {
    public static void main(String[] args) {
        StaticX_Y st1 = new StaticX_Y();
        StaticX_Y st2 = new StaticX_Y();
        st1.sety(2);
        StaticX_Y.setx(3.0);
        st2.sety(5);
        StaticX_Y.setx(4.0);
        System.out.println("st1的x值为："+ StaticX_Y.getx());
        System.out.println("st1的y值为："+ st1.gety());
        System.out.println("st2的x值为："+ StaticX_Y.getx());
        System.out.println("st2的y值为："+ st2.gety());
    }
}

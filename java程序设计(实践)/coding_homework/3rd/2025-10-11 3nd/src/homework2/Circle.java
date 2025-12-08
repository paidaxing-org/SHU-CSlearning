package homework2;

public class Circle {
    private double r, S;
    public final double PI = 3.14159;

    Circle(double r) {
        this.r = r;
        this.S = PI * r * r;
    }
    public void setr(double r) {
        this.r = r;
        S = PI * r * r;
    }
    public double getS() {
        return S;
    }
}

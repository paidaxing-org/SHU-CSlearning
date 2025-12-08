package homework2;

public class Triangle {
    private double a, b, c, C;
    private boolean is_triangle;

    Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.C = a + b + c;
        Is_Triangle();
    }

    public void Is_Triangle() {
        double aa = this.a, bb = this.b, cc = this.c;
        if (((aa + bb) > cc) && ((aa + cc) > bb) && ((cc + bb) > aa))
            this.is_triangle = true;
        else
            this.is_triangle = false;
    }
    public boolean getIsTriangle() {
        return this.is_triangle;
    }

    public void Modify_Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.C = a + b + c;
        Is_Triangle();
    }

    public double getC()
    {
        return this.C;
    }
}

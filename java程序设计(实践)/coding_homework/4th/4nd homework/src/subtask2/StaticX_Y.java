package subtask2;

public class StaticX_Y {
    static double x;
    int y;
    static double getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    static void setx(double x)
    {
        StaticX_Y.x = x;
    }
    void sety(int y)
    {
        this.y=y;
    }
}

package homework2;

public class Cone {
    private Circle c;
    private double h;
    Cone(Circle c, double h){
        this.c = c;
        this.h = h;
    }
    public void setC(Circle c){
        this.c = c;
    }
    public void setH(double h) {
        this.h=h;
    }
    public double getV(){
        double ss=c.getS();
        return h*ss/3.0;
    }
}

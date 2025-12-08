package subtask3;
import java.util.*;
public class Line {
    Point p1;
    Point p2;
    Line(Point p1, Point p2)
    {
        this.p1 = p1;
        this.p2 = p2;
    }
    double CalDis()
    {
        int disx = Math.abs(this.p1.x - this.p2.x);
        int disy = Math.abs(this.p1.y - this.p2.y);
        double ans = Math.sqrt(disx*disx + disy*disy);
        return ans;
    }
}

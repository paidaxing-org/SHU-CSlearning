package subtask1;


class computePower {
    static void compPower(double x, double y) {
        double sx = x * x;
        double sy = y * y;
        System.out.println("x平方的值为： " + sx + ", y平方的值为：" + sy);

    }
    static void compPower(Parameter p) {
        System.out.println("a的值为：" + p.a + ", b的值为：" + p.b);
        double sa = p.a * p.a;
        double sb = p.b * p.b;
        System.out.println("a平方的值为：" + sa + ", b平方的值为：" + sb);
        p.a = sa + sb;
        System.out.println("a的值为：" + p.a + ", b的值为：" + p.b);
    }
}

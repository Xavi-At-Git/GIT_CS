import java.util.Scanner;

public class tw2b {
    double a, b, c;

    void getSides() {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter 3 sides of a triangle:");
        a = in.nextDouble();
        b = in.nextDouble();
        c = in.nextDouble();
    }

    void checkTriangle() {
        if ((a + b) > c && (b + c) > a && (a + c) > b) {
            if (a == b && b == c)
                System.out.println("Triangle is equilateral");
            else if (a == b || b == c || c == a)
                System.out.println("Triangle is isosceles");
            else
                System.out.println("Triangle is scalene");

        } else {
            System.out.println("The triangle sides are invalid. ");
        }
    }

    double computeArea() {
        double s = (a + b + c) / 2;
        double Area;
        Area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
        return Area;

    }

    public static void main(String[] args) {
        tw2b t = new tw2b();
        t.getSides();
        t.checkTriangle();
        if ((t.computeArea()) != 0) {
            System.out.println("Area is " + t.computeArea());
        }
    }
}

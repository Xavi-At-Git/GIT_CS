// package tw2;

import static java.lang.System.exit;
import java.util.Scanner;

class Triangle {
    double a, b, c;

    void getSides() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter 3 sides of a triangle :");
        a = in.nextDouble();
        b = in.nextDouble();
        c = in.nextDouble();
    }

    void checkTriangle() {
        if ((a + b) > c && (b + c) > a && (a + c) > b) {
            if (a == b && a == c)
                System.out.println("Triangle is Equilateral");
            else if (a == b || a == c || b == c)
                System.out.println("Triangle is Isosceles");
            else
                System.out.println("Triangle is Scalene");
        } else {
            System.out.println("Triangle can't be formed!");
            exit(1);
        }
    }

    double area() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }
}

public class TW2B {
    public static void main(String[] args) {
        Triangle t = new Triangle();
        t.getSides();
        t.checkTriangle();

        if (t.area() != 0)
            System.out.println("Area is " + t.area());
    }
}

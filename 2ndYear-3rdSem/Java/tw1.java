import java.util.Scanner;

public class tw1 {
    public static void main(String[] args) {
        int[][] marks = new int[5][3];
        int[] total = new int[5];
        int[] avg = new int[5];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter the marks of Student" + (i + 1) + ":");
            for (int j = 0; j < 3; j++) {
                marks[i][j] = sc.nextInt();
                total[i] += marks[i][j];
            }
        }
        for (int i = 0; i < 5; i++)
            avg[i] = computeAvg(marks[i][0], marks[i][1], marks[i][2]);
        for (int i = 0; i < 5; i++) {
            System.out.println("Total marks of Student " + (i + 1) + " is " + total[i]);
            System.out.println("Total avg of Student " + (i + 1) + " is " + avg[i]);
        }
    }

    static int computeAvg(int m1, int m2, int m3) {
        int min = m1;
        if (min > m2)
            min = m2;
        if (min > m3)
            min = m3;
        int sum = m1 + m2 + m3 - min;
        int avg = (int) Math.ceil(sum / 2.0);
        return avg;

    }
}


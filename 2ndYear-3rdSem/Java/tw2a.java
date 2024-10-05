import java.util.Scanner;

public class tw2a {

    static String sort(char[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return new String(arr);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1, s2;
        System.out.println("Enter two strings s1 and s2: \n");
        s1 = sc.next().toLowerCase();
        s2 = sc.next().toLowerCase();
        if (s1.length() != s2.length()) {
            System.out.println("They are not anagrams");
        }

        char[] C1 = s1.toCharArray();
        char[] C2 = s2.toCharArray();

        String s3 = sort(C1);
        String s4 = sort(C2);

        if (s3.equals(s4)) {
            System.out.println("Both  " + s1 + " and " + s2 + "  are anagrams");
        } else {
            System.out.println("They are not anagrams");
        }
    }


}


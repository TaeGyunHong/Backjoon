import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a[] = new int[9];
        int max = 0, num = 0;

        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt();
            if(max < a[i]) {
            max = a[i];
            num = i + 1;
            }
        }
        System.out.println(max);
        System.out.println(num);
    }
}

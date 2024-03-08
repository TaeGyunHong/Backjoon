import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int square = 0;
        for (int i = 0; i < 5; i++) {
            int num = scan.nextInt();
            square += Math.pow(num, 2);
        }
        scan.close();
        System.out.println(square % 10);
    }
}

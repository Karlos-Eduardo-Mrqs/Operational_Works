import java.util.Scanner;

public class Sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int sum = number * (number + 1) / 2; 
        System.out.println(sum);
        sc.close(); 
    }
}

import java.util.Scanner;

public class HalfNumber {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            double number = sc.nextDouble();
            double half = (number*15/100); 
            System.err.println("50% of "+ number+":"+half);
        }
    }
}

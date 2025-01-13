import java.util.Scanner;
public class EvenOrOdd {
    static void checkEvenOrOdd(int number) {
        if (number % 2 == 0) {
            System.out.println("The number " + number + " is even!");
        } else {
            System.out.println("The number " + number + " is odd!");
        }
    }
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter an integer number: ");
            if (scanner.hasNextInt()) {
                int number = scanner.nextInt();
                checkEvenOrOdd(number);
            } else {
                System.out.println("Invalid input! Please enter a valid integer.");
            }
        }
    }
}
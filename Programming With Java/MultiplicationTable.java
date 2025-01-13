import java.util.Scanner;
public class MultiplicationTable {
    static void displayTable(int number) {
        System.out.println("Mutiplication Table of " + number + ":");
        for (int i = 1; i <= 10; i++) {
            System.out.println(number + " x " + i + " = " + (number * i));
        }
    }
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter with integer number for illustrate your Mutiplication Table: ");
            if (scanner.hasNextInt()) {
                int number = scanner.nextInt();
                displayTable(number);
            } else {
                System.out.println("Invalid Digit! Please, enter with integer number.");
            }
        }
    }
}

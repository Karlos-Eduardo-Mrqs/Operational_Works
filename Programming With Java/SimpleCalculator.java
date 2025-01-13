import java.util.Scanner;

public class SimpleCalculator {

    static boolean ValidSymbol(char symbolOperation) {
        switch (symbolOperation) {
            case '+':
            case '-':
            case 'X':
            case 'x':
            case '/':
                return true; // Operação válida
            default:
                return false; // Operação inválida
        }
    }

    static String Calculate(int number1, int number2, char symbolOperation) {
        switch (symbolOperation) {
            case '+':
                return number1 + "+" + number2 + "=" + (number1 + number2);
            case '-':
                return number1 + "-" + number2 + "=" + (number1 - number2);
            case 'X':
            case 'x':
                return number1 + "X" + number2 + "=" + (number1 * number2);
            case '/':
                if (number2 == 0) {
                    return "Error: Division by zero is not allowed!";
                } else {
                    return number1 + "/" + number2 + "=" + (number1/number2);
                }
            default:
                return "Invalid operation!";
        }
    }
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            System.out.println("Calculator!");

            System.out.print("Enter the first number: ");
            int number1 = scan.nextInt();

            System.out.print("Enter the second number: ");
            int number2 = scan.nextInt();

            System.out.println("What is the operation?");
            System.out.println("[+] Addition | [-] Subtraction | [X] Multiplication | [/] Division");
            char symbolOperation = scan.next().charAt(0);

            if (ValidSymbol(symbolOperation)) {
                String result = Calculate(number1, number2, symbolOperation);
                System.out.println(result);
            } else {
                System.out.println("Invalid operation! Please use [+], [-], [X], or [/].");
  
            }
        }
    }
}
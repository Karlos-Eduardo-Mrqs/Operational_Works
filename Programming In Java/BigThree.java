import java.util.Scanner;

public class BigThree { 
    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            System.out.println("Enter the first integer number:");
            int number1 = scan.nextInt();
            System.out.println("Enter the second integer number:");
            int number2 = scan.nextInt();
            System.out.println("Enter the third integer number:");
            int number3 = scan.nextInt();            
            OrderNumbers(number1, number2, number3);
            
        }
    }

    public static void OrderNumbers(int number1, int number2, int number3) {
        int maior, meio, menor;
        
        if (number1 >= number2 && number1 >= number3) {
            maior = number1;
            if (number2 >= number3) {
                meio = number2;
                menor = number3;
            } else {
                meio = number3;
                menor = number2;
            }
        } else if (number2 >= number1 && number2 >= number3) {
            maior = number2;
            if (number1 >= number3) {
                meio = number1;
                menor = number3;
            } else {
                meio = number3;
                menor = number1;
            }
        } else {
            maior = number3;
            if (number1 >= number2) {
                meio = number1;
                menor = number2;
            } else {
                meio = number2;
                menor = number1;
            }
        }
        // Exibindo os números em ordem decrescente
        System.out.println("Números em ordem decrescente: " + maior + ", " + meio + ", " + menor);
        System.out.println("Números em ordem crescente: " + menor + ", " + meio + ", " + maior);
    }

}
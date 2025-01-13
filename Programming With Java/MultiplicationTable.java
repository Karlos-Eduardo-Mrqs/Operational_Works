import java.util.Scanner;
public class MultiplicationTable {
    static void displayTable(int number) {
        System.out.println("Tabuada Do " + number + ":");
        for (int i = 1; i <= 10; i++) {
            System.out.println(number + " x " + i + " = " + (number * i));
        }
    }
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite um número inteiro para exibir sua tabela de multiplicação: ");
            if (scanner.hasNextInt()) {
                int number = scanner.nextInt();
                displayTable(number);
            } else {
                System.out.println("Entrada inválida! Por favor, digite um número inteiro.");
            }
        }
    }
}

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class RandomNumber {
    // Função para obter os intervalos válidos
    public static int[] getIntervals(Scanner scan) {
        int[] intervals = new int[2]; // [0] -> minInterval, [1] -> maxInterval
        while (true) {
            try {
                System.out.print("Enter the minimum interval for the game: ");
                intervals[0] = scan.nextInt();

                System.out.print("Enter the maximum interval for the game: ");
                intervals[1] = scan.nextInt();

                if (intervals[0] > intervals[1]) {
                    System.out.println("The minimum interval must be smaller than or equal to the maximum interval.");
                } else {
                    break; // Valores válidos, sai do loop
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter integers only.");
                scan.nextLine(); // Limpa o buffer do `Scanner`
            }
        }
        return intervals;
    }
    // Função para gerar o número mágico
    public static int generateMagicNumber(int minInterval, int maxInterval) {
        Random random = new Random();
        int magicNumber = random.nextInt(maxInterval - minInterval + 1) + minInterval;
        System.out.println("Admin: The magic number is: " + magicNumber); // Apenas para testes
        return magicNumber;
    }
    // Função para adivinhar o número
    public static void playGuessingGame(int magicNumber, Scanner scan) {
        int chances = 3;
        while (chances > 0) {
            try {
                System.out.print("What is the Magic Number? You have " + chances + " chance(s): ");
                int userNumber = scan.nextInt();

                if (userNumber == magicNumber) {
                    System.out.println("You guessed it right! The magic number is " + magicNumber + ".");
                    return; // Sai da função após adivinhar corretamente
                } else {
                    chances--;
                    if (chances > 0) {
                        System.out.println("Wrong guess! Try again.");
                    } else {
                        System.out.println("No more chances! The magic number was " + magicNumber + ".");
                    }
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter an integer.");
                scan.nextLine(); // Limpa o buffer do `Scanner`
            }
        }
    }
    // Função para perguntar se o usuário deseja continuar
    public static boolean askToPlayAgain(Scanner scan) {
        System.out.print("Do you want to play again? (yes/no): ");
        String userResponse = scan.next().trim().toLowerCase();
        return !userResponse.equals("no"); // Continua jogando se a resposta não for "no"
    }
    public static void main(String[] args) {
        boolean keepRunning = true;
        Scanner scan = new Scanner(System.in);

        while (keepRunning) {
            int[] intervals = getIntervals(scan); // Obter intervalos
            int magicNumber = generateMagicNumber(intervals[0], intervals[1]); // Gerar número mágico
            System.out.println("The magic number was successfully generated!");
            playGuessingGame(magicNumber, scan); // Jogar o jogo de adivinhação
            keepRunning = askToPlayAgain(scan); // Perguntar se deseja continuar
        }

        System.out.println("Exiting the program. Thank you for playing!");
        scan.close();
    }
}
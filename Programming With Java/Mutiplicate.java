import java.util.Scanner;
public class Mutiplicate {
    static void MutiplicateTable(int number){
        System.out.println("Mutiplicate Table of " + number);
        for (int i = 1 ; i <= 10; i++) {
            System.out.println(number + "X" + i + "=" + number * i);
        }
    }
    public static void main(String[] args) {
        try (Scanner put = new Scanner(System.in)) {
            System.out.print("Digit one int number for illustrate a MutiplicateTable:");
            int number = put.nextInt();
            MutiplicateTable(number);
        }
    }
}
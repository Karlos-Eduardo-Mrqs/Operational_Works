import java.util.Scanner;

class Fact{
    public static void main(String[] args) {
        long fact = 1;
        System.out.print("Digit one integer number :");
        try (Scanner sc = new Scanner(System.in)) {
            int number = sc.nextInt();
            for (int i = 1; i <= number ; i++){
                fact *= i;
            }
        }
        System.out.println(fact);
   }
}
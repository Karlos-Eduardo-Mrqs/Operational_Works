    import java.util.Scanner;
    import java.util.Arrays;
    public class OrderList {
        public static void main(String[] args) {
            try (Scanner scan = new Scanner(System.in)) {
                System.out.print("Enter the quantity of numbers: ");
                int QtdNumbers = scan.nextInt();
                int[] numbers = new int[QtdNumbers];
                for (int i = 0 ; i< numbers.length ; i++){
                    System.out.print("Enter with the number in posistion " + (i+1) +"º :");
                    int number = scan.nextInt(); 
                    numbers[i] = number;
                }
                Arrays.sort(numbers);
                for (int Num : numbers){
                    System.out.println(Num);
                }
            }
        }
    }
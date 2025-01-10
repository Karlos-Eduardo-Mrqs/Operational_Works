import java.util.Scanner;
public class AgeGroup {
    public static void main(String[] args) {
        System.out.print("Digit Your Age:");
        try (Scanner put = new Scanner(System.in)) {
            int Age = put.nextInt();
            if(Age <= 11){
                System.out.println("You Are Child !");
            }else if(Age > 12 && Age <= 17){
                System.out.println("You Are Teen !");
            }else if(Age > 18 && Age <= 64){
                System.out.println("You Are Adult !");
            }
        }
    }
}
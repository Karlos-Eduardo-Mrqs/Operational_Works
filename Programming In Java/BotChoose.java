import java.util.Scanner;

public class BotChoose {
    public static void main(String[] args) {
        bot();
    }
    static void bot(){
        try (Scanner sc = new Scanner(System.in)) {
            int message = sc.nextInt();
            switch(message){
                case 1:
                    System.out.println("Order confirmed");
                break;

                case 2:
                    System.out.println("info@sololearn.com");
                break;

                default:
                    System.out.println("Try again");
                break;
            }
        }
    }   
}

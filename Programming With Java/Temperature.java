import java.util.Scanner;
public class Temperature {
    public static void main(String[] args) {
        try (Scanner put = new Scanner(System.in)) {
            int temperature = put.nextInt();
            if(temperature <= 100){
                System.out.println("Not Boiling");
            }else{
                System.out.println("Boiling");
            }
        }
    }
}

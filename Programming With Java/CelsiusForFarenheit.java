import java.util.Scanner;
public class CelsiusForFarenheit {
    static double fahr(double c){
        return 1.8 * c + 32;
    }   
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            double c = sc.nextDouble(); 
            System.out.println(fahr(c));
        }
    }
}
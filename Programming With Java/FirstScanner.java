import java.util.Scanner;

public class FirstScanner {
    public static void main(String[] args) {
        try (Scanner put = new Scanner(System.in)) {
            String nome = put.nextLine();
            System.out.println("Name:"+nome);
        }
    }
}

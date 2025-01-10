import java.util.Scanner;
public class ColorBox {
    public static void main(String[] args) {
        try (Scanner put = new Scanner(System.in)) {
            String ColorBox = put.nextLine();
            switch (ColorBox) {
                case "red":
                    System.out.println("Box # 1");
                break;
                
                case "blue":
                    System.out.println("Box # 2");
                break;

                case "green":
                    System.out.println("Box # 3");
                break;

                default:
                System.out.println("Box # Nothing");
                break;
            }
        }
    }
}
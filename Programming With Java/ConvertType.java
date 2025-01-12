import java.util.Scanner;

public class ConvertType {
    public static void main(String[] args) {
        try (Scanner put = new Scanner(System.in)) {
            double feet = put.nextDouble();

            double inches = convert(feet);
            System.out.println(inches);
        }
    }

    public static double convert(double feet) {
        return feet * 12;
    }
}

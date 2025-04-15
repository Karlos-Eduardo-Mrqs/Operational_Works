import java.util.Scanner;

public class CinemaSeats {
    
    public static void main(String[] args) {
        int[][] seats = {
        {0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 1, 1}
        };
        try (Scanner sc = new Scanner(System.in)) {
            int row = sc.nextInt();
            int column = sc.nextInt();
            int SealSeat = seats[row] [column];
            if(SealSeat ==  1){
                System.out.println("Sold");
            }else{
                System.out.println("Free");
            }
        }
    }
}
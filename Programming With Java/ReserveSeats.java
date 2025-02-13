import java.util.Arrays;
import java.util.Scanner;

public class ReserveSeats {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // Cria arrays para armazenar as colunas e os assentos
        char[] columns = new char[16]; // 16 letras de 'A' a 'P'
        boolean[] seats = new boolean[16]; // Array para rastrear assentos ocupados (false = disponível)

        // Preenche o array de colunas com letras de 'A' a 'P'
        for (int i = 0; i < columns.length; i++) {
            columns[i] = (char) ('A' + i);
        }

        // Exibe as colunas disponíveis
        System.out.println("Colunas disponíveis: " + Arrays.toString(columns));

        // Solicita ao usuário que escolha uma coluna
        System.out.print("Escolha uma coluna (A-P): ");
        char escolhaColuna = scan.next().toUpperCase().charAt(0);

        // Solicita ao usuário que escolha um assento
        System.out.print("Escolha um assento (0-15): ");
        int escolhaAssento = scan.nextInt();

        // Verifica se a coluna escolhida está disponível
        boolean colunaEncontrada = false;
        int indiceColuna = -1;
        for (int i = 0; i < columns.length; i++) {
            if (columns[i] == escolhaColuna) {
                colunaEncontrada = true;
                indiceColuna = i;
                break;
            }
        }

        if (!colunaEncontrada) {
            System.out.println("Coluna inválida!");
        } else {
            // Verifica se o assento está disponível
            if (escolhaAssento < 0 || escolhaAssento >= seats.length) {
                System.out.println("Assento inválido!");
            } else if (seats[escolhaAssento]) {
                System.out.println("O assento " + escolhaAssento + " já está ocupado!");
            } else {
                // Marca o assento como ocupado
                seats[escolhaAssento] = true;
                System.out.println("Assento " + escolhaAssento + " na coluna " + escolhaColuna + " reservado com sucesso!");
            }
        }

        scan.close();
    }
}
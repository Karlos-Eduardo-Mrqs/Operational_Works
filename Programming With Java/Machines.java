import java.util.Scanner;
public class Machines {
    public static void main(String[] args) {
        Scanner put = new Scanner(System.in);
        System.out.println("Digite a quantidade de itens necessários:");
        int lenItens = put.nextInt();

        String[] itensMenu = new String[lenItens];

        for (int codeNumber = 0; codeNumber < lenItens; codeNumber++) {
            System.out.println("Digite o nome do item com código [ " + codeNumber + " ]:");
            String nameProduct = put.nextLine();
            itensMenu[codeNumber] = nameProduct;
        }

        System.out.println("\nItens cadastrados no menu:");
        for (int i = 0; i < lenItens; i++) {
            System.out.println("Código " + i + ": " + itensMenu[i]);
        }

        put.close(); 
    }
}
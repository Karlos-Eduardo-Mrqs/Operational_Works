import java.util.Scanner;
public class Machines {
    public static void main(String[] args) {
        Scanner put = new Scanner(System.in);
        System.out.println("Enter with quantity of itens :");
        int lenItens = put.nextInt();

        String[] itensMenu = new String[lenItens];

        for (int codeNumber = 0; codeNumber < lenItens; codeNumber++) {
            System.out.println("Enter name of item with code [ " + codeNumber + " ]:");
            String nameProduct = put.nextLine();
            itensMenu[codeNumber] = nameProduct;
        }

        System.out.println("\nRegistered items without menu\r\n" +":");
        for (int i = 0; i < lenItens; i++) {
            System.out.println("Code " + i + ": " + itensMenu[i]);
        }

        put.close(); 
    }
}
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ExampleSwing {
    public static void main(String[] args) {
        // Cria a janela principal
        JFrame frame = new JFrame("Exemplo Swing");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Cria o botão
        JButton button = new JButton("Clique Aqui");

        // Adiciona um ActionListener ao botão
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Ação a ser executada quando o botão for clicado
                JOptionPane.showMessageDialog(frame, "Botão clicado!");
            }
        });

        // Adiciona o botão à janela
        frame.add(button);

        // Torna a janela visível
        frame.setVisible(true);
    }
}
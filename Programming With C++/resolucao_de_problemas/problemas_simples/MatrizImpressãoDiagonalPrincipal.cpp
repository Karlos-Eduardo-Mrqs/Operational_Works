#include <iostream>
#include <cctype>
#include <string>

int main(){
    std::string matriz[5][5];
    std::string ElementoPr ;
    
    for(int coluna = 0  ; coluna < 5 ;coluna++){
        std::cout << std::endl;
        
        for(int linha = 0 ; linha < 5 ;linha++){
            std::cout << coluna << " coluna" << linha << " linha :";
            std::getline(std::cin, matriz[coluna][linha]);
            
            if(coluna == linha){
                ElementoPr = matriz[coluna][linha];
                if( !ElementoPr.empty() ){
                    ElementoPr[0] = toupper(ElementoPr[0]);
                    matriz[coluna][linha] = ElementoPr;
                }
            }
        }
    }
    
    for(int coluna = 0 ; coluna < 5 ;coluna++ ){
        std::cout << std::endl;
        for(int linha = 0 ; linha < 5 ; linha++){
            std::cout << "| " << matriz[coluna][linha]; 
        }
    }
    return 0;
}

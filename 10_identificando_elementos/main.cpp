#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string frase, resultado = "";
    getline(cin, frase);
    frase += ' ';
    int primeira, ultima;
    
    for(int i = 0; i < frase.length() - 2; i++){
        if(i == 0 || frase[i - 1] == ' '){
            primeira = i;
            
            for(int j = i + 1; j < frase.length(); j++){
                if(frase[j] == ' '){
                    ultima = j - 1;
                    // cout << primeira << " " << ultima << endl;
                    
                    bool letra = false, ponto = false, decimal = true;
                    for(int l = primeira; l <= ultima; l++){
                        if(isalpha(frase[l]) != 0){
                            letra = true;
                            decimal = false;
                            ponto = false;
                            break;
                        } else if(frase[l] == '.'){
                            ponto = true;
                            // letra = false;
                            decimal = false;
                        }
                    }
                    
                    if(letra){
                        resultado += "str ";
                    } else if(ponto){
                        resultado += "float ";
                    } else if(decimal){
                        resultado += "int ";
                    }
                    
                    break;
                }
            }
        }
    }
    
    resultado.resize(resultado.length() - 1);
    cout << resultado;
}
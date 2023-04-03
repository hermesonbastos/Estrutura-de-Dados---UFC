#include <iostream>
#include <string>
using namespace std;

int main(){
 string frase;
 getline(cin, frase);
 frase += " ";
 int atual, proxima;
 bool ordenada = true;
 
 for(int primeira = 0; primeira < frase.length(); primeira++){
     if(primeira == 0 || frase[primeira - 1] == ' '){
         atual = primeira;
         
         for(int segunda = primeira + 1; segunda < frase.length(); segunda++){
            if(frase[segunda - 1] == ' '){
                proxima = segunda;
                // cout << primeira << " " << segunda << endl;
                
                for(int i = 0; i < frase.length(); i++){
                    if(frase[primeira + i] > frase[segunda + i]){
                        ordenada = false;
                        // cout << i << " !" << endl;
                        segunda = frase.length();
                        primeira = frase.length();
                        break;
                    } else if(frase[primeira + i] < frase[segunda + i]){
                        break;
                    }
                }
                
                break;
            }
        }
    }
}
 
 if(ordenada){
     cout << "sim";
 } else {
     cout << "nao";
 }
}
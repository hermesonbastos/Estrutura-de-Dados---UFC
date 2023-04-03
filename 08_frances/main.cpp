#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase, result;
    int cont = 0;
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    getline(cin, frase);
    
    for(int letra = 0; letra < frase.length() - 1; letra++){
        cont = 0;
        for(int v = 0; v < 5; v++){
            int aux = 0;
            if(frase[letra] == vogais[v]){
                while(frase[letra + aux + 1] == ' ' && frase[letra + aux + 2] == vogais[v]){
                    cont++;
                    aux += 2;
                }
            }
        }
        frase.erase(letra + 1, 2 * cont);
    }
    
    cout << frase;
}
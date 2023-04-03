#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);
    char f;
    
    cin >> f;
    
    if(f == 'm'){
        for (int i = 0; i < frase.length(); i++) {
            if (isalpha(frase[i])) {
                frase[i] = tolower(frase[i]);
            }
        }
    } else if(f == 'M'){
        for (int i = 0; i < frase.length(); i++) {
            if (isalpha(frase[i])) {
                frase[i] = toupper(frase[i]);
            }
        }
    } else if(f == 'p'){
        
        for (int i = 0; i < frase.length(); i++) {
            if (isalpha(frase[i])) {
                frase[i] = tolower(frase[i]);
            }
        }
        for(int i = 1; i < frase.length(); i++){
            if(frase[i - 1] == ' ' && frase[i + 1] != ' '){
                frase[i] = toupper(frase[i]);
            }
        }
        
    } else if(f == 'i'){
        for(int i = 0; i < frase.length(); i++){
            if(isupper(frase[i])){
                frase[i] = tolower(frase[i]);
            } else if(islower(frase[i])){
                frase[i] = toupper(frase[i]);
            }
        }
    }
    
    cout << frase;
}
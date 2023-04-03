#include <iostream>
using namespace std;

bool ordenado(int vet[], int num_dominos){
    
    for(int i = 0; i < num_dominos - 1; i++){
        if(vet[i] > vet[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int num_dominos;
    cin >> num_dominos;
    int dominos[num_dominos];
    
    
    for(int i = 0; i < num_dominos; i++){
        cin >> dominos[i];
    }
    
    if(ordenado(dominos, num_dominos)){
        cout << "ok\n";
    } else {
        cout << "precisa de ajuste";
    }
}
#include <iostream>
using namespace std;

bool primo(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int inicio, fim;
    cin >> inicio >> fim;
    
    for(int i = inicio; i <= fim; i++){
        if(!!primo(i)){
            cout << i << "\n";
        }
    }
    
}
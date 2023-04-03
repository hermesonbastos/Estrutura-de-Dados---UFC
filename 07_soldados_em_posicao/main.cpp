#include <iostream>
using namespace std;

int main(){
    int l = 0, c = 0;
    cin >> l >> c;
    int soldados[l][c];
    int qtd = 0;
    
    for(int linha = 0; linha < l; linha++){
        for(int coluna = 0; coluna < c; coluna++){
            cin >> soldados[linha][coluna];
        }
    }
    
    for(int coluna = 0; coluna < c; coluna++){
        for(int linha = 0; linha < l - 1; linha++){
            if(soldados[linha + 1][coluna] < soldados[linha][coluna]){
                qtd++;
            }
        }
    }
    
    cout << qtd;
}
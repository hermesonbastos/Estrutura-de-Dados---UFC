#include <iostream>
#include <string>
using namespace std;

void preencheVetor(int *v, int n){
    if(n == 0){
        return;
    }
    preencheVetor(v, n - 1);
    cin >> v[n - 1];
}

void trianguloSomas(int *v, int n){

    if(n == 0){
        return;
    }

    int vet[n - 1];

    for(int i = n - 1; i > 0; i--){
        vet[i - 1] = v[i] + v[i - 1];
    }

    trianguloSomas(vet, n - 1);

    string str = "[";
        for(int i = 0; i < n; i++){
            if(i == n - 1){
                str += to_string(v[i]) + "]";
            } else {
                str += to_string(v[i]) + ", ";
            }
        }
    cout << str << endl;
    return;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    int v[n];
    preencheVetor(v, n);
    trianguloSomas(v, n);
    return 0;
}
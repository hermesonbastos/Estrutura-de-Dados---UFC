#include <iostream>
#include <iomanip>
using namespace std;

float fatorial(float n){
        if(n == 1){
            return 1;
        } else {
            return n * fatorial(n - 1);
        }
    }
    
float euler(float n){
        if(n == 0){
            return 1;
        } else {
            float fracao = 1/fatorial(n);
            return fracao + euler(n - 1);
        }
    }

int main(){
    int n;
    cin >> n;
    cout << fixed << setprecision(6);
    cout << euler(n);
}
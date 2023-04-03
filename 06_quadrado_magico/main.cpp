#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int r, j1, j2;
    
    cin >> r >> j1 >> j2;
    
    if(abs(r - j1) < abs(r - j2)){
        cout << "primeiro";
    } else if(abs(r - j2) < abs(r - j1)){
        cout << "segundo";
    } else {
        cout << "empate";
    }
}
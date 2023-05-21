#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> num;
    int n , op, x;
    string result = "[ ";

    cin >> n >> op;
    for(int i = 0; i < n; i++){
        cin >> x;
        num.push_back(x);
    }

    for(int i = 0; i < op; i++){
        vector<int> aux(n);
        for(int j = 0; j < n; j++){
            if(j == n - 1){
                aux[0] = num[j];
            } else {
                aux[j + 1] = num[j];
            }
        }

        for(int i = 0; i < n; i++){
            num[i] = aux[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(i == n - 1){
            result += to_string(num[i]) + " ]";
        } else {
            result += to_string(num[i]) + " ";
        }
    }

    cout << result << endl;
}

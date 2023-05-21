#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> strings;
    vector<string> consultas;
    int s, c;
    string frase, result = "";

    cin >> s;
    cin.ignore();
    for(int i = 0; i < s; i++){
        getline(cin, frase);
        strings.push_back(frase);
    }

    cin >> c;
    cin.ignore();
    for(int i = 0; i < c; i++){
        getline(cin, frase);
        consultas.push_back(frase);
    }

    for(int i = 0; i < c; i++){
        int count = 0;
        for(int j = 0; j < s; j++){
            if(consultas[i] == strings[j]){
                count++;
            }
        }
        result += to_string(count) + " ";
    }

    cout << result;
}
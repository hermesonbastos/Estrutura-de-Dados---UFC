// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     int n, r, aux;
//     string result = "";
//     cin >> n;
//     vector<int> fila;
//     for(int i = 0; i < n; i++){
//         cin >> aux;
//         fila.push_back(aux);
//     }

//     cin >> r;
//     vector<int> saida;
//     for(int i = 0; i < r; i++){
//         cin >> aux;
//         saida.push_back(aux);
//     }

//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < fila.size(); j++){
//             if(saida[i] == fila[j]){
//                 fila.erase(fila.begin() + j);
//                 break;
//             }
//         }
//     }

//     for(int i = 0; i < n; i++){
//         if(fila[i] != 0){
//             if(i == n - 1){
//                 result += to_string(fila[i]);
//             } else {
//                 result += to_string(fila[i]) + " ";
//             }
//         }
//     }

//     cout << result << endl;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> fila(n);

    for (int i = 0; i < n; ++i) {
        cin >> fila[i];
    }

    cin >> m;
    vector<int> saida(m);

    for (int i = 0; i < m; ++i) {
        cin >> saida[i];
    }

    for (int i = 0; i < m; ++i) {
        fila.erase(remove(fila.begin(), fila.end(), saida[i]), fila.end());
    }

    for (int i = 0; i < fila.size(); ++i) {
        cout << fila[i] << " ";
    }

    cout << endl;
}

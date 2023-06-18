#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> teams;
    int casa, fora;
    // Preenche a fila com a tabela ASCII, de A(int 65) até P(int 80)
    for(int i = 65; i <= 80; i++){
        teams.push(i);
    }

    while(teams.size() > 1){//enquanto não encontrar o vencedor
        cin >> casa >> fora;

        // compara os dois times iniciais, joga o vecendor pro fim da fila
        // e apaga os dois do começo da fila para a próxima partida
        if(casa > fora){
            teams.push(teams.front());
            teams.pop();
            teams.pop();
        } else {
            teams.pop();
            teams.push(teams.front());
            teams.pop();
        }

        // impressão para testes
        // queue<char> teste = teams;
        // while(!teste.empty()){
        //     cout << teste.front();
        //     teste.pop();
        // }
    }

    // imprime o time restante (vencedor)
    cout << teams.front() << endl;
}
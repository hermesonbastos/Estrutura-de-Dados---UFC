#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef struct Aluno{
    int matricula;
    string nome;
    double media;
} Aluno;

void preencherFicha(Aluno &aluno){
    cin >> aluno.matricula;
    cin.ignore(1);
    getline(cin, aluno.nome);
    cin >> aluno.media;
    cin.ignore(1);
}

int buscar_aluno(Aluno *classe, int tamanho, int m){
    for(int i = 0; i < tamanho; i++){
        if(classe[i].matricula == m){
            return i;
        }
    }

    return -1;
}

int main(){
    int tamanho, m;
    cin >> tamanho;
    Aluno classe[tamanho];

    for(int i = 0; i < tamanho; i++){
        preencherFicha(classe[i]);
    }

    cin >> m;

    int indice = buscar_aluno(classe, tamanho, m);

    if(indice == -1){
        cout << "NAO ENCONTRADA";
    } else {
        cout << fixed << setprecision(1) << classe[indice].nome << endl << classe[indice].media << endl;
    }
}
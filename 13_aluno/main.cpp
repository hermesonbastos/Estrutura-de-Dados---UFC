#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct Aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
} Aluno;

void preencherFicha(Aluno &aluno){
    getline(cin, aluno.nome);
    cin >> aluno.matricula;
    cin.ignore(1);
    getline(cin, aluno.disciplina);
    cin >> aluno.nota;
    cin.ignore(1);
}

void status_disciplina(Aluno &aluno){
    if(aluno.nota >= 7){
        cout << aluno.nome << " aprovado(a) em " << aluno.disciplina << endl;
    } else {
        cout << aluno.nome << " reprovado(a) em " << aluno.disciplina << endl;
    }
}

int main(){
    Aluno a1;
    preencherFicha(a1);

    status_disciplina(a1);
}
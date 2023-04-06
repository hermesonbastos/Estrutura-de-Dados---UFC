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

void maiorNota(Aluno aluno1, Aluno aluno2){
    if(aluno1.disciplina == aluno2.disciplina){
        if(aluno1.nota == aluno2.nota){
            cout << fixed << setprecision(1) << aluno1.nome << " e " << aluno2.nome << " , " << aluno1.nota << endl;
        } else if(aluno1.nota > aluno2.nota){
            cout << fixed << setprecision(1) << aluno1.nome << " , " << aluno1.nota << endl;
        } else if(aluno2.nota > aluno1.nota){
            cout << fixed << setprecision(1) << aluno2.nome << " , " << aluno2.nota << endl;
        }
    } else {
        cout << "É preciso que as matérias comparadas sejam as mesmas!" << endl;
    }
}

void preencherFicha(Aluno &aluno){
    getline(cin, aluno.nome);
    cin >> aluno.matricula;
    cin.ignore(1);
    getline(cin, aluno.disciplina);
    cin >> aluno.nota;
    cin.ignore(1);
}

int main(){
    Aluno aluno1;
    Aluno aluno2;
    preencherFicha(aluno1);
    preencherFicha(aluno2);
    
    maiorNota(aluno1, aluno2);
}
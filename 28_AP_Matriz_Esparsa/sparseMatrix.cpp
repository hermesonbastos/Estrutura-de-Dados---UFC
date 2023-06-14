#include <iostream>
#include "Node.h"
#include "SparseMatrix.h"
using namespace std;

// > Cria uma matriz esparsa vazia de tamanho m x n, com um nó cabeça e um nó sentinela para cada linha e coluna
// - se m ou n forem menores ou iguais a 0, lanca um erro e nao cria a matriz
SparseMatrix::SparseMatrix(int m, int n){
    if(m > 0 && n > 0){
        m_head = new Node(m_head, m_head, 0, 0); // cria o nó cabeça apontado para ele mesmo para e baixo e para a direita
        n_lin = m;
        n_col = n;
        
        Node *aux = m_head; // auxiliar é o m_head
        for(int i = 1; i <= n_lin; i++){ // percorre o número de linhas de 1 até o tamanho
            aux->abaixo = new Node(nullptr, nullptr, i, 0); // auxiliar abaixo aponta para um novo nó
            aux = aux->abaixo; // auxiliar é o nó abaixo dele
            aux->direita = aux; // auxiliar direita aponta para ele mesmo
            aux->abaixo = m_head;
        }

        aux = m_head; // auxiliar é o m_head
        for(int i = 1; i <= n_col; i++){ // percorre o número de colunas, de 1 ao tamanho
            aux->direita = new Node(nullptr, nullptr, 0, i); // auxiliar direita aponta para um NOVO nó
            aux = aux->direita; // auxiliar é o NOVO nó
            aux->abaixo = aux; // auxiliar abaixo aponta para ele mesmo
            aux->direita = m_head;
        }
    } else {
        cout << "Insira tamanhos validos! (O numero de linhas e de colunas devem ser maiores que 0)." << endl;
    }
}
// > Retorna o numero de linhas da matriz.
int SparseMatrix::getLin(){
    return n_lin;
}
// > Retorna o numero de colunas da matriz.
int SparseMatrix::getCol(){
    return n_col;
}

// > Recebe o numero de linhas e colunas de uma matriz e verifica se eles existem
//   - Retorna true se os indices nao existirem
bool SparseMatrix::indice_invalido(int i, int j){
    return i > n_lin || j > n_col || i < 1 || j < 1;
}

// > Desaloca o nó correspondente a linha i e a coluna j
//   - Retorna um erro caso os indices nao corresponderem ao tamanho da matriz atual
void SparseMatrix::apagaNo(int i, int j){
    if(indice_invalido(i, j)){
        cout << "\n* TENTE UM INDICE VALIDO AO TAMANHO DA MATRIZ *\n";
    } else {
        Node *auxl = m_head; // auxl é m_head
        for(int k = 1; k <= n_lin; k++){ // percorre todas as linhas, de 1 até o número de linhas
            if(auxl->linha == i){
                break;
            } else {
                auxl = auxl->abaixo; // auxl é o próximo nó abaixo
            }
        }

        Node *auxc = m_head; // aux é m_head
        for(int k = 1; k <= n_col; k++){ // percorre todas as colunas, de 1 ao tamanho
            if(auxc->coluna == j){
                break;
            } else {
                auxc = auxc->direita; // auxc é igual ao próximo a direita
            }
        }

        // percorre a linha até o anterior ao no a ser deletado
        while (auxl->direita->coluna < j && auxl->direita->coluna != 0) {
            auxl = auxl->direita;
        }

        // percorre a coluna até a anterior ao no a ser deletado
        while (auxc->abaixo->linha < i && auxc->abaixo->linha != 0) {
            auxc = auxc->abaixo;
        }
                
        Node *aux_del = auxl->direita; // aux_del aponta para o no a ser deletado
        auxl->direita = aux_del->direita; // auxl aponta para a direita do no a ser deletado
        auxc->abaixo = aux_del->abaixo; // auxc aponta para abaixo do no a ser deletado
        delete aux_del;
    }
}

// > Desaloca completamente uma matriz esparsa
SparseMatrix::~SparseMatrix(){
    Node* auxl = m_head->direita;

    // Percorre cada coluna enquando ela não for o no cabeca
    while(auxl != m_head){
        Node* auxc = auxl->abaixo;
        // Percorre cada linha enquanto ela nao for o no cabeca
        while(auxc != auxl){
            Node* aux_del = auxc->abaixo;
            delete auxc;
            auxc = aux_del;
        }
        // Apaga o no cabeca da coluna correspondente
        Node* aux_del = auxl->direita;
        delete auxl;
        auxl = aux_del;
    }

    // Desaloca os nos sentinelas de cada linha
    auxl = m_head->abaixo;
    while(auxl != m_head){
        Node* aux_del = auxl->abaixo;
        delete auxl;
        auxl = aux_del;
    }

    // Apaga o no cabeca
    delete m_head;
}

// > Insere um valor na posicao i, j na matriz esparsa selecionada.
//   - Lanca uma mensagem de erro caso i ou j, nao correspondam ao tamanho da matriz selecionada.
void SparseMatrix::insert(int i, int j, double value){

    if(indice_invalido(i, j)){
        cout << "\n* TENTE UM INDICE VALIDO AO TAMANHO DA MATRIZ *\n" << endl;
        return;
    } else {
        // O auxl percorre todos os sentinelas das linhas a partir da coluna 1 para encontrar a linha fornecida pelo usuario(i)
        Node *auxl = m_head->abaixo;
        for(int k = 1; k <= n_lin; k++){
            if(auxl->linha == i){
                break;
            } else {
                auxl = auxl->abaixo;
            }
        }
        // O auxl percorre todas as colunas da linha "i" para encontrar o nó antecessor a coluna "j"
        while (auxl->direita->coluna != 0 && auxl->direita->coluna < j){
            auxl = auxl->direita;
        }

        // O auxc percorre todos os sentinelas das colunas a partir da coluna 1 para encontrar a coluna fornecida pelo usuario(j)
        Node *auxc = m_head->direita;
        for(int k = 1; k <= n_col; k++){ 
            if(auxc->coluna == j){
                break;
            } else {
                auxc = auxc->direita;
            }
        }
        // O auxc percorre todas as linhas da coluna "j" para encontrar o nó antecessor a linha "i"
        while (auxc->abaixo->linha != 0 && auxc->abaixo->linha < i){
            auxc = auxc->abaixo;
        }

        // Verifica se o nó informado já existe
        if(auxl->direita->coluna == j && auxc->abaixo->linha == i){
            // Se o valor a inserir for igual a 0, ele desaloca a memoria do nó
            if(value != 0){
                auxl->direita->valor = value;
                return;
            } else {
                Node* aux_lin = auxl->direita->direita;
                Node* aux_col = auxc->abaixo->abaixo;
                delete auxl->direita;
                auxl->direita = aux_lin;
                auxc->abaixo = aux_col;
                return;
            }
        } else {
            Node* novo = new Node(value, auxl->direita, auxc->abaixo, i, j);
            auxl->direita = novo;
            auxc->abaixo = novo;
            return;
        }  

    }
}
// > Devolve o valor contido na linha i e coluna j da matriz.
//  -Lanca uma mensagem de erro caso i ou j, nao correspondam ao tamanho da matriz selecionada.
double SparseMatrix::get(int i, int j){
    if (indice_invalido(i, j)) {
        cout << "\n* TENTE UM INDICE VALIDO AO TAMANHO DA MATRIZ *\n" << endl;
        return 0.0;
    } else {
        // O auxl percorre todos os sentinelas das linhas a partir da coluna 1 para encontrar a linha fornecida pelo usuario(i)
        Node* auxl = m_head;
        for (int k = 1; k <= n_lin; k++) {
            if (auxl->linha == i) {
                break;
            } else {
                auxl = auxl->abaixo;
            }
        }
        // O auxc percorre todos os sentinelas das colunas a partir da coluna 1 para encontrar a coluna fornecida pelo usuario(j)
        Node* auxc = m_head;
        for (int k = 1; k <= n_col; k++) {
            if (auxc->coluna == j) {
                break;
            } else {
                auxc = auxc->direita;
            }
        }
        // Percorre a matriz esparsa ate encontrar a linha e coluna especificada.
        Node* atual_linha = auxl;
        for (int at = 0; at <= n_col; at++) { 
            if (atual_linha->coluna < j) { // Verfica se nao esta ultrapassando o numero de colunas.
                atual_linha = atual_linha->direita;
            } else if (atual_linha->coluna == j) { // verifica se a coluna da linha atual é o mesmo que j
                return atual_linha->valor; // retorn o valor na linha i e coluna j atual
            } else {
                return 0.0; // Elemento não encontrado, valor padrão 0.0
            }
        }
    }

    return 0; // Elemento não encontrado, valor padrão 0.0
}
// > Printar matriz esparsa
void SparseMatrix::print(){
    Node* auxl = m_head->abaixo; // Recebe o primeiro nó sentinela (excluindo o nó cabeça).

    while (auxl != m_head) {
    Node* atual = auxl->direita; // Recebe o primeiro nó da linha.

    // Percorre as linhas e colunas
    for (int j = 1; j <= n_col; j++) {
        if (atual != auxl && atual->coluna == j) { // Se atual for diferente do no sentinela.
            cout << atual->valor << " "; // Imprime valor contido nesse nó
            atual = atual->direita; // avança para o próximo.
        } else {
            cout << "0 ";
        }
    }   

    cout << endl;
    auxl = auxl->abaixo;
    }
}

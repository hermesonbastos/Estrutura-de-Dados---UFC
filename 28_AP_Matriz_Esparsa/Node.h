//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923
//                                                             //
//-------------------------------------------------------------//


#ifndef NODE_H
#define NODE_H
struct Node {

    Node *direita;
    Node *abaixo;
    int linha;
    int coluna; 
    double valor;

    // > Cria um nó com 5 atributos, uma referencia para o no a direita, uma referencia para o no abaixo,
    // o numero da linha, o numero da coluna e o valor contido
    Node(const double& val, Node *right = nullptr, Node *down = nullptr, int l = 0, int c = 0){
        valor = val;
        direita = right;
        abaixo = down;
        linha = l;
        coluna = c;
    }

    // - Quando for o nó cabeça ou sentinela, nao inicializa o valor
    Node(Node *right = nullptr, Node *down = nullptr, int l = 0, int c = 0){
        direita = right;
        abaixo = down;
        linha = l;
        coluna = c;
    }
};


#endif

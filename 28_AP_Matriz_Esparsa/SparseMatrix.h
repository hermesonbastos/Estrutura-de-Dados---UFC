//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923
//                                                             //
//-------------------------------------------------------------//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"

// Interface da classe SparseMatrix
class SparseMatrix {

    private:

        Node *m_head; // nó cabeça
        int n_col {0}; // número de colunas
        int n_lin {0}; // número de linhas

    public:

        // Construtor da classe SparseMatrix
        // - Recebe o número de linhas(m) e colunas(n)
        SparseMatrix(int m, int n);

        void apagaNo(int i, int j);

        bool indice_invalido(int i, int j);

        int getLin();

        int getCol();
        // Destrutor
        ~SparseMatrix();

        // Insere um valor na SparseMatrix
        // - Recebe a linha(i) e a coluna (j) junto do valor(value) a ser inserido na determinada posição
        void insert(int i, int j, double value);

        double get(int i, int j);

        // Printa a matriz A no terminal
        // Inclusive os elementos iguais a 0
        void print();
};

#endif

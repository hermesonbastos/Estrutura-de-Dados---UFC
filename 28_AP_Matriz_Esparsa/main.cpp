//--------------------------- Dupla ---------------------------//
//                                                             //
//                Hermeson Bastos Maia - 537806                //
//             João Paulo Almeida Miranda - 540923             //
//                                                             //
//-------------------------------------------------------------//

#include <iostream>
#include <string>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>
using namespace std;

std::vector<SparseMatrix*> vec_matrix;

// > Recebe um arquivo matrix.txt contendo uma matriz como parametro e retorna a 
// leitura das linhas, colunas e valores dessa matriz lida.
//    - Verifica se o arquivo é aberto corretamente.
//       - Se não conseguir ser aberto, retorna uma mensagem de erro.
//    - Extrai o numero de linhas e colunas da input_matrix.
//    - Cria uma nova matriz que irá armazenar as linhas, colunas e valores lidos.
//    - Linhas, colunas e valores são inseridos na nova matrix criada enquanto tiverem
// valores para serem extraídos no input_arquivo.
//    - Fecha o arquivo que foi extraído.
//    - Retorna a nova matriz contendo os valores extraídos do input_arquivo.
SparseMatrix* readSparseMatrix(const string& arquivo_matrix) {
   ifstream input_arquivo(arquivo_matrix);

   if(!input_arquivo.is_open()) {
      std::cout << "\n*ERRO AO ABRIR O ARQUIVO DE ENTRADA, TENTE NOVAMENTE.*\n" << std::endl;
      return nullptr;
   }

   int numLin, numCol;
   input_arquivo >> numLin >> numCol;

   SparseMatrix* read_matrix = new SparseMatrix(numLin, numCol);

   int lin, col;
   double value;
   while (input_arquivo >> lin >> col >> value) {
      read_matrix->insert(lin, col, value);
   }

   vec_matrix.push_back(read_matrix);
   
   input_arquivo.close();

   cout <<  "\n--- Matriz lida com sucesso ---\n";
   return read_matrix;
}

// > Retorna a soma de duas matrizes ou a soma de uma matriz consigo mesma.
//    - Caso em que verifica se a matriz A e a matriz B tem o mesmo tamanho.
//       - Se os tamanhos forem diferentes, retorna uma mensagem de erro.
//    - Primeiro loop percorrendo da posição 1 até chegar no numero total de linhas.
//    - Segundo loop percorrendo da posição 1 até o numero total de colunas.
//    - Insere na nova matriz sumMatriz a linha, coluna e a soma dos valores nessa posição.
//    - retorna a nova matriz com valores somados de A e B.
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B) {
   
   if(A->getLin() == B->getLin() && A->getCol() == B->getCol()) {
      SparseMatrix* sumMatrix = new SparseMatrix(A->getLin(), A->getCol());
      for (int i = 1; i <= A->getLin(); i++) {
         for (int j = 1; j <= B->getCol(); j++) {
            sumMatrix->insert(i, j, A->get(i, j) + B->get(i, j));
         }
      }
      return sumMatrix;
   } else {
      std::cout << "* NAO E PERMITIDO SOMAR DUAS MATRIZES DE TAMANHOS DIFERENTES *" << "\n";
      std::cout << "Dica: Se voce tentar somar duas matrizes esparsas de tamanhos diferentes, nao havera uma correspondencia exata entre os elementos das matrizes. As dimensoes diferentes implicam que nao ha elementos correspondentes em todas as posicoes. Portanto, a operacao de soma nao faz sentido nesse contexto.\n";
      return nullptr;
   }
}

// > Recebe duas matrizes A e B de tamanho m x n e n x m respectivamente, gera uma nova matriz com o produto das duas
//   - Caso o numero de colunas de A seja diferente do numero de linhas de B, imprime uma mensagem de erro
SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B) {
   
   if(A->getCol() == B->getLin()){
      SparseMatrix* multMatrix = new SparseMatrix(A->getLin(), B->getCol());
      for (int i = 1; i <= multMatrix->getLin(); i++) {
         for (int j = 1; j <= multMatrix->getCol(); j++) {
            double aux = 0;
            for(int k = 1; k <= A->getCol(); k++) {
               aux += A->get(i, k) * B->get(k, j);
            }
            multMatrix->insert(i, j, aux);
         }
      }
      return multMatrix;

   } else {
      std::cout << "* SO EH PERMITIDO MULTIPLICAR DUAS MATRIZES QUANDO O NUMERO DE COLUNAS DA PRIMEIRA E IGUAL AO NUMERO DE LINHAS DA SEGUNDA *" << "\n";
      std::cout << "Dica: Tente multiplicar matrizes em que o numero de colunas de A e igual ao numero de linhas de B.\n";
   }
}

// > Recebe um vetor de ponteiros para matrizes esparsas, imprime o índice das matrizes disponíveis e retorna true
//   - Caso não haja nenhuma matriz disponivel, retorna false para tratamento de erros
bool mostrarMatrizesDisponiveis(std::vector<SparseMatrix*> vector_matrix){
   string disp = "\n> MATRIZES DISPONIVEIS: ";
   if(vector_matrix.size() == 0){
      return false;
   } else {
      for(int i = 0; i < vector_matrix.size(); i++){
         if(i == vector_matrix.size() - 1) disp += "[" + to_string(i + 1) + "]\n";
         else disp += "[" + to_string(i + 1) + "] ";
      }
      cout << disp;
      return true;
   }
}

int main() {
   
   int resposta;
   int sair = 0;
   std::cout << "\n                  por\n ------ <Joao Paulo Almeida>  ------\n              <Hermeson Bastos>\n";
   while (sair == 0) {
      std::cout << "\n ------ Menu de criacao e manipulacao de Matriz Esparsa ------\n";
      std::cout << "1. Criar uma matriz manualmente.\n";
      std::cout << "2. Ler matriz de um arquivo. (inclua .txt)\n";
      std::cout << "3. Preencher matriz inteira.\n";
      std::cout << "4. Inserir em uma posicao especifica da matriz.\n";
      std::cout << "5. Imprimir matriz(es).\n";
      std::cout << "6. Somar matrizes.\n";
      std::cout << "7. Multiplicar matrizes.\n";
      std::cout << "8. Apagar valor de uma posicao especifica.\n";
      std::cout << "9. Ver matrizes existentes.\n";
      std::cout << "10. Sair.\n";
      std::cout << "> Selecione uma opcao: ";
      std::cin >> resposta;

      switch (resposta) {
         // > Cria uma nova matriz esparsa e insere no final do vec_matrix
         //    - Se o numero de linhas ou de colunas for igual a 0, imprime um erro.
         //    - Cria uma nova matriz esparsa e insere no vetor de matrizes.
         case 1: {
            int numLin, numCol;
            cout << "\nInforme o numero de linhas da sua matriz: ";
            cin >> numLin;
            cout << "Agora informe o numero de colunas da sua matriz: ";
            cin >> numCol;

            if(numLin == 0 || numCol == 0) {
               cout << "\n-- Matriz invalida, por favor tente novamente. --\n";
               cout << "\nDica: A definicao de uma matriz requer pelo menos uma linha e uma coluna para ter algum tipo de conteudo. Uma matriz sem elementos nao faz sentido, pois nao existem dados para armazenar ou acessar.\n";
               break;
            }
            SparseMatrix *sparseMatrix = new SparseMatrix(numLin, numCol);
            vec_matrix.push_back(sparseMatrix);

            cout << "\n--- Matriz criada com sucesso! ---\n";
            break;
         }
         // > Cria uma nova matriz que recebe uma matriz lida da função readSparse.
         //    - Cria uma variável que irá receber a string com nome do arquivo. 
         //    - Declara uma nova matriz que recebe uma matriz lida.
         case 2: {
            string arquivo;
            cout << "\nInsira o nome do arquivo que voce deseja ler: ";
            cin.ignore();
            getline(cin, arquivo);
            SparseMatrix* matrix = readSparseMatrix(arquivo);
            break;
         }
         // > Insere valores em todas as posições da matriz.
         //    - Caso em que não existe matriz para ser inserida.
         //       - Se não existir matriz, imprime um erro.
         //    - Pergunta qual matriz o usuario deseja preencher.
         //    - Verifica se matriz existe no vetor de matrizes.
         //       - se não existir no vetor de matrizes, imprime um erro.
         //    - Percorre todas as linhas e colunas e pede pra inserir o valor nessa posição.
         //    - Insere na matriz escolhida o valor na linha e coluna específica.
         case 3:{
            int it = 0;
            if(!mostrarMatrizesDisponiveis(vec_matrix)){
               cout << "\n* NAO EXISTE(M) MATRIZ(ES)! *\n";
               break;
            }

            std::cout << "> Qual matriz voce deseja preencher: ";
            cin >> it;
            it--;

            double v;
            if (it >= 0 && it < vec_matrix.size()) {
               for(int i = 1; i <= vec_matrix[it]->getLin(); i++){
                  for(int j = 1; j <= vec_matrix[it]->getCol(); j++){
                     std::cout << "Digite o valor da posicao (" + to_string(i) + ", " + to_string(j) + "): ";
                     cin >> v;
                     vec_matrix[it]->insert(i, j, v);
                  }
               }

               cout << "\n --- Matriz preenchida com sucesso --- \n";
            } else {
               cout << "\n* MATRIZ INVALIDA OU INEXISTENTE *\n";
            }
            break;
         }
         // > Insere ou altera o valor de uma posicao especifica na matriz.
         //    - Caso em que não existe matriz para ser inserida.
         //       - Se não existir matriz, imprime um erro.
         //    - Variável é subtraída em 1 para entrar no padrão de indice do vetor.
         //    - Verifica se a matriz existe no vetor de matrizes.
         //    - Insere o valor na posição específica.
         case 4: {
            int it = 0;
            int lin, col;
            double value;
            if(!mostrarMatrizesDisponiveis(vec_matrix)){
               cout << "\n* NAO EXISTE(M) MATRIZ(ES)! *\n";
               break;
            }

            std::cout << "> Informe em qual matriz voce deseja inserir um valor: ";
            cin >> it;
            it--;

            // Verifica se a matriz existe no vec_matrix
            if (it >= 0 && it < vec_matrix.size()) {
               std::cout << "\nDigite a linha que voce ira inserir: ";
               cin >> lin;
               std::cout << "Digite a coluna que voce ira inserir: ";
               std::cin >> col;
               std::cout << "Digite o valor que voce quer inserir na sua matriz: ";
               std::cin >> value;
               vec_matrix[it]->insert(lin, col, value);
               std::cout << "\n--- Elemento inserido com sucesso na matriz! ---\n";
            } else {
               std::cout << "* MATRIZ INVALIDA OU INEXISTENTE *\n";
            }
            break;
         }
         // > Impressão de matrizes.
         //    - Caso em que não existe matriz a ser impressa.
         //       - Se não existir matriz, imprime um erro.
         //    - Se escolher imprimir somente uma
         //       - Verifica se existe matriz a ser impressa.
         //       - Verifica se a escolha existe no vetor de matrizes.
         //    - Apos as verificações chama a função print pra matriz escolhida.
         //    - Verifica se a opção escolhida é válida
         //       - Se não pede para escolher novamente
         case 5: {
            int x;
            do {
               cout << "\n> Voce deseja imprimir somente uma matriz ou todas?\n";
               cout << "1. Imprima somente uma.\n";
               cout << "2. Imprima todas as matrizes disponiveis.\n";
               cout << "3. Voltar para o menu.\n";
               cout << "> Selecione uma opcao: ";
               cin >> x;
               if(x < 1 || x > 3){
                  cout << "\n* OPCAO INVALIDA, TENTE NOVAMENTE *\n";
               }
            } while(x < 1 || x > 3);

            if(x == 1) {

               if(!mostrarMatrizesDisponiveis(vec_matrix)){
                  cout << "\n* NAO EXISTE(M) MATRIZ(ES) A SER(EM) IMPRESSA(S)! *\n";
                  break;
               }

               int escolha;
               cout << "Qual matriz voce deseja imprimir? (escolha por ordem de criacao)\n";
               cout << "Matriz: ";
               cin >> escolha;

               if(escolha >= 0 && escolha <= vec_matrix.size()) {
                  // Escolha é diminuida em 1 para entrar nos padroes de indice do vector.
                  escolha--; 
                  std::cout << "\n";
                  vec_matrix[escolha]->print();
               } else {
                  std::cout << "* MATRIZ INVALIDA OU INEXISTENTE *\n";
               }
               break;
            } else if(x == 2) { // caso em que deseja imprimir todas as matrizes.
               if(!mostrarMatrizesDisponiveis(vec_matrix)){
                  cout << "\n* NAO EXISTE(M) MATRIZ(ES) A SER(EM) IMPRESSA(S)! *\n";
                  break;
               }
               std::cout << "\n";
               for (auto &&matrix : vec_matrix) { // Chama a função print para cada matriz contida no vetor.
                  matrix->print();
                  std::cout << "\n";
               }
               break;
            } else 
               break;
         }
         // > Informa ao usuário as matrizes disponíveis caso haja, solicita a escolha de duas
         //   matrizes para serem somadas (as duas devem ter o mesmo numero de linhas e colunas)
         //   - Se não houverem matrizes, imprime um erro
         //   - Se a matriz informada não existir, exibe as disponiveis e solicita novamente uma existente
         //   - Uma matriz pode ser somada com ela mesma
         // > Caso o usuário queira, salva matriz com o resultado da soma como uma nova matriz
         case 6: {

            if(!mostrarMatrizesDisponiveis(vec_matrix)){
               cout << "\n* NAO EXISTE(M) MATRIZ(ES) A SEREM SOMADAS! *\n";
               break;
            }

            bool invalido = true;
            int indexM1, indexM2;
            std::cout << "\n--- Escolha as matrizes que deseja somar ---\n";
            while(invalido){
               std::cout << "Matriz 01: ";
               cin >> indexM1;
               indexM1--;
               if(indexM1 < 0 || indexM1 >= vec_matrix.size()){
                  cout << "\n* ERRO, TENTE UMA MATRIZ EXISTENTE:";
                  mostrarMatrizesDisponiveis(vec_matrix);
               } else {
                  invalido = false;
               }
            }

            invalido = true;
            while(invalido){
               std::cout << "\nMatriz 02: ";
               std::cin >> indexM2;
               indexM2--;
               if(indexM2 < 0 || indexM2 >= vec_matrix.size()){
                  cout << "\n* ERRO, TENTE UMA MATRIZ EXISTENTE:";
                  mostrarMatrizesDisponiveis(vec_matrix);
               } else {
                  invalido = false;
               }
            }

            SparseMatrix* matrizSomada = sum(vec_matrix[indexM1], vec_matrix[indexM2]);
            if(matrizSomada != nullptr) {
               std::cout << "\n";
               matrizSomada->print();
            }

            int save;
            std::cout << "\n> Deseja salvar o resultado da soma como uma nova matriz ?";
            std::cout << "\n1. Sim";
            std::cout << "\n2. Nao\n";
            cin >> save;

            if(save == 1){
               vec_matrix.push_back(matrizSomada);
            }
            break;
         }
         
         // > Informa ao usuário as matrizes disponíveis caso haja, solicita a escolha de duas
         //   matrizes para serem multiplicadas (o numero de colunas da primeira matriz deve ser
         //   igual ao numero de linhas da segunda matriz)
         //   - Se houver apenas uma matriz, imprime um erro
         //   - Se não houverem matrizes, imprime um erro
         //   - Se a matriz informada não existir, exibe as disponiveis e solicita novamente uma existente
         // > Caso o usuário queira, salva a matriz produto como uma nova matriz
         case 7: {

            if(!mostrarMatrizesDisponiveis(vec_matrix)){
               cout << "\n* NAO EXISTE(M) MATRIZ(ES) A SEREM MULTIPLICADAS! *\n";
               break;
            }

            if(vec_matrix.size() == 1){
               cout << "\n* VOCE PRECISA DE PELO MENOS 2 MATRIZES DISPONIVEIS *\n";
               break;
            }

            bool invalido = true;
            int indexM1, indexM2;
            std::cout << "\n--- Escolha as matrizes que deseja multiplicar ---\n";
            while(invalido){
               std::cout << "Matriz 01: ";
               cin >> indexM1;
               indexM1--;
               if(indexM1 < 0 || indexM1 >= vec_matrix.size()){
                  cout << "\n* ERRO, TENTE UMA MATRIZ EXISTENTE:";
                  mostrarMatrizesDisponiveis(vec_matrix);
               } else {
                  invalido = false;
               }
            }

            invalido = true;
            while(invalido){
               std::cout << "\nMatriz 02: ";
               std::cin >> indexM2;
               indexM2--;
               if(indexM2 < 0 || indexM2 >= vec_matrix.size()){
                  cout << "\n* ERRO, TENTE UMA MATRIZ EXISTENTE:";
                  mostrarMatrizesDisponiveis(vec_matrix);
               } else {
                  invalido = false;
               }
            }

            SparseMatrix* matrizProduto = multiply(vec_matrix[indexM1], vec_matrix[indexM2]);
            if(matrizProduto != nullptr) {
               std::cout << "Matriz Produto: \n";
               matrizProduto->print();
            }

            int save;
            std::cout << "\n> Deseja salvar o resultado da multiplicacao como uma nova matriz ?";
            std::cout << "\n1. Sim";
            std::cout << "\n2. Nao\n";
            cin >> save;

            if(save == 1){
               vec_matrix.push_back(matrizProduto);
            }

            break;
         }
         // > Apaga o valor de uma posição específica da matriz.
         //    - Caso em que não existe matriz.
         //       - Se não existir matriz, imprime um erro.
         //    - Verifica se a matriz existe no vetor de matrizes.
         //       - Se não existir, imprime um erro.
         //    - Insere 0 na na linha e coluna escolhida pelo usuario. 
         case 8: {
            int it = 0;
            int lin, col;
            double value;
            if(!mostrarMatrizesDisponiveis(vec_matrix)){
               cout << "\n* NAO EXISTE(M) MATRIZ(ES)! *\n";
               break;
            }

            std::cout << "> Informe de qual matriz voce quer apagar uma posicao: ";
            cin >> it;
            it--;

            // Verificar se a matriz existe no vec_matrix
            if (it >= 0 && it < vec_matrix.size()) {
               std::cout << "\nInforme a linha do valor a ser apagado: ";
               cin >> lin;
               std::cout << "\nInforme a coluna do valor a ser apagado: ";
               cin >> col;
               vec_matrix[it]->insert(lin, col, 0);
               std::cout << "\n--- Valor apagado com sucesso ---\n";
            } else {
               std::cout << "\n* MATRIZ INEXISTENTE *\n";
            }
            break;
         }
         // > Ver todas as matrizes existentes.
         //    - Caso em que não existe matriz.
         //       - Se não existir matriz, imprime um erro.
         //    - Se existir, a função retorna as matrizes disponíveis.
         case 9: {
            if(!mostrarMatrizesDisponiveis(vec_matrix)){
               cout << "\n* NAO EXISTE(M) NENHUMA MATRIZ(ES)! *\n";
               break;
            }
            break;
         }
         // > Sair.
         //    - Chama o destrutor em cada uma das matrizes contidas no vetor de matriz.
         //    - Variavel sair recebe 1.
         //    - While termina quando sair != 0.
         //    - Fim do código.
         case 10: {
            for(int i = 0; i < vec_matrix.size(); i++){
               vec_matrix[i]->~SparseMatrix();
            }
            sair = 1;
            break;
         }
      }
   }
}

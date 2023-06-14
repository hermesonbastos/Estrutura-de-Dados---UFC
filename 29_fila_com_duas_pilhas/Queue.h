#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

using namespace std;

class Queue {

    private:

    stack <int> deposit;
    stack <int> shelf;

    public:

    // Construtor da classe Queue, inicializa uma nova fila
    Queue() = default;

    // Função que enfileira um elemento x no final da fila
    void toQueue(int x);

    // Função que retorna o primeiro da fila
    int getFirst();

    // Função que remove o primeiro da fila
    void removeFirst();

    void transferToShelf(){
        if(this->shelf.empty()){
            while(!(this->deposit.empty())){
                shelf.push(deposit.top());
                deposit.pop();
            }
        }
    }
};

#endif

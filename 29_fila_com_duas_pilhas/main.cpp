#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

int main() {
    Queue *fila = new Queue();
    int op = 0;
    cin >> op;

    while(op != 0){
        int func;
        cin >> func;

        switch(func){
            case 1: {
                int value;
                cin >> value;
                fila->toQueue(value);
                op--;
                break;
            }
            
            case 2: {
                fila->removeFirst();
                op--;
                break;
            }

            case 3: {
                cout << fila->getFirst() << endl;
                op--;
                break;
            }
        }
    }
}
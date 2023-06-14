#include <stack>
#include "Queue.h"
using namespace std;

void Queue::toQueue(int x){
    deposit.push(x);
}

int Queue::getFirst(){
    Queue::transferToShelf();
    return shelf.top();
}

void Queue::removeFirst(){
    Queue::transferToShelf();
    shelf.pop();
}
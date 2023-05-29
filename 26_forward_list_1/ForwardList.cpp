/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 1
 ***********************************************************/

Item& ForwardList::front() {
    // fazer
    return this->m_head->next->value;
}

const Item& ForwardList::front() const {
    // fazer
    return this->m_head->next->value;
}
    
void ForwardList::push_front(const Item& val) {
    // fazer
    this->m_head->next = new Node(val, this->m_head->next);
    this->m_size = this->m_size++;
}

void ForwardList::pop_front() {
    // fazer
    // if(this->m_head->next == nullptr){ // verifica se a lista não está vazia (se o nó pra qual o m_head aponta não é nulo)
    //     return;
    // }

    // Node *aux = this->m_head->next; // cria um nó auxiliar para guardar o endereço do primeiro nó que vai ser deletado
    // delete this->m_head->next; // deleta o primeiro nó
    // this->m_head->next = aux; // 
    if (m_head->next == nullptr) {
        return;  // If the list is empty, do nothing
    }
    
    Node* aux = m_head->next;
    m_head->next = aux->next;
    delete aux;
    m_size--;
}

Item& ForwardList::back() {
    // fazer
    Node* aux = this->m_head->next; // cria um nó auxiliar que vai apontar para o primeiro da lista
    while(aux->next != nullptr){ // enquanto o próximo nó não for nulo (não for o último) ele atribui o próximo nó ao auxiliar
        aux = aux->next;
    }
    
    return aux->value;
}

const Item& ForwardList::back() const {
    // fazer
    Node* aux = this->m_head->next; // cria um nó auxiliar que vai apontar para o primeiro da lista
    while(aux->next != nullptr){ // enquanto o próximo nó não for nulo (não for o último) ele atribui o próximo nó ao auxiliar
        aux = aux->next;
    }
    
    return aux->value;
}
    
void ForwardList::push_back(const Item& val) {
    // fazer
    Node* aux = this->m_head; // cria um nó auxiliar que vai apontar para o primeiro da lista
    while(aux->next != nullptr){ // enquanto o próximo nó não for nulo (não for o último) ele atribui o próximo nó ao auxiliar
        aux = aux->next;
    }
    aux->next = new Node(val, nullptr); // cria um novo nó no enderenço que era nulo, com o valor passado e apontando para nulo (novo último)
    this->m_size++; // incrementa o tamanho global da lista
}

void ForwardList::pop_back() {
    // fazer
    if (m_head->next == nullptr) { // verifica se a lista não está vazia
        return;
    }

    Node* aux = m_head; // cria um ponteiro auxiliar que aponta para o cabeçalho
    while (aux->next->next != nullptr) { // percorre até o penúltimo item da lista atribuindo o elemento para aux
        aux = aux->next;
    }

    delete aux->next; // deleta o último
    aux->next = nullptr;
    m_size--; // decrementa o tamanho global da lista
}
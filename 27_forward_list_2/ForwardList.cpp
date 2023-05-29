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
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) {
    // fazer
    if (!lst.empty()) {
        Node* lastNode = m_head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;  // Encontra o último nó da lista atual
        }

        lastNode->next = lst.m_head->next;  // Justa a lst com o final da lista
        lst.m_head->next = nullptr;  // Define o próximo nó da lista lst como nulo

        m_size += lst.m_size;
        lst.m_size = 0;
    }
}

void ForwardList::remove(const Item& val) {
    // fazer
    Node* atual = m_head->next; // cria um nó auxiliar atual para apontar para o primeiro nó da lista
    Node* anterior = m_head; // cria um nó auxiliar anterior para apontar para o antecessor do atual

    while (atual != nullptr) { // se o nó atual não for vazio, execute
        if (atual->value == val) { // se o valor do nó atual for igual ao valor passado ára a função, execute
            anterior->next = atual->next; // o nó anterior aponta para o próximo ao atual (pula 1)
            Node* temp = atual; // um nó temporário é criado como cópia do atual
            atual = atual->next; // o nó atual aponta para o próximo
            delete temp; // usamos temp que guardava o atual para podermos deletar da memória
            m_size--; // decrementamos globalmente o tamanho da lista

        } else { // se o valor atual não for igual ao passado por parâmetro
            anterior = atual; // o anterior (inicialmente m_head), aponta para o atual
            atual = atual->next; // e o atual aponta para o próximo, permitindo que percorramos a lista
        }
    }
}

ForwardList* ForwardList::clone() {
    // fazer
    ForwardList* newList = new ForwardList();  // Cria uma nova lista vazia

    Node* current = m_head->next;
    Node* newLast = newList->m_head;

    while (current != nullptr) {
        newLast->next = new Node(current->value, nullptr);  // Cria um novo nó com o valor atual e próximo como nullptr
        newLast = newLast->next;  // Atualiza o ponteiro para o último nó criado
        current = current->next;  // Avança para o próximo nó na lista original
    }

    newList->m_size = m_size;  // Define o tamanho da nova lista como o mesmo tamanho da lista original

    return newList;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    // fazer
    if (!vec.empty()) { // se o vetor não estiver vazio, execute
        Node* lastNode = m_head; // cria um nó apontando para m_head da lista atual
        while (lastNode->next != nullptr) { // enquanto a lista não estiver vazia
            lastNode = lastNode->next; // lastNode aponta para o último elemento da lista
        }
        for (const auto& item : vec) { // itera sobre os itens do vetor
            lastNode->next = new Node(item, nullptr); // cria um novo nó no fim da lista, armazenando o valor do vetor iterado
            lastNode = lastNode->next; // o último passa a apontar para o próximo que foi criado (que aponta para null)
            m_size++; // incrementa globalmente o tamanho atual da lista
        }
    }
}

void ForwardList::swap(ForwardList& lst) {
    // fazer
    Node* temp= m_head; // nó temporário que aponta para o m_head atual
    m_head = lst.m_head; // m_head atual aponta para o m_head da lst
    lst.m_head = temp; // m_head da lst aponta para o m_head da atual

    // troca o tamanho global das listas
    int temps = m_size; 
    m_size = lst.m_size;
    lst.m_size = temps;
}

bool ForwardList::equals(const ForwardList& lst) const {
    // fazer
    if (m_size != lst.m_size) {
        return false;  // As listas têm tamanhos diferentes, então não são iguais
    }

    Node* currentThis = m_head->next; // currentThis aponta para o primeiro elemento da lista atual
    Node* currentLst = lst.m_head->next; // currentLst aponta para o primeiro elemento da lista lst

    while (currentThis != nullptr && currentLst != nullptr) { // se nenhuma das duas listas tiverem chegado ao fim, execute
        if (currentThis->value != currentLst->value) {  // verifica se o valor atual nas duas listas são iguais
            return false;  // Os valores dos nós atuais são diferentes, então as listas não são iguais
        }

        // atualiza os ponteiros para iterar sobre as suas listas
        currentThis = currentThis->next;
        currentLst = currentLst->next;
    }
    return true; // se percorrer tudo sem nenhum problema é porque as listas são iguais, logo retorna true
}

void ForwardList::reverse() {
    // fazer
    if (!(m_head->next == nullptr || m_head->next->next == nullptr)) { // não faz nada se a lista estiver vazia
        Node *anterior = nullptr;
        Node *atual = m_head->next;
        Node *proximo = nullptr;

        while (atual != nullptr) {
            proximo = atual->next;  // Salva o próximo nó
            atual->next = anterior;  // Inverte o ponteiro next do nó atual para o nó anterior

            anterior = atual;        // Avança para o próximo nó
            atual = proximo;
        }

        m_head->next = anterior;  // Atualiza o ponteiro m_head->next para apontar para o último nó 
    }
}

Item& ForwardList::get(int index) {
    // fazer
    // Verifica se o índice está fora do intervalo válido
    if (index < 0 || index >= m_size) {
        throw std::range_error("index out of range"); // Lança uma exceção std::range_error com a mensagem de erro "index out of range"
    }

    Node *atual = m_head->next; // Ponteiro para o nó atual, começando no primeiro nó após o nó cabeça

    // Percorre a lista encadeada até o nó na posição 'index'
    for (int i = 0; i < index; i++) {
        atual = atual->next; // Move para o próximo nó
    }

    return atual->value; // Retorna uma referência para o valor do nó encontrado
}

const Item& ForwardList::get(int index) const {
    // fazer
    if (index < 0 || index >= m_size) {
        throw std::range_error("index out of range"); // Lança uma exceção std::range_error com a mensagem de erro "index out of range"
    }

    Node *atual = m_head->next; // Ponteiro para o nó atual, começando no primeiro nó após o nó cabeça

    // Percorre a lista encadeada até o nó na posição 'index'
    for (int i = 0; i < index; i++) {
        atual = atual->next; // Move para o próximo nó
    }

    return atual->value; // Retorna uma referência para o valor do nó encontrado
}

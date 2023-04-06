# include <cstdlib>
# include "No.hpp"

using namespace std;

template <typename type>
void Node<type>::alloc_space() {
    this->next_node = (Node*) malloc(sizeof(Node));
}


template <typename type>
void Node<type>::nullify_node(){
    this->value = 0;
    this->next_node = nullptr;
}


template <typename type>
Node<type>::Node(void) {
    this->alloc_space();
    this->nullify_node();
}

template <typename type>
Node<type>::Node(type value) {
    this->alloc_space();
    this->value = value;
    this->next_node = nullptr;
}


template <typename type>
type Node<type>::getValue(void) {
    return this->value;
}

template <typename type>
Node<type>* Node<type>::getNextNode(void) {
    return this->next_node;
}

template <typename type>
void Node<type>::setValue(type new_value) {
    this->value = new_value;
}

template <typename type>
void Node<type>::setNextNode(Node<type>* next_node) {
    this->next_node = next_node;
}


template <typename type>
Node<type>::Node(type value, Node* next_node) {
    this->alloc_space();
    this->value = value;
    this->setNextNode(next_node);
}


template <typename type>
Node<type>* Node<type>::createNextNode(type value) {
    Node<type> *new_no = (Node<type>*) malloc(sizeof(Node<type>));
    *new_no = Node<type>(value);
    this->setNextNode(new_no);
    return new_no;
}
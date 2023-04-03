# include <cstdlib>

using namespace std;

template <typename type>
void Node<type>::alloc_space() {
    this->next_node = (Node*) malloc(sizeof(Node));
    this->past_node = (Node*) malloc(sizeof(Node));
}

template <typename type>
void Node<type>::nullify_node(){
    this->value = 0;
    this->next_node = nullptr;
    this->past_node = nullptr;
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
    this->past_node = nullptr;
}

template <typename type>
Node<type>::Node(type value, Node* next_node) {
    this->alloc_space();
    this->value = value;
    this->next_node = next_node;
    this->past_node = nullptr;
}

template <typename type>
Node<type>::Node(type value, Node* next_node, Node* past_node) {
    this->alloc_space();
    this->value = value;
    this->next_node = next_node;
    this->past_node = past_node;
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
Node<type>* Node<type>::getPastNode(void) {
    return this->past_node;
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
void Node<type>::setPastNode(Node<type>* past_node) {
    this->past_node = past_node;
}

template <typename type>
void Node<type>::delete_node(void) {
    type* valueptr = &(this->value);
    free(this->next_node);
    free(this->past_node);
}

template <typename type>
Node<type>* Node<type>::getThisNode(void) {
    return &this;
}


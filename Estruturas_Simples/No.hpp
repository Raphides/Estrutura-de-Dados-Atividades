template <typename type>
class Node
{
private:
    type value;
    Node *next_node, *past_node;
    void alloc_space();
public:
    Node(type value, Node* next_node, Node* past_node);
    Node(type value, Node* next_node);
    Node(type value);
    Node(void);
    void nullify_node(void);
    void delete_node(void);
    type getValue(void);
    void setValue(type new_value);
    Node* getNextNode(void);
    void setNextNode(Node* next_node);
    Node* getPastNode(void);
    void setPastNode(Node* past_node);
};

template <typename type>
void Node<type>::alloc_space() {
    this->next_node = (Node*) malloc(sizeof(Node));
    this->past_node = (Node*) malloc(sizeof(Node));
}

template <typename type>
void Node<type>::nullify_node(){
    this->value = NULL;
    *(this->next_node) = NULL;
    *(this->past_node) = NULL;
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
    *(this->next_node) = NULL;
    *(this->past_node) = NULL;
}

template <typename type>
Node<type>::Node(type value, Node* next_node) {
    this->alloc_space();
    *(this->value) = value;
    this->next_node = next_node;
    *(this->past_node) = NULL;
}

template <typename type>
Node<type>::Node(type value, Node* next_node, Node* past_node) {
    this->alloc_space();
    *(this->value) = value;
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
    this->value = NULL;
    free(this->next_node);
    free(this->past_node);
}
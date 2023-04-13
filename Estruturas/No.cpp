# include <cstdlib>

template <typename type>
class Node
{
protected:
    type value;
    Node *next_node;
    void alloc_space();
public:
    
    Node(type value, Node* next_node);
    Node(type value);
    Node(void);

    void nullify_node(void);
    
    type getValue(void);
    void setValue(type new_value);
    
    Node* getNextNode(void);
    void setNextNode(Node* next_node);

    Node* createNextNode(type value);
};

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


// Nó duplo

template <typename type>
class Double_Node: public Node<type> {
protected:
    Double_Node *past_node;
    void alloc_space();
public:
    void nullify_node(void);

    Double_Node(type value, Double_Node<type>* next_node, Double_Node<type>* past_node);
    Double_Node(type value, Double_Node<type>* next_node);
    Double_Node(type value);
    Double_Node(void);
    
    void setNextNode(Double_Node<type>* next_node);
    
    Double_Node* getPastNode(void);
    void setPastNode(Double_Node<type>* past_node);
    
    Double_Node* createNextNode(type value);
    Double_Node* createPastNode(type value);
    
};

// Double Node definitions

template <typename type>
void Double_Node<type>::alloc_space() {
    this->next_node = (Double_Node<type>*) malloc(sizeof(Double_Node<type>));
    this->past_node = (Double_Node<type>*) malloc(sizeof(Double_Node<type>));
}

template <typename type>
void Double_Node<type>::nullify_node(){
    this->past_node = nullptr;
    Node<type>::nullify_node();
}

template <typename type>
Double_Node<type>::Double_Node(type value) {
    this->alloc_space();
    this->value = value;
    this->next_node = nullptr;
    this->past_node = nullptr;
}


template <typename type>
Double_Node<type>* Double_Node<type>::getPastNode(void) {
    return this->past_node;
}

template <typename type>
Double_Node<type>::Double_Node(type value, Double_Node<type>* next_node, Double_Node<type>* past_node) {
    this->alloc_space();
    this->value = value;
    this->setNextNode(next_node);
    this->setPastNode(past_node);
}

template <typename type>
void Double_Node<type>::setNextNode(Double_Node<type>* next_node) {
    this->next_node = next_node;
    if (next_node->getPastNode() != this)
        next_node->setPastNode(this);
}

template <typename type>
void Double_Node<type>::setPastNode(Double_Node<type>* past_node) {
    this->past_node = past_node;
    if (this != past_node->getNextNode())
        past_node->setNextNode(this);    
}

template <typename type>
Double_Node<type>* Double_Node<type>::createNextNode(type value) {
    Double_Node<type> *new_no = (Double_Node<type>*) malloc(sizeof(Double_Node<type>));
    *new_no = Double_Node<type>(value);
    this->setNextNode(new_no);
    return new_no;
}

template <typename type>
Double_Node<type>* Double_Node<type>::createPastNode(type value) {
    Double_Node<type> *new_no = (Double_Node<type>*) malloc(sizeof(Double_Node<type>));
    *new_no = Double_Node<type>(value);
    this->setPastNode(new_no);
    return new_no;
}
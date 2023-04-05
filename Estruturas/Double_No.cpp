# include <cstdlib>
using namespace std;

# include "Double_No.hpp"

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
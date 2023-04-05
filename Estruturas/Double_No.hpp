# include "No.cpp"

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
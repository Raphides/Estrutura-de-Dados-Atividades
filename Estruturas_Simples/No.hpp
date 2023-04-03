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
    ~Node();

    void nullify_node(void);
    
    type getValue(void);
    void setValue(type new_value);
    
    Node* getNextNode(void);
    void setNextNode(Node* next_node);
    
    Node* getPastNode(void);
    void setPastNode(Node* past_node);

    Node* createNextNode(type value);
    Node* createPastNode(type value);
};

# include "No.cpp"
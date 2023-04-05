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
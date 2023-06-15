
template <typename type>
class Node
{
private:
    
public:
    type value;
    Node *next;
    Node(type value);
    ~Node();

};

Node::Node(/* args */)
{
}

Node::~Node()
{
}

template <typename type>
class Linked_List
{
private:
    
public:
    Linked_List(/* args */);
    
    int append(type value);

    int add(unsigned int index, type value);

    int pop();

    int exclude(unsigned int index);
    
    ~Linked_List();
};

Linked_List::Linked_List(/* args */)
{
}

Linked_List::~Linked_List()
{
}


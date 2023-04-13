# include "No.cpp"

template <typename type>
class Base_List
{
protected:
    int size;
    
public:
    Node<type> *startNode;
    Node<type> *lastNode;
    
    virtual Base_List(Node<type> startNode);
    virtual Base_List(type value);
    virtual Base_List(void);

    virtual bool check_sanity();

    virtual int getSize();
    virtual Node<type>* getNode(int target_index);
    virtual int findNode(type target_value);
    virtual int findNode(Node<type>* target_Node);

    virtual void add(type value);
    virtual void add(Node<type> Node)
};

template <typename type>
Base_List<type>::Base_List(/* args */)
{
}

template <typename type>
Base_List<type>::Base_List()
{
}


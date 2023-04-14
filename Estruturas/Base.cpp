# include "No.cpp"
# include "Exceptions.cpp"

template <typename type>
class Base_List
{
protected:
    int size;
    Node<type> **getAdressSequence(bool fromEnd=true);
    
public:
    Node<type> *startNode;
    Node<type> *lastNode;
    
    virtual Base_List(Node<type>* startNode);
    virtual Base_List(type value);
    virtual Base_List(void);

    bool isInsane();

    int getSize();
    virtual Node<type>* getNode(int target_index);
    virtual int findNode(type target_value);
    virtual int findNode(Node<type>* target_Node);

    virtual void append(type value);
    virtual void append(Node<type>* Node);

    virtual void remove();


};

template <typename type>
Node<type>** Base_List<type>::getAdressSequence(bool fromEnd=false)
{
    if (this->size == 0)
    {
        return nullptr;
    }
    else
    {
        Node<type>** result = (Node<type>**) calloc(this->size, sizeof(Node<type>*));
        Node<type> *actualNode;
      
        
        try {
            if (!fromEnd){
                actualNode = this->startNode;
                for (int i = 0; i < this->size; i++)
                {
                    result[i] = actualNode;
                    actualNode = actualNode->getNextNode();
                }
            }
            else {
                actualNode = this->lastNode;
                for (int i = this->size - 1; i >= 0; i--)
                {
                    result[i] = actualNode;
                    actualNode = actualNode->get();
                }
            }
            
            return result;
        }
        catch (exception err){
            return nullptr;
        }
    }
    
}


template <typename type>
bool Base_List<type>::isInsane(void)
{
    
}

template <typename type>
Base_List<type>::Base_List(/* args */)
{
}


template <typename type>
Base_List<type>::Base_List(/* args */)
{
}

template <typename type>
Base_List<type>::Base_List()
{
}


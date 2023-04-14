# include "No.cpp"
# include "Exceptions.cpp"

template <typename type>
class Base_List
{
protected:
    int size;
    virtual int isAscending()=0;
    
public:
    int getSize();

    type getValue(int target_index)=0;
    virtual int findValue(type target_value)=0;

    virtual void add(type value)=0;
    virtual void remove()=0;

    /**
     * @returns 0 if the it is not ordered.
     * If it is ordered, returns 1 when element at index 0 is the smaller,
     * else it returns -1. 
    */
    virtual int checkOrder()=0;
    virtual void bubbleSort()=0;
    virtual void mergeSort()=0;
    virtual void selectionSort()=0;
    virtual void quickSort()=0;
    virtual type* toFixedVector()=0;
    virtual type* toAllocatedVector()=0;
};
template <typename type>
class Base_Simple_Linked_List: public Base_List
{
protected:
    Node<type> *startNode;
    Node<type> *lastNode;
    int isAscending();
public:
    type* toFixedVector();
    type* toAllocatedVector();
};

template <typename type>
class Base_Doubble_Linked_List: public Base_List
{
protected:
    Double_Node<type> *startNode;
    Double_Node<type> *lastNode;
    int isAscending();
public:
    type* toFixedVector();
    type* toAllocatedVector();
};


template <typename type>
int Base_List<type>::getSize(){
    return this->size;
};

template <typename type>
type* Base_Simple_Linked_List<type>::toFixedVector(){
    type result[this->size];
    Node<type>* actualNode = this->startNode;
    for (int j = 0; j < this->size; j++)
    {
        result = actualNode->getValue();
        actualNode = actualNode->getNextNode();
    }
    return result;
};

template <typename type>
type* Base_Simple_Linked_List<type>::toAllocatedVector(){
    type* result = (type*) calloc(this->size, sizeof(type));
    Node<type>* actualNode = this->startNode;
    for (int j = 0; j < this->size; j++)
    {
        result = actualNode->getValue();
        actualNode = actualNode->getNextNode();
    }
    return result;
}

template <typename type>
type* Base_Doubble_Linked_List<type>::toFixedVector(){
    type result[this->size];
    Node<type>* actualNode = this->startNode;
    for (int j = 0; j < this->size; j++)
    {
        result = actualNode->getValue();
        actualNode = actualNode->getNextNode();
    }
    return result;
};

template <typename type>
type* Base_Doubble_Linked_List<type>::toAllocatedVector(){
    type* result = (type*) calloc(this->size, sizeof(type));
    Node<type>* actualNode = this->startNode;
    for (int j = 0; j < this->size; j++)
    {
        result = actualNode->getValue();
        actualNode = actualNode->getNextNode();
    }
    return result;
};


template <typename type>
int Base_Simple_Linked_List<type>::isAscending(){
    type value1;
    try{
        if ((this->startNode->getValue()) > (this->startNode->getValue()))
        {
            
        }
        else if()
        else
        {
            /* code */
        }
    }
    catch (exception err){
        throw TypeError("type used in the list is not comperable, so you can not check its order.");
    }



};

template <typename type>
int Base_Doubble_Linked_List<type>::isAscending(){

};
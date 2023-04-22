# include "Double_No.cpp"

# include <cstdlib>
# include <cstdio>

int main(int argc, char const *argv[])
{
    Double_Node<int> *no1 = (Double_Node<int>*) malloc(sizeof(Double_Node<int>));
    *no1 = Double_Node<int>(0);
    no1->createPastNode(2);
    printf("%d %d\n", no1->getValue(), no1->getPastNode()->getValue());
    no1->createNextNode(-2);
    printf("%d %d\n", no1->getValue(), no1->getNextNode()->getValue());
    return 0;
}

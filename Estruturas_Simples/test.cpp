# include "No.hpp"
# include<cstdio>

int main(int argc, char const *argv[])
{
    Node<int> no1 = Node<int>(2);
    Node<int> no2 = Node<int>(3, nullptr);
    Node<int> no3 = Node<int>();
    no1.setNextNode(&no2);
    no1.getNextNode()->setNextNode(&no3);
    printf("%d %d %d\n", no1.getValue(), no1.getNextNode()->getValue(), no1.getNextNode()->getNextNode()->getValue());
    return 0;
}
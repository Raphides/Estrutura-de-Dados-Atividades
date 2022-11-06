void swap(int *a, int *b);

void swap(int *a, int *b) {
    // a = &e and b = &17
    int temporary = *a;
    // when we use * with a pointer already declared, we are refering to its adress content
    // a = %e and 'content a' = temporary = content of e = 13
    *a = *b;
    // content of 'a' stored adress(content of e) is now content of 'b' stored adress (content of f).
    // before a --> e = 13
    // now a --> e = 17
    *b = temporary;
    // *b refers to f
    // f = temporary = 13 
}
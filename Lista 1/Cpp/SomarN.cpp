// Programa que soma n números

# include <iostream>

using namespace std;

int numero, linhas, soma;

int main(int argc, char const *argv[])
{
    soma = 0;
    cin >> linhas;
    for (int i = 0; i < linhas; i++)
    {
        cin >> numero;
        soma += numero;
    }
    cout << soma << endl;
    
    return 0;
}

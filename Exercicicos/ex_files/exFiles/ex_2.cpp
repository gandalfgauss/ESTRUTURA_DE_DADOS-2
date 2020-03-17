#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct
{
    char sexo;
    int idade;
    char fumante;

} Entrevistado;

int main()
{
    Entrevistado entrevista;
    FILE *arq;
    int qntPessoa = 0;
    int qntMulheres = 0, qntMulheres40 = 0;
    int qntHomens = 0, qntHomens40 = 0;
    int qntFumantes = 0;
    char opcao, fumante;

    if ((arq = fopen("resposta.bin", "w+b")) == NULL)
    {
        cout << "ERRO NA ABERTURA DO ARQUIVO" << endl;
        exit(1);
    }

    do
    {
        cout << "SEXO(M/F): " << endl;
        cin >> entrevista.sexo;
        cout << "IDADE: " << endl;
        cin >> entrevista.idade;
        cout << "FUMANTE (S/N): " << endl;
        cin >> entrevista.fumante;

        qntPessoa++;

        if (toupper(entrevista.fumante) == 'N')
        {
            if (toupper(entrevista.sexo) == 'M')
            {
                qntHomens++;
                if (entrevista.idade >= 40)
                    qntHomens40++;
            }
            else
            {
                qntMulheres++;
                if (entrevista.idade >= 40)
                    qntMulheres40++;
            }
        }
        else
        {
             if (toupper(entrevista.sexo) == 'M')
            {
                
                qntHomens++;
                if (entrevista.idade >= 40)
                    qntHomens40++;
            }
            else
            {
                qntMulheres++;
                if (entrevista.idade >= 40)
                    qntMulheres40++;
            }
        }
        

        cout << "Adiciona mais uma pessoa?(S/N)" << endl;
        cin >> opcao;
    } while (toupper(opcao) == 'S');
}
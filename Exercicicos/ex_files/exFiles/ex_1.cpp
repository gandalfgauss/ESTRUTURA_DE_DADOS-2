#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

typedef struct aluno
{
    string nome;
    int matricula[3];
    double n_1, n_2, n_3;
} Aluno;

int main()
{
    Aluno a;
    FILE *arq;
    double media;
    string nome;

    srand(time(NULL));

    if ((arq = fopen("aluno.bin", "w+b")) == NULL)
    {
        cout << "erro na abertura do aarquivo" << endl;
        exit(1);
    }

    for (int i = 0; i < 1; i++)
    {
        a.n_1 = (rand() % 11);
        a.n_2 = (rand() % 11);
        a.n_3 = (rand() % 11);
        cin >> nome;
        a.nome = nome;

        fwrite(&a, sizeof(a), 1, arq);
    }

    fseek(arq, 0, SEEK_SET);

    cout << endl;

    for (int i = 0; i < 1; i++)
    {
        fread(&a, sizeof(Aluno), 1, arq);

        media = (a.n_1 + a.n_2 + a.n_3) / 3;

        cout << "Nome: " << a.nome; 
        cout << "\nmedia: " << media << endl;
    }

    fclose(arq);

    return 0;
}
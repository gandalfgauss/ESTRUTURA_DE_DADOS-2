#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE *arq;
    int voto;
    int vote_1 = 0, vote_2 = 0, vote_3 = 0, vote_4 = 0, vote_5 = 0;
    int nulo = 0;
    int eleitor;
    char enter;

    if ((arq = fopen("votos.txt", "r")) == NULL)
    {
        cout << "Erro na abertura do arquivo" << endl;
        exit(1);
    }

    while (fscanf(arq, "%d %d %[\n]", &eleitor, &voto, &enter) != EOF)
    {
        if (voto == 0)
        {
            nulo++;
        }
        else
        {
            if (voto == 1)
                vote_1++;
            else if (voto == 2)
                vote_2++;
            else if (voto == 3)
                vote_3++;
            else if (voto == 4)
                vote_4++;
            else
                vote_5++;
        }
    }

    cout << "\nNULOS: " << nulo
         << "\nCandatato 1: " << vote_1
         << "\nCandatato 2: " << vote_2
         << "\nCandatato 3: " << vote_3
         << "\nCandatato 4: " << vote_4
         << "\nCandatato 5: " << vote_5 << endl;

    int vote_max = 0;
    int win = 0;

    for (int i = 0; i < 5; i++)
    {
        if (vote_1 > vote_max)
        {
            vote_max = vote_1;
            win = 1;
        }
        else if (vote_2 > vote_max)
        {
            vote_max = vote_2;
            win = 2;
        }
        else if (vote_3 > vote_max)
        {
            vote_max = vote_3;
            win = 3;
        }
        else if (vote_4 > vote_max)
        {
            vote_max = vote_4;
            win = 4;
        }
        else if (vote_5 > vote_max)
        {
            vote_max = vote_5;
            win = 5;
        }
    }

    cout << "-----------------------" << endl;
    cout << "O CANDIDATO: " << win
         << "\nE Obteve: " << vote_max << " votos" << endl;

    return 0;
}
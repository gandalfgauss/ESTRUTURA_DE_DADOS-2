#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    FILE *arq;
    int temp;
    int quant = 0;

    if ((arq = fopen("votos.txt", "w")) == NULL)
    {
        cout << "Erro na criação do arquivo" << endl;
        exit(1);
    }

    srand(time(NULL));

    do
    {
        temp = (rand() % 6);
        quant++;
        fprintf(arq, "%3d %d\n", quant, temp);

    } while (quant < 100);

    fclose(arq);
    return 0;
}
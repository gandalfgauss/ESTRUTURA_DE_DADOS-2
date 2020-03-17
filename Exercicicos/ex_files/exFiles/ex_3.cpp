#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    FILE *arq;
    double temp, temp_max, temp_mim;
    double media;
    double soma_temp = 0;
    int nro_dias = 0, dias_abaixo = 0, dias_acima = 0, dias;
    char enter;

    if (argc != 2)
    {
        cout << "formato: excultavel arquivo\n";
        exit(1);
    }

    if ((arq = fopen(argv[1], "r")) == NULL)
    {
        cout << "Erro na abartura do arquivo" << endl;
        exit(1);
    }

    while (fscanf(arq, "%d %lf %[\n]",
                  &dias, &temp, &enter) != EOF)
    {
        if (nro_dias == 0)
        {
            temp_max = temp;
            temp_mim = temp;
        }
        else
        {
            if (temp <= temp_mim)
                temp_mim = temp;
            else if (temp >= temp_max)
                temp_max = temp;
        }

        nro_dias++;
        soma_temp += temp;
    }

    media = soma_temp / nro_dias;
    /* 
    fclose(arq);

    if ((arq = fopen(argv[1], "r")) == NULL)
    {
        cout << "Erro na abartura do arquivo" << endl;
        exit(1);
    } */

    fseek(arq, 0, SEEK_SET);

    while (fscanf(arq, "%d %lf %[\n]",
                  &dias, &temp, &enter) != EOF)
    {
        if (temp <= media)
            dias_abaixo++;
        else if (temp > media)
            dias_acima++;
    }

    cout << "numero de dias: " << dias << endl;
    cout << "Media: " << media << "C" << endl;
    cout << "Dias abaixo da media: " << dias_abaixo << " dias" << endl;
    cout << "Dias acima da media: " << dias_acima << " dias" << endl;
    cout << "Menor: " << temp_mim << endl;
    cout << "Maior: " << temp_max << endl;

    fclose(arq);
    return 0;
}

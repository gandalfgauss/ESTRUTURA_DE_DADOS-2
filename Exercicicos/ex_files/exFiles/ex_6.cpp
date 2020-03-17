#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE *in, *out;
    int n = 100;
    int j;

    if ((in = fopen("numeros.bin", "w+b")) == NULL)
    {
        cout << "Erro na abertura do arquivo " << endl;
    }

    if ((out = fopen("numeros.bin", "w+b")) == NULL)
    {
        cout << "Erro na abertura do arquivo " << endl;
    }

    for (int i = 0; i <= n; i++)
    {
        fwrite(&i, sizeof(int), 1, in);
    }

    fseek(in, 0, SEEK_SET);

    for (int i = 0; i <= n; i++)
    {
        fread(&j, sizeof(int), 1, in);

        if ((j % 2) == 0)
            fwrite(&j, sizeof(int), 1, out);
    }

    fseek(out, 0, SEEK_SET);

    int k = 0;
    for (int i = 0; i <= n; i++)
    {
        fread(&k, sizeof(int), 1, out);
        cout << k << endl;
    }

    fclose(in);
    fclose(out);

    return 0;
}

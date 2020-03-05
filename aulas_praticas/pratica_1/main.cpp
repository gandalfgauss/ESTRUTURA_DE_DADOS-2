#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE *arq;   //!Ponteiro para o arquivo
    FILE *arq_1; //! ponteiro para o arquivo  onde sera escrito o conceito
    int matricula;
    char nome[51];
    char enter, conceito;
    int faltas;
    double nota_1, nota_2, nota_3;
    double media;

    if ((arq = fopen("alunos.txt", "r")) == NULL)
    {
        cout << "Erro na abertura do arquivo" << endl;
        exit(1);
    }

    if ((arq_1 = fopen("conceitos.txt", "w")) == NULL)
    {
        cout << "Erro na criacao do arquivo" << endl;
        exit(1);
    }

    while (fscanf(arq, "%d %[A-Z a-z] %lf %lf %lf %d %[\n]",
                  &matricula, nome, &nota_1, &nota_2, &nota_3, &faltas, &enter) != EOF)
    {
        media = 0.0;
        //printf("%d %s %.1lf %.1lf %.1lf %d \n", 
        //matricula, nome, nota_1, nota_2, nota_3, faltas);

        media = (nota_1 + nota_2+ nota_3) / 3;

        if(faltas > 18)
        {   conceito = 'F';
            fprintf(arq_1, "%d %s %c\n", matricula, nome, conceito);
        }
        else
        {
            if((media >= 0 && media < 6.0) )
            {
                conceito = 'R';
                fprintf(arq_1, "%d %s %c\n", matricula, nome, conceito);
            }
            else if( (media >= 6.0 && media < 7.5) )
            {
                conceito = 'C';
                fprintf(arq_1, "%d %s %c\n", matricula, nome, conceito);
            }
            else if(media >= 7.5 && media < 9.0 )
            {
                conceito = 'B';
                fprintf(arq_1, "%d %s %c\n", matricula, nome, conceito);
            }
            else if(media >= 9.0 && media < 10.0 )
            {
                conceito = 'A';
                fprintf(arq_1, "%d %s %c\n", matricula, nome, conceito);
            }
        }

        
    }
    //fachemento dos arquivos
    fclose(arq);
    fclose(arq_1);
    return 0;
}
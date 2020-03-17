#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

typedef struct
{
    int matricula;
    char *nome;
    int faltas;
    double nota_1, nota_2, nota_3;
    char conceito;
    double media;
}Aluno;

int main()
{
    FILE *arq_1, *arq_2;
    FILE *arqBin;

    Aluno *aluno;
    //char enter;

    int matricula;
    char *nome;
    char enter/* , conceito */;
    int faltas;
    double nota_1, nota_2, nota_3;
    double media;

    if ((arq_1 = fopen("alunos.txt", "r")) == NULL)
    {
        cout << "Erro na abertura do arquivo" << endl;
        exit(1);
    }

    if ((arq_2 = fopen("conceitos.txt", "w")) == NULL)
    {
        cout << "Erro na criacao do arquivo" << endl;
        exit(1);
    }

    int i =0;
    while (fscanf(arq_1, "%d %[A-Z a-z] %lf %lf %lf %d %[\n]",
                  &matricula, nome, &nota_1, &nota_2, &nota_3, &faltas, &enter) != EOF)
    {
        media = 0.0;
        //printf("%d %s %.1lf %.1lf %.1lf %d \n", 
        //matricula, nome, nota_1, nota_2, nota_3, faltas);

        media = (nota_1 + nota_2+ nota_3) / 3;

        aluno->nota_1 = nota_1;
        aluno->nota_2 = nota_2;
        aluno->nota_3 = nota_3;
        aluno->nome =  nome;
        aluno->matricula = matricula;
        aluno->faltas = faltas;
        aluno->media = media;



        if(faltas > 18)
        {   aluno->conceito = 'F';
            //fprintf(arq_2, "%d %s %c\n", aluno->matricula, aluno->nome, aluno->conceito);
        }
        else
        {
            if((media >= 0 && media < 6.0) )
            {
                aluno->conceito = 'R';
                //fprintf(arq_2, "%d %s %c\n", aluno->matricula, aluno->nome, aluno->conceito);
            }
            else if( (media >= 6.0 && media < 7.5) )
            {
                aluno->conceito = 'C';
                //fprintf(arq_2, "%d %s %c\n", aluno->matricula, aluno->nome, aluno->conceito);
            }
            else if(media >= 7.5 && media < 9.0 )
            {
                aluno->conceito = 'B';
                //fprintf(arq_2, "%d %s %c\n", aluno->matricula, aluno->nome, aluno->conceito);
            }
            else if(media >= 9.0 && media < 10.0 )
            {
                aluno->conceito = 'A';
                //fprintf(arq_2, "%d %s %c\n", aluno->matricula, aluno->nome, aluno->conceito);
            }
        }
    }

   /*  fseek(arq_2, 0, SEEK_SET);

    if ((arqBin = fopen("alunos.bin", "wb")) == NULL)
    {
        cout << "Erro na criacao do arquivo" << endl;
        exit(1);
    }

    while (aluno != NULL)
    {
        fwrite(&aluno, sizeof(aluno), 1, arqBin);
    } */
    


    //fachemento dos arquivos
    //fclose(arqBin);
    fclose(arq_1);
    fclose(arq_2);
    return 0;
}
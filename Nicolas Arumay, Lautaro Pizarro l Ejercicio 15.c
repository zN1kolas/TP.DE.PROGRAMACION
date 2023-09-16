#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char Materias[5][20]={"Matematicas", "Lengua", "Ingles", "Geografia", "Biologia"};
    char Trim[3][10]={"Trim 1", "Trim 2", "Trim 3"};
    int Notas[3][5];
    srand(time(NULL));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
        {
            Notas[i][j]= rand()%10+1;
        }
    }

    for(int i=0; i<5; i++)
    {
        printf("\t");
        printf("%8s", Materias[i]);

    }
    printf("\n");
    for(int i=0; i<3; i++)
        {
            printf("%s ", Trim[i]);
            for(int j=0; j<5; j++)
            {

                printf("%\t%5d\t", Notas[i][j]);
            }
            printf("\n");
        }


}

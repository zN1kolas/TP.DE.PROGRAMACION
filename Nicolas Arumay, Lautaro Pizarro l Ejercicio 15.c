#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void Cargar (int Notas[3][5]); //Cargar matriz de notas
void Mostrar (char Materias[5][20], char Trim[3][10], int Notas[3][5]);
void MateriasProm(int Notas[3][5],float Promedios[4], char Materias[5][20]);
void PorcentAprob(int Notas[3][5], float Porcentaje[4], char Trim[3][10]);
void PromGeneral (float Promedios[4]);


int main()
{
    char Materias[5][20]={"Matematicas", "Lengua", "Ingles", "Geografia", "Biologia"};
    char Trim[3][10]={"Trim 1", "Trim 2", "Trim 3"}, Nombre[20];
    int Notas[3][5];
    float Promedios[4], Porcentaje[4];

    printf("Ingrese su nombre: \n");
    fflush(stdin);
    gets(Nombre);
    srand(time(NULL));
    system("cls");

    Cargar (Notas);
    Mostrar (Materias, Trim, Notas);
    printf("Nombre completo: %s\n", Nombre);
    //Punto a)
    printf("a)\n");
    MateriasProm (Notas, Promedios, Materias);
    printf("b)\n");
    PorcentAprob (Notas, Porcentaje, Trim);
    printf("c)\n");
    PromGeneral (Promedios);

}

void Cargar (int Notas[3][5])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
        {
            Notas[i][j]= rand()%10+1;
        }
    }

}
void Mostrar (char Materias[5][20], char Trim[3][10], int Notas[3][5])
{
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
    printf("\n");
}
void MateriasProm(int Notas[3][5],float Promedios[4], char Materias[5][20])
{
    float Suma=0;
    int j=0;
        while(j<5)
        {
            Suma=0;
            for (int i=0; i<3; i++)
            {
                Suma=Suma+Notas[i][j];
            }
            Promedios[j]=Suma/3;
            printf("Promedio de %s: %.2f\n", Materias[j], Promedios[j]);
            j++;
        }
}
void PorcentAprob(int Notas[3][5], float Porcentaje[4], char Trim [3][10])
{
    int j=0, cont;
        while (j<3)
        {
            cont=0;
            for(int i=0; i<5; i++)
            {
                if (Notas[j][i]>6)
                {
                    cont+=1;
                }
            }
            Porcentaje[j]=(cont*100)/5;
            printf("%s : %.2f\n", Trim[j], Porcentaje[j]);
            j++;
        }
}

void PromGeneral (float Promedios[4])
{
    float Promedio, Suma=0;
    for(int i=0; i<5; i++)
        {
            Suma=Suma+Promedios[i];
        }
        Promedio=Suma/5;
        printf("El promedio general es: %.2f", Promedio);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void MateriasPromedio (int Notas[3][5], float Suma, float Promedios[]);
void PorcenMaterias (int Notas[3][5], int cont, float Porcentaje[]);

int main()
{
    char Materias[5][20]={"Matematicas", "Lengua", "Ingles", "Geografia", "Biologia"};
    char Trim[3][10]={"Trim 1", "Trim 2", "Trim 3"};
    int cont, Notas[3][5], j=0;
    char Nombre[10];
    float Suma=0, Promedios[4], Porcentaje[3], Suma1=0;

        printf("Ingrese su nombre: \n");
        fflush(stdin);
        gets(Nombre);

        srand(time(NULL));
        system("cls");
        //Cargar matriz de notas
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<5; j++)
            {
                Notas[i][j]= rand()%10+1;
            }
        }
        printf("\n");
        //Imprimir tabla
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

        //Promedios
        MateriasPromedio(Notas, Suma, Promedios);
        PorcenMaterias(Notas, cont, Porcentaje);



        printf("\na)\n");
        printf("Nombre completo: %s\n", Nombre);
        printf("Promedio de Matematicas: %.2f\n", Promedios[0]);
        printf("Promedio de Lengua: %.2f\n", Promedios[1]);
        printf("Promedio de Ingles: %.2f\n", Promedios[2]);
        printf("Promedio de Geografia: %.2f\n", Promedios[3]);
        printf("Promedio de Biologia: %.2f\n", Promedios[4]);

        printf("\nb)\n");
        printf("Trim 1: %2.f%c\n", Porcentaje[0], 37);
        printf("Trim 2: %2.f%c\n", Porcentaje[1], 37);
        printf("Trim 3: %2.f%c\n", Porcentaje[2], 37);

        printf("\nc)\n");
        PorcenGeneral(Suma1, Promedios);
        system("pause");
        system("cls");


    }

void MateriasPromedio(int Notas[3][5], float Suma, float Promedios[4])
{
    int j=0;
        while(j<5)
        {
            Suma=0;
            for (int i=0; i<3; i++)
            {
                Suma=Suma+Notas[i][j];
            }
            Promedios[j]=Suma/3;
            j++;
        }
}

void PorcenMaterias(int Notas[3][5], int cont, float Porcentaje[4])
{
    int j=0;
        while (j<3)
        {
            cont=0;
            for(int i=0; i<5; i++)
            {
                if (Notas[j][i]>=6)
                {
                    cont+=1;
                }
            }
            Porcentaje[j]=(cont*100)/5;
            j++;
        }
}

void PorcenGeneral (float Suma1, float Promedios[4])
{
    for(int i=0; i<5; i++)
        {
            Suma1=Suma1+Promedios[i];
        }
        printf("Promedio general: %.1f\n\n", Suma1/5);
}


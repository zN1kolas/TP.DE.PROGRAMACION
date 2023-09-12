#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void Cargar (int Vector[]); //Para cargar el vector con numeros al azar
void Mostrar (int Vector[]); //Para mostrar el contenido del vector
void ContRepetido (int Vector[]); //Cuenta cuantas veces se repite el numero en el vector
bool SinRepetidos (int Num, int Vector[],int i); //Saca los numeros repetidos del vector
void Interseccion (int Vector[], int Vector2[], int *cont, int Vector3[]);

int main(){
    int Vector[10], Vector2[10], Vector3[10], opc, Num, cont=0;
    srand(time(NULL));
    Cargar(Vector);
    Cargar(Vector2);
    do
    {
        do
        {
            printf("\tMENU DE OPCIONES\n");
            printf("\n1) Mostrar vectores y numeros repetidos");
            printf("\n2) Mostrar vectores sin numeros repetidos");
            printf("\n3) La union entre ambos vectores");
            printf("\n4) La interseccion entre ambos vectores");
            printf("\n5) Mostrar la resta de A - B");
            printf("\n6) Mostrar la resta de B - A");
            printf("\n7) Salir del programa\n");
            printf("Seleccione una opcion: "); scanf("%d", &opc);
            if (opc<1 || opc>7)
            {
                system("cls");
                printf("Esa opcion NO existe, porfavor ingrese una opcion valida\n");
                system("pause");
                system("cls");
            }
        } while (opc<1 || opc>7);

        switch(opc)
        {
            case 1:
                system("cls");
                printf("\t  Vector\n");
                Mostrar(Vector);
                ContRepetido(Vector);
                printf("\n\t  Vector 2\n");
                Mostrar(Vector2);
                ContRepetido(Vector2);

                break;

            case 2:
                system("cls");
                printf("\t  Vector\n");
                for(int i=0;i<10;i++)
                {
                    Num=Vector[i];
                    while(SinRepetidos(Num,Vector,i))
                    {

                    Num=rand()%16+20;
                    }
                    Vector[i]=Num;
                }
                Mostrar(Vector);
                printf("\n\t  Vector 2\n");
                for(int i=0;i<10;i++)
                {
                    Num=Vector2[i];
                    while(SinRepetidos(Num,Vector2,i))
                    {

                    Num=rand()%16+20;
                    }
                    Vector2[i]=Num;
                }
                Mostrar(Vector2);
                break;
            case 4:
                system("cls");
                Limpiar(&cont, Vector3);
                Interseccion(Vector,Vector2,&cont, Vector3);

                break;
            case 7:
                break;

    }
    if (opc !=7)
    {
        system("pause");
        system("cls");
    }

    }while(opc !=7);

}

void Cargar (int Vector[10]){

    for(int i=0;i<10;i++){

        Vector[i]= rand()% 16+20;
    }

}

void Mostrar (int Vector[10]){

    for(int i=0;i<10;i++){

        printf("%d ", Vector[i]);
    }
    printf("\n");
}

bool SinRepetidos (int Num, int Vector[10],int i){
    int j;
    for(j=0;j<i;j++){

        if(Num == Vector[j]){
            return true;
        }
    }
    return false;
}

void ContRepetido(int Vector[10])
{
int conteo[16] = {0};

    for(int i = 0; i < 10; i++) {
        conteo[Vector[i] - 20]++;
    }

    for(int i = 0; i < 16; i++) {
        if (conteo[i] > 0) {
            printf("El numero %d se repite %d veces\n", i + 20, conteo[i]);
        }
    }
}

void Interseccion (int Vector[10], int Vector2[10], int *cont, int Vector3[*cont])
{

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(Vector[i] == Vector2[j])
            {
                Vector3[*cont] = Vector[i];
                *cont=*cont+1;

            }
        }
    }
    printf("Interseccion entre los vectores: \n");
    for(int i=0;i<*cont;i++)
    {

        printf("%d ", Vector3[i]);

    }
    printf("\n");
}

void Limpiar (int *cont, int Vector[*cont])
{
    for(int i=0; i<*cont; i++)
    {
        Vector[i]=0;
    }
    *cont=0;
}

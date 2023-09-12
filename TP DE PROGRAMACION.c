#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void Cargar (int Vector[]); //Para cargar el vector con numeros al azar
void Mostrar (int Vector[]); //Para mostrar el contenido del vector
void ContRepetido (int Vector[]); //Cuenta cuantas veces se repite el numero en el vector
bool SinRepetidos (int Num, int Vector[],int i); //Saca los numeros repetidos del vector
void Interseccion (int Vector[], int Vector2[], int *cont, int Vector3[]); //Muestra la interseccion entre los vectores
void UnionVectores(int Vector[], int Vector2[], int Vector4[]); //Muestra la union entre los vectores
void Limpiar (int *cont, int Vector[*cont]);//Para limpiar el vector que contiene las intersecciones y muestre siempre lo mismo

int main(){
    int Vector[10], Vector2[10], Vector3[10], Vector4[20], opc, Num, cont=0;
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
            case 3:
                system("cls");
                printf("\t  Vector\n");
                Mostrar(Vector);
                printf("\n\t  Vector 2\n");
                Mostrar(Vector2);
                UnionVectores(Vector, Vector2, Vector4);
                break;
            case 4:
                system("cls");
                printf("\t  Vector\n");
                Mostrar(Vector);
                printf("\n\t  Vector 2\n");
                Mostrar(Vector2);
                Limpiar(&cont, Vector3);
                Interseccion(Vector,Vector2,&cont, Vector3);
                break;
            case 5:
                break;
            case 7:
                break;

    }
    if (opc !=7)
    {
        printf("\n"); system("pause");
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
    printf("\nInterseccion entre los vectores: \n");
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

void UnionVectores (int Vector[10], int Vector2[10], int Vector4[20]){
    int opc, acum=0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            opc=0;
            if(Vector[i]==Vector2[j])
            {
                opc=1;
                break;
            }
        }

        if(opc==0)
            {
                Vector4[acum]=Vector[i];
                acum=acum+1;
            }

    }
    for(int i=0; i<10; i++)
    {

        for(int j=0; j<10; j++)
        {
            opc=0;
            if(Vector2[i]==Vector[j])
            {
                opc=1;
                break;
            }
        }

        if(opc==0)
            {
                Vector4[acum]=Vector2[i];
                acum=acum+1;
            }
    }
    printf("\nUnion entre los vectores:\n");
    for(int i=0; i<acum; i++)
    {
        printf("%d ",Vector4[i]);
    }
    printf("\n");
}

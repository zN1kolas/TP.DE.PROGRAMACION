#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void Cargar (int Vector[]); //Para cargar el vector con numeros al azar
void Mostrar (int Vector[]); //Para mostrar el contenido del vector
void ContRepetido (int Vector[]);
bool SinRepetidos (int Num, int Vector[],int i); //Saca los numeros repetidos del vector

int main(){
    int Vector[10], Vector2[10], opc, Num;

    do{

    printf("\tMENU DE OPCIONES\n");
    printf("\n1) Mostrar vectores y numeros repetidos");
    printf("\n2) Mostrar vectores sin numeros repetidos");
    printf("\n3) La union entre ambos vectores");
    printf("\n4) La interseccion entre ambos vectores");
    printf("\n5) Mostrar la resta de A - B");
    printf("\n6) Mostrar la resta de B - A\n");
    printf("Seleccione una opcion: "); scanf("%d", &opc);
    if (opc<1 || opc>6){
        system("cls");
        printf("Esa opcion NO existe, porfavor ingrese una opcion valida\n");
        system("pause");
        system("cls");
    }
    } while (opc<1 || opc>6);
    srand(time(NULL));
    Cargar(Vector);
    Cargar(Vector2);
    switch(opc)
    {
        case 1:
            system("cls");
            printf("\t  Vector\n");
            Mostrar(Vector);
            ContRepetido(Vector);
            printf("\n\t  Vector 2\n");
            Mostrar(Vector);
            ContRepetido(Vector);

            break;

        case 2:
            system("cls");
            for(int i=0;i<10;i++){
                Num=Vector[i];
                while(SinRepetidos(Num,Vector,i)){

                    Num=rand()%16+20;

                }
                Vector[i]=Num;
            }
            for(int i=0;i<10;i++){
                Num=Vector2[i];
                while(SinRepetidos(Num,Vector2,i)){

                    Num=rand()%16+20;

                }
                Vector2[i]=Num;
            }
            Mostrar(Vector);
            Mostrar(Vector2);
        break;

    }

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

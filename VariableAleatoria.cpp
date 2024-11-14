/*Calculadora de esperanza, varianza y desviación estándar de una variable aleatoria*/

#include <iostream>
#include <math.h>

struct VarAleatoria
{
    int valor;
    float probabilidad;
};

void CargaDeDatos(VarAleatoria vec[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Ingrese el %d%c valor de X: ", i+1, 167); // 167-> º
        scanf("%d", &vec[i].valor);
        printf("Ingrese la probabilidad del %d%c valor de X: ", i+1, 167);
        scanf("%f", &vec[i].probabilidad);
    }

    return;
}

float CalcularEsperanza(VarAleatoria vec[], int size)
{
    float esperanza = 0;
    for(int i=0; i<size; i++)
    {
        esperanza += (vec[i].valor * vec[i].probabilidad);
    }

    return esperanza;
}

float CalcularVarianza(VarAleatoria vec[], int size, float esperanza)
{
    float varianza = 0;
    for(int i=0; i<size; i++)
    {
        varianza += (pow(vec[i].valor - esperanza, 2) * vec[i].probabilidad);
    }

    return varianza;
}

int main()
{
    int totalValores;

    printf("Ingrese la cantidad de valores que puede tomar X: ");
    scanf("%d", &totalValores);
    VarAleatoria rangoX[totalValores];

    CargaDeDatos(rangoX, totalValores);
    float esperanza = CalcularEsperanza(rangoX, totalValores);
    float varianza = CalcularVarianza(rangoX, totalValores, esperanza);
    float desviacion = sqrt(varianza);

    printf("La esperanza de X es: %.5f \nLa varianza de X es: %.5f \nLa desviacion estandar de X es: %.5f \n", esperanza, varianza, desviacion);

    return 0;
}
#include <stdio.h>
#include "Funciones.h"

int Menu(){
//variable para elegir la opcion dentro del switch.
 int opcion;
 //variable que guarda el numero "A" = x , "B" = y.
 float x;
 float y;
 //variable que guarda el resultado de cada operacion.
 float suma;
 float resta;
 float division;
 float multiplicacion;
 int factorialA;
 int factorialB;
 //bandera para saber si se ingreso el primero numero.
 int flag1 = 0;
 //bandera para saber si se ingreso el segundo numero.
 int flag2 = 0;
 //bandera para saber si se hizo el calculo.
 int flag3 = 0;

do{
//muestro las opciones y cuando introduzcan el primero y segundo numero los coloco al lado.
    if(flag1==0){
        printf("1). Introducir el primer numero. \n");
    } else {
    printf("1). Introducir el primer numero. A = %.2f\n", x);
    }
    if (flag2 ==0){
        printf("2). Introducir el segundo numero. \n");
    }else {
    printf("2). Introducir el segundo numero. B = %.2f \n", y);
    }
    printf("3). Calcular todas las operaciones. \n");
    printf("4). Mostrar las operaciones.\n");
    printf("5). Salir.\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
        flag1 = 99;
        x = GetNum();
            break;
        case 2:
        flag2 = 99;
        y = GetNum();
            break;
        case 3:
//si se introdujeron los primeros dos numeros hago las cuentas, si no muestro el mensaje de error.
            if(flag1 ==99 && flag2==99){
                suma = Suma(x, y);
                resta = Resta(x, y);
                division = Division(x, y);
                multiplicacion = Multiplicacion(x, y);
                factorialA = FactorialA(x);
                factorialB = FactorialB(y);
                printf("Calculando...\n");
                flag3 = 99;
            } else {
            printf("Le falta introducir uno o ambos numeros.\n");
            }

            break;
        case 4:
//si se calculo (case 3) muestro los numeros si no muestro el mensaje de error.
            if (flag3 == 99){
                printf("La suma entre %.2f y %.2f es: %.2f \n",x , y, suma);

                printf("La diferencia entre %.2f y %.2f es: %.2f \n",x , y, resta);

                if (division == 0) {
                    printf("No se puede dividir por cero.\n");
                } else {
                    printf("El cociente entre %.2f y %.2f es: %.2f \n",x , y, division);
                }

                printf("El producto entre  %.2f y %.2f es: %.2f \n",x , y, multiplicacion);

                if  (factorialA == 0 ) {
                printf("No se puede calcular factorial de numeros con coma, negativos o mayores a 12.\n");
                }else {
                printf("El factorial de %.2f es: %d \n", x, factorialA);
                }
                if  (factorialB == 0 ) {
                printf("No se puede calcular factorial de numeros con coma, negativos o mayores a 12.\n");
                }else {
                printf("El factorial de %.2f es: %d \n", y, factorialB);
                }

            }else{
            printf("Debes calcular primero.\n");
            }

            break;
        case 5:
            printf("Adios uwu .\n");
            break;
        default:
            fflush(stdin);
            printf("El caracter ingresado no es una opcion valida.\n");
            break;
    }


system("pause");
system("cls");

} while (opcion != 5);

return opcion;
}

float GetNum() {
//funcion que pide los numeros, la variable lo guarda y lo pasa al menu.
float numero;

printf("Introduzca el numero: ");
scanf("%f", &numero);
return numero;

}

float Suma(float x, float y){
float suma;

suma = x + y;
return suma;
}

float Resta(float x, float y){
float resta;

resta = x - (y);

return resta;
}

float Division(float x, float y){
float division;
//si el divisor es 0 devuelvo 0 para mostrar el mensaje de error, si no lo es hago el calculo.
if (y == 0) {
    division = 0;
} else {
division = x / y;
}

return division;
}

float Multiplicacion(float x, float y){
float multiplicacion;

multiplicacion = x * y;

return multiplicacion;
}
float FactorialA(float x){
//variable que guardad la parte entera del numero.
int entero;
//variable que guarda la resta entre el numero y su parte entera para ver si tiene decimales.
float validacion;
//variable que guarda el factorial.
int factorialA = 1;

entero = (int)x;
validacion = x - entero;
//valido si el numero no tiene coma, es negativo o mayor a 12, si no lo es hago la factorizacion si lo es devuelvo 0 para mostrar mensaje de error.
if (x >=0 && validacion == 0 && x <=12){
    //variable de control.
    for(int i =1 ; i <= x; i++ ){
        factorialA = factorialA * i;
    }
}else {
factorialA = 0;
}

return factorialA;

}
float FactorialB(float y){
int entero;
float validacion;
int factorialB = 1;
entero = (int) y;
validacion = y - entero;

if (y >= 0 && validacion == 0 && y<=12){
    for (int i=1 ; i <= y; i++){
        factorialB = factorialB * i;
    }
} else {
factorialB = 0;
}
return factorialB;
}

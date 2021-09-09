//MÉTODO BISECCIÓN DE LA FORMA X^3+X^2+X+C
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

//auxiliar para validacion global
char aux[50];

int validar_real(char* n) {
    char *ap_final;
    double valor = strtod(n, &ap_final);
    return !(*ap_final == '\0' || isspace(*ap_final) != 0);
}

double iteracion_anterior=1;    // valor de la aproximación anterior
double iteracion_actual=1;  // valor de la aproximación actual
int iteracion=0;    // veces que se ha repetido el procedimiento

//double leer_doble();    // lee un número double de la entrada
int validacion_intervalo(double x1,double xu,double c1,double c2,double c3,double c4);  // valida x_1, x_u != 0
double calcular_xr(double x1,double xu);
double casos(double x1,double xr,double c1,double c2,double c3,double c4);  // devuelve f(x_1) * f(x_r)
double error_aprox(double actual, double anterior);

int main(){
	double error_aproximado=100;    // error en la actual repetición
    double validacion;  // si el intervalo leído es válido o no
    double res; // guarda f(x_1) * f(x_r)
    double raiz;    // valor aproximado de la raíz
	double x1,xu,xr,Ea,c1,c2,c3,c4; // variables que introduce el usuario

	
	printf("\t--------------METODO DE BISECCION-------------\n\n");
	printf("\t\tDA SOLUCION A LA FORMA x%c+x%c+x+c",252,253);
	
	do{
		do{
		printf("\n\n\tIngresa el valor minimo de tu intervalo: ");
		gets(aux);
		if(validar_real(aux)==1){
                printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------");
            }
    	}while(validar_real(aux)==1);
        x1 = atof(aux);
		

		do{
		printf("\n\tIngresa el valor maximo de tu intervalo: ");
		gets(aux);
		if(validar_real(aux)==1){
                printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------");
            }
		}while(validar_real(aux)==1);
		xu = atof(aux);
	
		
		do{
			do{
			printf("\n\tIngresa el maximo valor del error aproximado que puede tener: ");
			gets(aux);
			if(validar_real(aux)==1){
                	printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------");
            	}
			}while(validar_real(aux)==1);
			Ea = atof(aux);
		}while(Ea>99.9);
		
		do{
		printf("\n\n\tIngresa el coeficiente del termino x%c: ",252);
		gets(aux);
		if(validar_real(aux)==1){
                printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------\n");
            }
		}while(validar_real(aux)==1);
		c1 = atof(aux);
		
		do{
		printf("\n\tIngresa el coeficiente del termino x%c: ",253);
		gets(aux);
		if(validar_real(aux)==1){
                printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------\n");
            }
		}while(validar_real(aux)==1);
		c2 = atof(aux);
		
		do{
		printf("\n\tIngresa el coeficiente del termino x: ");
		gets(aux);
		if(validar_real(aux)==1){
                printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------\n");
            }
		}while(validar_real(aux)==1);
		c3 = atof(aux);
		
		do{
		printf("\n\tIngresa el valor de tu constante: ");
		gets(aux);
		if(validar_real(aux)==1){
                printf("\n\n\t-----------ERROR DE DATO INGRESADO--------------\n");
            }
		}while(validar_real(aux)==1);
		c4 = atof(aux);
		
		validacion=validacion_intervalo(x1,xu,c1,c2,c3,c4);
	}while(validacion==0);
	
	
	do{
		xr=calcular_xr(x1,xu);
		++iteracion;
		iteracion_anterior=iteracion_actual;
		iteracion_actual=xr;
		res= casos(x1,xr,c1,c2,c3,c4);
		if(res<0){  // si f(x_1) * f(x_r) < 0
			xu=xr;
		}else if(res>0){    // si f(x_1) * f(x_r) > 0
			x1=xr;
		}else{  // si f(x_1) * f(x_r) = 0
			// raiz=xr;
			// printf("\n\tAproximacion a la raiz: %lf",raiz);
			break;
		}
		if(iteracion>1){    // en iteración 1, el error aproximado tiene el valor de 100%
			error_aproximado=error_aprox(iteracion_actual,iteracion_anterior);
		}

	}while (error_aproximado>Ea);   // mientras el error aproximado sea mayor al que quiere el usuario
	
	raiz=xr;
	printf("\n\tAproximacion a la raiz: %lf",raiz);
	printf("\n\tError aproximado: %lf%c",error_aproximado,37);
	
	return 0;
}

/*double leer_doble() {
    char cadena[127];   // cadena temporal para leer valores
    char *ap; // apuntador necesario para convertir a real
    fgets(cadena, 127, stdin);
    return strtod(cadena, &ap);
}*/

int validacion_intervalo(double x1,double xu,double c1,double c2,double c3,double c4){
	int a=0;    // indica si el intervalo es válido
	double fx1,fxr,res;
	fx1= (c1*(pow(x1,3)))+(c2*(pow(x1,2)))+(c3*x1)+c4;  // f(x_1)
	// printf("%lf\n",fx1);
	fxr= (c1*(pow(xu,3)))+(c2*(pow(xu,2)))+(c3*xu)+c4;  // f(x_r)
	// printf("%lf\n",fxr);
	res=fx1*fxr;
	if(res>=0){ // si f(x_1) * f(x_r) >= 0
		printf("\n\n\t----NO CONTIENE LA RAIZ -----\n\n");
		return a;
	}
	else{   // si f(x_1) * f(x_r) < 0
		a=1;
	}
	return a;
}

double calcular_xr(double x1,double xu){
	double respuesta;
	respuesta= (x1+xu)/2;
	return respuesta;
}

double casos(double x1,double xr,double c1,double c2,double c3,double c4){
	double fx1,fxr,respuesta;
	fx1= (c1*(pow(x1,3)))+(c2*(pow(x1,2)))+(c3*x1)+c4;
	fxr= (c1*(pow(xr,3)))+(c2*(pow(xr,2)))+(c3*xr)+c4;
	respuesta=fx1*fxr;
	
	return respuesta;
}

double error_aprox(double actual, double anterior){
	double error_aproximado;
	error_aproximado= fabs((actual - anterior) / (actual)) * 100;

	return error_aproximado;
}



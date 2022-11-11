	/*	CORTE DE CONTROL - Movimientos de clientes de un banco
	*/
#include <stdio.h>
#include <string.h>

// defino tipo de dato cadena
typedef char string[20];

// defino registro del cliente
typedef struct {
	int nroCuenta;
	string nombre;
	int codOperacion;
	float importe;
}tRegistro;

tRegistro registro;
FILE * archivo;

// variables por campo de control
float acum_deposito;
float acum_extraccion;

int cant_deposito;
int cant_extraccion;

int cuentaAnterior;

// prototipo
void inicializar ();
void procesoCorte ();
void principioCorte ();
void finCorte ();

void leerRegistro ();
void unCliente ();
void finalizar ();

// bloque principal
int main () {
	inicializar ();
	procesoCorte ();
	finalizar ();
	return 0;
}

// implementacion
void inicializar () {
	archivo = fopen ("clientes.dat", "rb");
	leerRegistro ();
	
	printf ("\t\n***Detalle de movimientos por cuenta***\n\n");
	printf ("Nro de cuenta\tDeposito\tExtraccion\n\n");
}

void procesoCorte () {
	while (!feof(archivo)) {
		principioCorte ();
		
		while (!feof(archivo) && registro.nroCuenta == cuentaAnterior) {
			unCliente ();
			leerRegistro ();
		}

		
		finCorte ();
	}
}

void leerRegistro () {
	fread (&registro, sizeof (tRegistro), 1, archivo);
}

void principioCorte () {
	acum_deposito = 0;
	acum_extraccion = 0;
	cant_deposito = 0;
	cant_extraccion = 0;
	cuentaAnterior = registro.nroCuenta;
}

void unCliente () {
	if (registro.codOperacion == 1) {
		acum_deposito = acum_deposito + registro.importe;
		cant_deposito = cant_deposito + 1;
	}
	else {
		acum_extraccion = acum_extraccion + registro.importe;
		cant_extraccion = cant_extraccion + 1;
	}
	
	// printf ("%d %d %.2f\t", registro.nroCuenta, registro.codOperacion, registro.importe);
	printf ("%d\t", registro.nroCuenta);
	
}

void finCorte () {

	// printf("%d %d \n", acum_deposito,acum_extraccion);

	printf ("Total Cuenta: \t %.2f\t %.2f\n", acum_deposito, acum_extraccion);
	printf ("Cantidad de movimientos\t %d\t%d\n\n", cant_deposito, cant_extraccion);
	// printf ("%.2f\t %.2f\n", acum_deposito, acum_extraccion);
	// printf ("\t %d\t%d\n\n", cant_deposito, cant_extraccion);
}

void finalizar () {
	fclose (archivo);
}

































































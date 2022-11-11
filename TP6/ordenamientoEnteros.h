/*Ejemplo de cátedra - AED 2 - 2021*/
void seleccionDirecta(int[], int);
void insercionDirecta(int[], int);
void ordenacionPorIntercambio(int[], int);        
void ordenacionBurbujaMejorada(int[], int);

void ordenacionPorIntercambio(int pVector[], int pDim){ //Burbuja
	//Efecto: se ordena v ascendentemente 
	int i, j;
	int aux;	
	
	for (i = 0; i < pDim-1; i++) { //n-1 pasadas
		for (j = 0; j < pDim-1; j++)  { //n-1 comparaciones
			if (pVector[j] > pVector[j+1])  { 
				//intercambio
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
			}			
		}		
	}
}

void seleccionDirecta(int pVector[], int pDim){ //Selección sucesiva de menores
	//Efecto: se ordena pVector ascendentemente
	int i, j, posMenor;
	int valMenor, aux;  //2 - 12 -5- 7
	
	for (i = 0; i < pDim-1; i++) { //n-1 pasadas	
		valMenor = pVector[i];
		posMenor = i;
		
		for (j = i+1; j < pDim; j++) { //el número de comparaciones decrece
			if (pVector[j] < valMenor){
				//se actualiza el nuevo valor menor y la posición donde se encuentra
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if (posMenor != i) {
			//Si el menor no es pVector[i], se intercambian los valores
			aux = pVector[i];
			pVector[i] = pVector[posMenor]; 
			pVector[posMenor] = aux; 
		}
	}
}

void insercionDirecta(int pVector[], int pDim){ //Baraja
	//Efecto: se ordena pVector ascendentemente
	int i, j;
	int aux;  

	for (i = 1; i < pDim; i++) { //Ciclo de pasadas
		aux = pVector[i]; //Se reserva el valor en el auxiliar   //aux = 7
		j = i - 1;		
		while ((j >= 0) && (pVector[j] > aux))  { //Ciclo de comparaciones
			pVector[j+1] = pVector[j]; //Desplaza el elemento   //3 - 5  - 7 - 9
			j = j-1;  //Disminuye el valor de j										
		}
		pVector[j+1] = aux;	 //Ubica el valor, almacenado en auxiliar, en la posición que le corresponde 
	}
}

void ordenacionBurbujaMejorada(int pVector[], int pDim){
	//Efecto: se ordena v ascendentemente
	int i, j;
	int aux;
	bool bandera;

	bandera = false;
	i = 0;
	while ((bandera == false) && (i < pDim))	{
		bandera = true;	
		for (j = 0; j < pDim-1; j++)	{
			//Se busca el menor desde atras y se situa en vi
			if (pVector[j] > pVector[j+1]){
				//intercambio
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
				bandera = false;
			}
		}
		i = i+1;				
	}
}


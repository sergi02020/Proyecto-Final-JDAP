#include <memory.h> //Libreria para memorias 
#include <fstream>  //Libreria para manejo de archivos 
#include <iostream> //Libreria general
using namespace std ;

void reading(); // Funcion de lectura del archivo ROBCOM
void process(); // Funcion de comprobacion


short int m,n,i,j,p, //Definicion de variables como enteros cortos 
	  m1,m2,n1,n2,
	  c[100][100];

char s,cord,ste[40]; //Definicion de caracteres 

int main()
{
   memset(c,1,sizeof(c)); // Utilizacion del memset para guardar en pociciones de memoria la matriz C
   reading(); // Direccionar a la funcion de lectura
   while (p != i) // Ciclo mientras para comprobar que el numero de pasos y la cantidad de pasos ingresados sean iguales
   {
   	void failures(); // Direccionar a la funcion de fracasos o fallos 
   }
   process(); // Direccionar a la funcion de comprobacion
}  
void reading() // Funcion de lectura
{
     ifstream asig("ROBCOM.txt"); // Lectura del archivo ROBCOM
     asig>>m>>n; // Lectura del tamaño de la matriz

     for (i = 1; i <= m; i++) { // Ciclo para de asignar valores en la matriz
	 for (j = 1; j < n; j++)
	 asig>>c[i][j]; // Lectura de la matriz
	 asig>>c[i][n];
     };

     asig>>m1>>n1; // Lectura de la pocision inicial del robot
     asig>>m2>>n2; // Lectura de la pocision final del robot
     asig>>cord; // Lectura de la orientacion cardinal del robot
     asig>>p; // Numero de pasos de orientacion

     i = 0;
     for ( ; i < p; ++i) // Ciclo (para) sobre la lectura de las indicaciones de pasos
	 asig>>ste[i];

     asig.close();
}//reading

void failures() // Funcion de fallos
{
   ofstream salida("ROBCOM1.txt"); // Creacion del archivo de salida
   s = 'E'; // s como "E" de fallo en llegar a la ruta
   salida<<s; // Imprimir el resultado en el archivo de texto
   salida.close();
   exit(1);
}

void process() // Funcion de comprobacion
{
   for (i = 0; i < p; i++) // Ciclo (para) recorriendo p
   {
       switch (ste[i]) // Condicional switch recorriendo las instrucciones 
       {
	   case 'D': // Caso en D (Derecha)
	   {
		 switch(cord) // Condicional switch segun cordenada cardinal
		 {
		    case 'N' : { cord = 'E'; break; }
		    case 'S' : { cord = 'O'; break; }
		    case 'E' : { cord = 'S'; break; }
		    case 'O' : { cord = 'N'; break; }
		 }
		 break;
	   } 

	   case 'I': // Caso en I (Izquierda)
	   {
		 switch(cord) // Condicional switch segun cordenada cardinal
		 {
		    case 'N' : { cord = 'O'; break; }
		    case 'S' : { cord = 'E'; break; }
		    case 'E' : { cord = 'N'; break; }
		    case 'O' : { cord = 'S'; break; }
		 };
		 break;
	   }

	   default: // condicional por defecto A (Avance)
	   {
		 switch(cord) // Condicional Switch segun cordenadas 
		 {
		    case 'N' : // Hacia el Norte
		    {
			if (c[m1-1][n1] != 0) failures();
			m1--;
			break;
		    }
		    case 'S' : // Hacia el Sur
		    {
			if (c[m1+1][n1] != 0) failures();
			m1++;
			break;
		    }
		    case 'E' : // Hacia el Este
		    {
			if (c[m1][n1+1] != 0) failures();
			n1++;
			break;
		    }
		    case 'O' : // Hacia el Oeste
		    {
			if (c[m1][n1-1] != 0) failures();
			n1--;
			break;
		    }
		 }
	   } 
       }
   }
   if ((m1 = m2) & (n1 = n2)) // Condicional para comprobar si la pocision inicial es igual a la final
   {
      ofstream salida("ROBCOM1.txt"); // Creacion del archivo de salida
      s = 'C'; //  s como "C" de acierto al llegar a su objetivo
      salida<<s; // Imprimir el resultado en el archivo de texto
      salida.close();
   }
   else failures(); // Si no se cumple se direcciona a la funcion de fallos
}

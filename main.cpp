
#include "Celulas.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<unistd.h>
#include<ctime>

using namespace std;
/*Dar� un tiempo en el cual se generar� la matriz de celulas,
 despu�s de haberla generado e impreso, hace una pausa en el proceso
 para que el usuario pulse una tecla y dar continuac�n a la siguiente matriz
 con la nueva generaci�n de c�lulas*/

int main()
{
		srand (time(NULL));
		Celulas celulas (20,20);
		while(1)
		{
			celulas.imprimir ();
			usleep (100000) ;
			system ("pause");
			celulas.ciclo ();
		}
	return 0;
}

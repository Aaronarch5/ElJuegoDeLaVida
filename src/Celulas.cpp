#include "Celulas.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<unistd.h>
#include<ctime>

	/*Se crea una matriz y se definen las filas y columnas de esta*/
	Celulas::Celulas (int f, int c)
	{
		filas = f;
		columnas = c;
		celulas . resize (filas);
		for (int i=0; i<celulas.size(); i++)
		{
			celulas[i].resize(columnas);
		}

		for (int f=0; f<filas; f++)
		{
			for (int c=0; c<columnas; c++)
			{
				celulas [f][c] = rand () %2;
			}
		}
	}

	/* Se hace la impresión de los carácteres que representaran a las celulas, en este caso el asterisco se usará para una celula en ese espacio . */
	void Celulas::imprimir()
	{
		for (int f=0; f< filas; f ++)
		{
			for (int c=0; c<columnas; c++)
			{
				if(celulas[f][c]==1)
					cout << "*";
				else
					cout << "  ";
			}
			cout << "\n";
		}
	}

	/* Cada if se encarga de analizar la posicion de cada célula con respecto de otra
	para hacer la accion que corresponde y da vida o muerte a la célula */
	int Celulas::analizarCelulasCercanas(int posf , int posc)
	{
		celulasCercanas = 0;
		if ((posf-1) >= 0 && (posc-1)>=0)
			if(celulas[posf-1][posc-1] == 1)
				celulasCercanas++;

		if ((posf-1) >= 0)
			if( celulas [posf-1][posc] == 1)
				celulasCercanas++;

		if(posf-1 >= 0 && posc+1 <= columnas-1)
			if(celulas[posf-1][posc+1] == 1)
				celulasCercanas++;

		if(posc-1 >= 0)
			if(celulas[posf][posc-1] == 1)
				celulasCercanas++;

		if(posc+1 <= columnas-1)
			if(celulas [posf][posc +1] == 1)
				celulasCercanas++;

		if( posf+1 <= filas-1 && posc-1 >= 0)
			if(celulas [posf +1][posc -1] == 1)
				celulasCercanas++;

		if(posf+1 <= filas-1)
			if(celulas[posf+1][posc] == 1)
				celulasCercanas++;

		if(posf+1 <= filas-1 && posc+1<=columnas-1)
			if(celulas[posf +1][posc +1] == 1)
				celulasCercanas++;

		return celulasCercanas;
	}

	/*Vector para crear una nueva matriz con la nueva genración de células con las sobrevivientes*/
	void Celulas::ciclo ()
	{
		vector <vector<int>>nueva_conf = celulas;

		for ( int f=0; f< filas ; f++)
		{
			for (int c=0; c< columnas ; c ++)
			{
				int n_celulasCercanas = analizarCelulasCercanas (f, c);
				if( celulas [f][c] == 0)
				{
					if( celulasCercanas == 3)
						nueva_conf [f][c] = 1;
					else
						nueva_conf [f][c] = 0;
				}
				if ( celulas [f][c] == 1)
				{
					if( celulasCercanas == 2 || celulasCercanas == 3)
						nueva_conf [f][c] = 1;
					else
						nueva_conf [f][c] = 0;
				}
			}
		}

		celulas = nueva_conf;

	}





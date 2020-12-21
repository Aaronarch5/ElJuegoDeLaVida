#ifndef CELULAS_H
	#define CELULAS_H
	#include <iostream>
	#include <cstdlib>
	#include <vector>
	#include <unistd.h>
	#include <ctime>

	using namespace std;

	class Celulas //Clase para definr el comportamiento y caracteristicas de las células
	{
		private:
			int filas;
			int columnas;
			int celulasCercanas;
			vector <vector<int>>celulas;
        public:
		Celulas(int f, int c); //Constructor y este crea el arreglo con la cantidad de celulas asignadas
		void imprimir(); //Atributo para imrprimor el area donde esarán ubicadas las celulas
		int analizarCelulasCercanas (int posf, int posc);
		//ATributo que compara la cantidad de celulas cercanas unas de otras
		void ciclo(); //Repite ciclo

	};


	#endif

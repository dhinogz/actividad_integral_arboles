#include <iostream>
#include <fstream>

using namespace std;

#include "BST_3_4.h"

void loadData(dataCS &dataLoaded, BST &arbol, string txtFile)
{
	ifstream dataSuez(txtFile);
	while(dataSuez >> dataLoaded.nombre >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.tipo)
	{
		arbol.add(dataLoaded);
	}
	dataSuez.close();
}

int main()
{
    BST arbolM;
    BST arbolR;
	struct dataCS dataSuez;

	// preguntamos por el nombre del archivo de texto
	string txtFileM, txtFileR;
	cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Mediterráneo? (ej. canal.txt): ";
	cin >> txtFileM;
	cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Rojo? (ej. canal.txt): ";
	cin >> txtFileR;

	// cargamos los datos 
	loadData(dataSuez, arbolM, txtFileM);

    cout << "Entradas Mar ROJO" << endl;
    arbolM.print();

    loadData(dataSuez, arbolR, txtFileR);
    
    cout << "Entradas Mar MEDITERRANEO" << endl;
    arbolR.print();
	
}


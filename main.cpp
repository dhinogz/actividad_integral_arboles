#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "BST_3_4.h"

void loadData(dataCS &dataLoaded, BST &arbol, string txtFile, queue<string> &qu)
{
	ifstream dataSuez(txtFile);
	while(dataSuez >> dataLoaded.ubi >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.tipo)
	{
        dataLoaded.nombre = dataLoaded.ubi.substr(0,3);
        dataLoaded.cant = arbol.repetidos(dataLoaded.nombre) + 1;
        arbol.add(dataLoaded);
    }
    dataSuez.close();
}

int main()
{
    BST arbolM;
    BST arbolR;
	struct dataCS dataSuez;

    queue<string> quM;
    queue<string> quR;

	// preguntamos por el nombre de los archivos de texto
	string txtFileM, txtFileR;
	cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Mediterráneo? (ej. canal.txt): ";
	cin >> txtFileM;
	cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Rojo? (ej. canal.txt): ";
	cin >> txtFileR;

	// cargamos los datos 
	loadData(dataSuez, arbolM, txtFileM, quM);

    cout << "Entradas Mar ROJO" << endl;
    arbolM.print();

    loadData(dataSuez, arbolR, txtFileR, quR);

    cout << "Entradas Mar MEDITERRANEO" << endl;
    arbolR.print();
}

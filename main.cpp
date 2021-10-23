#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "BST_3_4.h"

void loadData(dataCS &dataLoaded, BST &arbol, string txtFile)
{
	ifstream dataSuez(txtFile);
	while(dataSuez >> dataLoaded.ubi >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.tipo)
    {
        dataLoaded.nombre = dataLoaded.ubi.substr(0,3);
        dataLoaded.cant = arbol.repeat(dataLoaded.nombre) + 1;    
        arbol.add(dataLoaded);
    }
    dataSuez.close();
}

int main()
{
    BST arbolM;
    BST arbolR;
	struct dataCS dataSuez;

	// preguntamos por el nombre de los archivos de texto
	string txtFileM, txtFileR;
	cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Rojo? (ej. pruebaR.txt): ";
	cin >> txtFileR;
    cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Mediterráneo? (ej. pruebaM.txt): ";
	cin >> txtFileM;

	// cargamos los datos 
	
    loadData(dataSuez, arbolR, txtFileR);
    cout << "Entradas Mar ROJO" << endl;
    arbolR.print();

    loadData(dataSuez, arbolM, txtFileM);
    cout << "Entradas Mar MEDITERRANEO" << endl;
    arbolM.print();

}

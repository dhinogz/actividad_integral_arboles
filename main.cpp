/*
Autores: 
David Hinojosa González - A01720601
Sebastián Joya Páez - A01025103
Ricardo Jorge Rodríguez Treviño - A00831595
Fecha: 24/10/2021
Descripción: El presente código solicita el nombre de dos archivos de texto de los barcos que navegan por el canal de Suez
(uno para el Mar Mediterráneo y el otro para el Mar Rojo) para posteriormente contabilizar las incidencias de cada una de las 
series y almacenar esto como data único en dos árboles binarios de búsqueda (uno para cada mar) y desplegarlos en pantalla.
*/

#include <iostream>
#include <fstream>

using namespace std;

#include "BST.h"

// Se obtienen los datos del archivo de entrada para introducirlos en el árbol correspondiente
// Complejidad: O(n)
void loadData(dataCS dataLoaded, BST &arbol, string txtFile)
{
	ifstream dataSuez(txtFile);
    int cont = 1;
    string name;
    string aux;
    dataSuez >> dataLoaded.ubi >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.tipo;
    aux = dataLoaded.ubi;
    while(dataSuez >> dataLoaded.ubi >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.tipo)
    {
        name = dataLoaded.ubi.substr(0,3);
        if (name == aux.substr(0,3)){
            cont++;
            aux = dataLoaded.ubi;
        }
        else{
            dataLoaded.nombre = aux.substr(0,3);
            dataLoaded.cant = cont;
            arbol.add(dataLoaded);

            aux = dataLoaded.ubi;
            cont = 1;
        }
    }
    dataLoaded.nombre = aux.substr(0,3);
    dataLoaded.cant = cont;
    arbol.add(dataLoaded);
    dataSuez.close();
}

int main()
{
    BST arbolM;
    BST arbolR;
	struct dataCS dataSuez;

	// Se pregunta por el nombre de cada uno de los archivos de texto
	string txtFileM, txtFileR;
	cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Rojo? (ej. pruebaR.txt): ";
	cin >> txtFileR;
    cout << "¿Cuál es el nombre del archivo de texto de donde se sacarán los datos del Mar Mediterráneo? (ej. pruebaM.txt): ";
	cin >> txtFileM;

	// Se cargan los datos correspondientes al Mar Rojo
    loadData(dataSuez, arbolR, txtFileR);
    // Se imprime el árbol
    cout << "Entradas Mar ROJO" << endl;
    arbolR.print();

    // Se cargan los datos correspondientes al Mar Mediterráneo
    loadData(dataSuez, arbolM, txtFileM);
    // Se imprime el árbol
    cout << "Entradas Mar MEDITERRANEO" << endl;
    arbolM.print();
}

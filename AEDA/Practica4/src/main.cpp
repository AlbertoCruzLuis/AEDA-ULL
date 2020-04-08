//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: main.cpp
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#include "../include/Tabla.h"
#include "../include/Dni.h"
#include <iostream>
#include <vector>
#include <map>
#include "../include/Celda.h"

int main()
{
  //Parametros para crear la tabla Hash
  int nCeldas;
  int nClaves;

  //Solicitar los parametros para crear la tabla Hash
  std::cout << "Introducir Numero de Celdas: ";
  std::cin >> nCeldas;
  std::cout << "Introducir NUmero de Claves: ";
  std::cin >> nClaves;

  int tipoFDispersion;   //Tipo de Funcion de Dispersion
  std::cout << "Elegir una Funcion de Dispersion\n";
  std::cout << "Modulo: 0\nSuma: 1\nPseudoaleatoria: 2\n";
  std::cout << "Tipo: ";
  std::cin >> tipoFDispersion;
  //Guardar Tipo de Funcion de Dispersion en un mapa
  std::map<int,std::string> Dispersion;
  Dispersion[0] = "Modulo";
  Dispersion[1] = "Suma";
  Dispersion[2] = "Pseudoaleatoria";

  int tipoFExploracion;   //Tipo de Funcion de Exploracion
  std::cout << "Elegir una Funcion de Exploracion\n";
  std::cout << "Lineal: 0\nCuadratica: 1\nDispersion Doble: 2\n";
  std::cout << "Tipo: ";
  std::cin >> tipoFExploracion;
  //Guardar Tipo de Funcion de Exploracion en un mapa
  std::map<int,std::string> Exploracion;
  Exploracion[0] = "Lineal";
  Exploracion[1] = "Cuadratica";
  Exploracion[2] = "Dispersion Doble";

  //Pedir Funcion de Dispersion
  //Pedir Funcion de Exploracion

  //Parametros del experimento
  double factor;     //Valor entre [0...1]
  int nPruebas;

  //Solicitar los parametros del experimento
  std::cout << "Introducir el factor de carga entre [0..1]: ";
  std::cin >> factor;
  while(factor < 0 || factor > 1)
  {
    std::cout << "Error\nIntroducir el factor de carga entre [0..1]: ";
    std::cin >> factor;
  }
  std::cout << "Introducir el Numero de Pruebas: ";
  std::cin >> nPruebas;

  //Crear un banco de prueba
  //2*N Valores Tipo Dni Random
  //Tamaño banco de pruebas
  int N = factor * nCeldas * nClaves;
  AEDA::Dni dni;
  // Cremos el Banco de Pruebas
  //std::vector<AEDA::Dni> banco_pruebas(N);
  std::vector<int> banco_pruebas(N);
  //Instanciamos de forma aleatoria los datos del banco de pruebas
  srand(time(NULL));
  for(int i = 0; i < banco_pruebas.size(); i++)
  {
    banco_pruebas[i] = rand() % 100; 
  }

  //Crear Tabla Hash e insertar los N valores obtenidos del Banco de Pruebas
  AEDA::Tabla<int> tabla(nCeldas, nClaves, tipoFDispersion, tipoFExploracion);
  for(int i = 0; i < banco_pruebas.size(); i++)
  {
    tabla.Insertar(banco_pruebas[i]);
  }
  //Mostramos la Tabla Hash
  tabla.Mostrar();

  //Valores para el experimento
  //Capacidad de la Tabla: 100, 1000 y 10000
  //Factores de carga: 0.3 0.5 0.7 0.8 0.9 

  //1) Experimento Operacion Busqueda
  //Inicializar a 0 

  //Realizar la busqueda
  

  //2) Experimento Operacion Insercion
  //Inicializar a 0 

  //Realizar la busqueda


  //3)Mostrar los Datos obtenidos
  std::cout << "+++++++++++++++++++++++++\n";
  std::cout << "| Datos del Experimento |\n"; 
  std::cout << "+++++++++++++++++++++++++\n";

  //Texto
  std::cout << "Celdas\tnClaves\t\tDispersion\t\tExploracion" <<
  "\t\tCarga\tPruebas\n";

  //Resultados
  std::cout << nCeldas << "\t" << nClaves << "\t\t" <<
  Dispersion[tipoFDispersion] << "\t\t\t" << Exploracion[tipoFExploracion] << "\t\t" <<
  factor << "\t" << nPruebas << "\n\n";

  //Texto
  std::cout << "           " <<
  "Minimo\t\tMedio\t\tMaximo\n";
  std::cout << "Busquedas";

  //Resultados

  //Texto
  std::cout << "\nInsercion\n";
  
  //Resultados
  


}
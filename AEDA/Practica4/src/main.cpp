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

  //Guardar Tipo de Funcion de Dispersion en un mapa
  std::map<int,std::string> Dispersion = {
    {0,"Modulo"},
    {1,"Suma"},
    {2,"Pseudoaleatoria"}
  };
  int tipoFDispersion;   //Tipo de Funcion de Dispersion
  std::cout << "Elegir una Funcion de Dispersion\n";
  std::cout << "Modulo: 0\tSuma: 1\tPseudoaleatoria: 2\n";
  std::cout << "Tipo: ";
  std::cin >> tipoFDispersion;
  //Comprobar si la clave se encuentra en el mapa
  auto itD = Dispersion.find(tipoFDispersion);
  while(itD == Dispersion.end())
  {
    std::cout << "Error" << "\nTipo: ";
    std::cin >> tipoFDispersion;
    itD = Dispersion.find(tipoFDispersion);
  }

  //Guardar Tipo de Funcion de Exploracion en un mapa
  std::map<int,std::string> Exploracion = {
    {0,"Lineal"},
    {1,"Cuadratica"},
    {2,"Dispersion Doble"}
  };
  int tipoFExploracion;   //Tipo de Funcion de Exploracion
  std::cout << "Elegir una Funcion de Exploracion\n";
  std::cout << "Lineal: 0\tCuadratica: 1\tDispersion Doble: 2\n";
  std::cout << "Tipo: ";
  std::cin >> tipoFExploracion;
  //Comprobar si la clave se encuentra en el mapa
  auto itE = Exploracion.find(tipoFExploracion);
  while(itE == Exploracion.end())
  {
    std::cout << "Error" << "\nTipo: ";
    std::cin >> tipoFExploracion;
    itE = Exploracion.find(tipoFExploracion);
  }

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
  // Cremos el Banco de Pruebas
  //std::vector<AEDA::Dni> banco_pruebas(N);
  std::vector<AEDA::Dni> banco_pruebas(2*N);
  //Instanciamos de forma aleatoria los datos del banco de pruebas
  srand(time(NULL));
  for(int i = 0; i < banco_pruebas.size(); i++)
  {
    banco_pruebas[i] = AEDA::Dni(rand());
    std::cout << banco_pruebas[i] << "\n";
  }

  //Crear Tabla Hash e insertar los N valores obtenidos del Banco de Pruebas
  AEDA::Tabla<AEDA::Dni> tabla(nCeldas, nClaves, tipoFDispersion, tipoFExploracion);

  //Insertar en la tabla los N primeros valores del banco
  for(int i = 0; i < N; i++)
  {
    tabla.Insertar(banco_pruebas[i]);
  }

  //Valores para el experimento
  //Capacidad de la Tabla: 100, 1000 y 10000
  //Factores de carga: 0.3 0.5 0.7 0.8 0.9 

  //1) Experimento Operacion Busqueda
  //Buscar las nPruebas aleatoreamente en la tabla hash
  for(int i = 0; i < N; i++)
  {
    std::cout << "Busqueda\n";
    tabla.Buscar(banco_pruebas[i]);
  }

  //2) Experimento Operacion Insercion
  //Insertar las nPruebas aleatorimente de las utimas N claves
  /*for(int i = N; i < banco_pruebas.size(); i++)
  {
    tabla.Insertar(banco_pruebas[i]);
  }*/

  //Mostramos la Tabla Hash
  tabla.Mostrar();

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
  "Minimo\t\tMedio\t\tMaximo\t\tTotal\n";
  std::cout << "Busquedas";

  //Resultados Busquedas

  //Texto
  std::cout << "\nInsercion";
  
  //Resultados Insercion
  std::cout << "\t" << tabla.get_estadisticas().min() << "\t\t" <<
  tabla.get_estadisticas().media() << "\t\t" <<
  tabla.get_estadisticas().max() << "\t\t" <<
  tabla.get_estadisticas().total() << "\n";

}
//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: main.cpp
//@Version: Práctica 2 Modificacion - El juego de la Vida
//==============================================================

#include "tablero.h"
#include "celula.h"

int main()
{
  int n, m, turnos;
  //Pedir las dimensiones de la malla y el numero de turnos
  std::cout << "Introducir Numero de Columnas: ";
  std::cin >> n;
  std::cout << "Introducir Numero de Filas: ";
  std::cin >> m;
  std::cout << "Introducir Numero de Turnos: ";
  std::cin >> turnos;

  //Creamos Nuestro Tablero
  AEDA::Tablero tablero(n,m);

  //Elegir la forma de colocar las celulas vivas
  std::cout << "Pulsa 0 - Para introducir celulas manualmente\n"
  << "Pulsa 1 - Para introducir celulas aleatoriamente\n";
  int mode;
  std::cin >> mode;
  if(mode)
    tablero.random_tablero();
  else
    tablero.rellenar_tablero();

  //Mostrar la malla del tablero Inicialmente
  tablero.print();
  //Mostrar el Numero Maximo de Vecinos Inicialmente
  std::cout << "Numero Maximo de Vecinos: " <<
      tablero.maximo_vecinos() << "\n";

  //Ejecutamos cada turno del juego en un bucle
  int sum_vivas = 0;
  std::vector<std::pair<int,int>> pos_vivas;
  for(int i = 0; i < turnos; i++)
  {
    //Mostrar Turno
    std::cout << "------ Turno: " << i << "------\n";

    //Contar Vecinas y Actualizar estado
    tablero.update(); 
    //Mostrar por Pantalla
    tablero.print();

    //Hallar la celula con el mayor numero de vecinos
    std::cout << "Numero Maximo de Vecinos: " <<
      tablero.maximo_vecinos() << "\n";   
  }

  return 0;
}
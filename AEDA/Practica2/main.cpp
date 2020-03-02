//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: main.cpp
//@Version: Práctica 2 - El juego de la Vida
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

  //Colocar las celulas vivas y actualizar el estado de las celulas
  tablero.poner_celula_viva(3,1);
  tablero.poner_celula_viva(1,1);
  tablero.poner_celula_viva(1,2);
  tablero.poner_celula_viva(2,1);
  tablero.poner_celula_viva(2,3);

  //Mostrar la malla del tablero
  tablero.print();

  //Ejecutar cada turno en un bucle
  //Cada turno actualizar y mostrar
  while(turnos--)
  {
    //Mostrar Turno
    std::cout << "------ Turnos Restantes " << turnos << "------\n";

    //Bucle para Contar vecinas y actulizar estado de cada celula del Tablero
    for(int i = 1; i < n+1; i++)
      for(int j = 1; j < m+1; j++)
      {
        //1) Contar sus vecinas y guardarlas
        tablero.get_malla()[i]->data()[j]->contar_vecinas(tablero,i,j);
        //Comprobaciones
        /*std::cout << "POS: " << i << "," << j << "N_Vecinas: " << tablero.get_malla()[i]->data()[j]->get_vecinas();
        if(tablero.get_malla()[i]->data()[j]->get_vecinas() == 3)
          std::cout << " Viva\n";
        else
          std::cout << "\n";*/
      }
    for(int i = 1; i < n+1; i++)
      for(int j = 1; j < m+1; j++)
      {
        //2) Actualizar su estado
        tablero.get_malla()[i]->data()[j]->actualizar_estado();
      } 
    //3) Mostrar por Pantalla
    tablero.print();
  }
  return 0;
}
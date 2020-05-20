//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Mayo 2020
//@Name: Demostracion.cpp
//@Version: Práctica 7 - ​​Implementación árbol binario búsqueda balanceado
//=======================================================================

#ifndef PROGRAMA_DEMOSTRACION
#define PROGRAMA_DEMOSTRACION

#include <iostream>
#include "ArbolAVL.h"
#include "Dni.h"

void demostracion()
{
  std::cout << "-----------------------\n";
  std::cout << "|  Modo Demostracion  |\n";
  std::cout << "-----------------------\n";
  //Definimos el Tipo de Clave a Usar
  typedef AEDA::Dni clave;

  //Creamos el arbol Vacio
  AEDA::ArbolAVL<clave> AVL;

  int mode = -1;
  try
  {
    while (mode != 0)
    {
      //Menu Opciones
      std::cout << "\n[0] Salir\n[1] Insertar Clave\n[2] Eliminar Clave\n";
      std::cout << "Opcion: ";
      std::cin >> mode;
      while (mode < 0 || mode > 2)
      {
        std::cout << "Error.\nOpcion Incorrecta\n";
        std::cout << "Opcion: ";
        std::cin >> mode;
      }

      //Salir del Programa
      if(mode == 0)
        throw mode;

      //Pedir Clave
      clave dato;
      std::cout << "Introducir la Clave\n";
      std::cin >> dato;

      //Realizar una Opcion
      switch (mode)
      {
        case 1: std::cout << "-> Insertar: " << dato << "\n";
          AVL.Insertar(dato);
          break;
        case 2: std::cout << "-> Eliminar: " << dato << "\n";
          AVL.Eliminar(dato);
          break;
        default:
          throw mode;
      }

      //Mostrar el arbol
      AVL.RecorreNivel();

      //Separacion
      std::cout << "--------------------\n";
    }
  }
  catch(int mode)
  {
    std::cout << "Fin del programa\n";
  }
}

#endif
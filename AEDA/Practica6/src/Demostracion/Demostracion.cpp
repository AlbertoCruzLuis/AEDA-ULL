//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Demostracion.cpp
//@Version: Práctica 6 - ​​ Implementación de un árbol binario de búsqueda
//=======================================================================

#ifndef PROGRAMA_DEMOSTRACION
#define PROGRAMA_DEMOSTRACION

#include <iostream>
#include "../../include/ArbolBB.h"
#include "../../include/Dni.h"

void demostracion()
{
  std::cout << "-----------------------\n";
  std::cout << "|  Modo Demostracion  |\n";
  std::cout << "-----------------------\n";
  //Definimos el Tipo de Clave a Usar
  typedef AEDA::Dni clave;

  //Creamos el arbol Vacio
  AEDA::ArbolBB<clave> ABB;

  int mode = 1;
  while (mode != 0)
  {
    //Menu Opciones
    std::cout << "\n[0] Salir\n[1] Insertar Clave\n[2] Eliminar Clave\n";
    std::cin >> mode;

    //Salir del Programa
    if(mode == 0)
      return;

    //Pedir Clave
    clave dato;
    std::cout << "Introducir la Clave\n";
    std::cin >> dato;

    //Realizar una Opcion
    switch (mode)
    {
      case 1: ABB.Insertar(dato);
        break;
      case 2: ABB.Eliminar(dato);
        break;
    }

    //Mostrar el arbol
    ABB.RecorreNivel();
  }
}

#endif
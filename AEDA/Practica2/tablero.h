//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: tablero.h
//@Version: Práctica 2 - El juego de la Vida
//==============================================================

#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "celula.h"

namespace AEDA
{
class Tablero
{
  public:
    Tablero(int, int, int);
    ~Tablero(){}
    void poner_celula_viva(int, int);
    void print(std::ostream& os = std::cout);

  private:
    int n_;   //Numero de Filas
    int m_;   //Numero de Columnas
    int turno_;
    std::vector<std::vector<Celula*>*> malla_;
};
}

#endif
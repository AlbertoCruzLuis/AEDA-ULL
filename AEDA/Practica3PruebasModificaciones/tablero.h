//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: tablero.h
//@Version: Práctica 3 - El juego de la Vida Generalizado
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
    Tablero(int, int);
    ~Tablero();
    std::vector<std::vector<Celula*>*> get_malla() const
    { return malla_; }
    void poner_celula(int, int, int);
    void rellenar_tablero();
    void random_tablero();
    void update();
    void contar_tipos_celulas();
    void print(std::ostream& os = std::cout);

  private:
    int n_;   //Numero de Filas
    int m_;   //Numero de Columnas
    std::vector<std::vector<Celula*>*> malla_;
};
}

#endif
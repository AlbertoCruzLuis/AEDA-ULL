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
    Tablero(int, int);
    ~Tablero();
    std::vector<std::vector<Celula*>*> get_malla() const
    { return malla_; }
    int get_n()
    { return n_; }
    int get_m()
    { return m_; }
    void poner_celula_viva(int, int);
    void rellenar_tablero();
    void random_tablero();
    void update();
    int maximo_vecinos();
    void print(std::ostream& os = std::cout);
    friend std::ostream& operator<<(std::ostream&, Tablero&);

  private:
    int n_;   //Numero de Filas
    int m_;   //Numero de Columnas
    std::vector<std::vector<Celula*>*> malla_;
};
}

#endif
//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula.h
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#ifndef CELULA_H
#define CELULA_H

#include <iostream>

namespace AEDA
{

//Declaramos la clase asi para evitar que se produzca un buble infinito
class Tablero;
class Celula1;
class Celula2;
class Celula3;
class CelulaX;

class Celula
{
  public:
    Celula(std::pair<int, int>);
    virtual ~Celula();
    static Celula* create_celula(int, int, int);
    virtual int get_Estado() const;
    virtual int actualizar_estado();
    virtual void contar_vecinas(const Tablero&);
    //Sobrecargar Operador de flujo
    friend std::ostream& operator<<(std::ostream& os, const Celula *celula);
    virtual std::ostream& print(std::ostream& os);

  protected:
    std::pair<int,int> pos_;
    int vecinas_;
};
}

#endif
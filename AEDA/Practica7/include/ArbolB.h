//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Mayo 2020
//@Name: ArbolB.h
//@Version: Práctica 7 - ​​Implementación árbol binario búsqueda balanceado
//=======================================================================

#ifndef ARBOLB_H
#define ARBOLB_H

#include "Nodo.h"
#include <queue>

namespace AEDA
{

template <class Clave>
class ArbolB
{
  public:
    ArbolB();
    ~ArbolB();

    Nodo<Clave>*& get_raiz();
    void Podar(Nodo<Clave>*&);
    bool EsVacio(Nodo<Clave>*);
    bool EsHoja(Nodo<Clave>*);
    const int Tam();
    const bool Equilibrado();
    void RecorreNivel();

  protected:
    Nodo<Clave>* raiz_;
    const int TamRama(Nodo<Clave>* nodo);
    const bool EquilibrioRama(Nodo<Clave> *nodo);
};

template <class Clave>
ArbolB<Clave>::ArbolB() : 
raiz_(nullptr)
{}

template <class Clave>
ArbolB<Clave>::~ArbolB()
{
  Podar(raiz_);
}

template <class Clave>
Nodo<Clave>*& ArbolB<Clave>::get_raiz()
{ return raiz_; }

template <class Clave>
bool ArbolB<Clave>::EsVacio(Nodo<Clave> *nodo)
{
  //Esta vacio si no hay nodos
  return nodo == NULL;
}

template <class Clave>
bool ArbolB<Clave>::EsHoja(Nodo<Clave> *nodo)
{
  //Es Hoja si no tiene subarboles
  return !nodo->get_izq() && !nodo->get_dcho();
}

template <class Clave>
void ArbolB<Clave>::Podar(Nodo<Clave>* &nodo)
{
  if (nodo == NULL)
    return;
  Podar(nodo->get_izq());    //Podar subarbol izquierdo
  Podar(nodo->get_dcho());   //Podar subarbol derecho
  delete nodo;
  nodo = nullptr;
}

template <class Clave>
const int ArbolB<Clave>::Tam()
{
  return TamRama(raiz_);
}

template <class Clave>
const int ArbolB<Clave>::TamRama(Nodo<Clave>* nodo)
{
  if (nodo == NULL) return 0;
  return (1 + TamRama(nodo->get_izq()) +
              TamRama(nodo->get_dcho()));
}

template <class Clave>
const bool ArbolB<Clave>::Equilibrado()
{
  return EquilibrioRama(raiz_);
}

template <class Clave>
const bool ArbolB<Clave>::EquilibrioRama(Nodo<Clave> *nodo)
{
  if (nodo == NULL) return true;
  int eq = TamRama(nodo->get_izq()) - TamRama(nodo->get_dcho());
  switch (eq)
  {
    case -1:
    case 0:
    case 1:
      return EquilibrioRama(nodo->get_izq()) && EquilibrioRama(nodo->get_dcho());

    default: return false;
  }
}

template <class Clave>
void ArbolB<Clave>::RecorreNivel()
{
  //Creamos una cola para almacenar los nodos y el nivel del arbol
  //Mediente una pareja de nodos y nivel
  std::queue<std::pair<Nodo<Clave>*,int>> Q;
  Nodo<Clave> *nodo;
  int nivel, Nivel_actual = 0;
  Q.push(std::make_pair(raiz_,0));

  std::cout << "Nivel 0: ";
  //Recorremos la cola hasta que este vacia
  while (!Q.empty())
  {
    //Guardamos el primer valor de la cola
    std::pair<Nodo<Clave>*,int> p;
    p = Q.front();
    nodo = p.first;
    nivel = p.second;
    //Quitamos la pareja(nodo,nivel) de la Cola
    Q.pop();
    if(nivel > Nivel_actual)
    {
      Nivel_actual = nivel;
      std::cout << "\nNivel " << Nivel_actual << ": ";
    }
    //Mostramos el valor del nodo
    nodo->print();
    if (nodo != NULL)
    {
      Q.push(std::make_pair(nodo->get_izq(),nivel+1));
      Q.push(std::make_pair(nodo->get_dcho(),nivel+1));
    }
  }
  std::cout << "\n";
}

}

#endif
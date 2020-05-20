//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Mayo 2020
//@Name: ArbolAVL.h
//@Version: Práctica 7 - ​​Implementación árbol binario búsqueda balanceado
//=======================================================================

#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include "Nodo.h"
#include "ArbolB.h"
#include "ArbolBB.h"

namespace AEDA
{
template <class Clave>
class ArbolAVL : public ArbolBB<Clave>
{
  public:
    ArbolAVL(/* args */);
    ~ArbolAVL();

    void Insertar(Clave);
    void Eliminar(Clave);

  private:
    void rotacion_II(Nodo<Clave>*&);
    void rotacion_DD(Nodo<Clave>*&);
    void rotacion_ID(Nodo<Clave>*&);
    void rotacion_DI(Nodo<Clave>*&);
    void inserta_bal(Nodo<Clave>*&, Nodo<Clave>*, bool&);
    void insert_re_balancea_izq(Nodo<Clave>*&, bool&);
    void insert_re_balancea_dcha(Nodo<Clave>*&, bool&);
    void elimina_rama(Nodo<Clave>*&, Clave, bool&);
    void sustituye(Nodo<Clave>*&, Nodo<Clave>*&, bool&);
    void eliminar_re_balancea_izq(Nodo<Clave>*&, bool&);
    void eliminar_re_balancea_dcha(Nodo<Clave>*&, bool&);

};

template <class Clave>
ArbolAVL<Clave>::ArbolAVL() :
ArbolBB<Clave>()
{}

template <class Clave>
ArbolAVL<Clave>::~ArbolAVL()
{
}

template <class Clave>
void ArbolAVL<Clave>::rotacion_II(Nodo<Clave>* &nodo)
{
  Nodo<Clave>* nodo1 = nodo->get_izq();
  nodo->get_izq() = nodo1->get_dcho();
  nodo1->get_dcho() = nodo;
  if (nodo1->get_bal() == 1)
  {
    nodo->get_bal() = 0;
    nodo1->get_bal() = 0;
  }
  else
  {
    nodo->get_bal() = 1;
    nodo1->get_bal() = -1;
  }
  nodo = nodo1;
}

template <class Clave>
void ArbolAVL<Clave>::rotacion_DD(Nodo<Clave>* &nodo)
{
  Nodo<Clave>* nodo1 = nodo->get_dcho();
  nodo->get_dcho() = nodo1->get_izq();
  nodo1->get_izq() = nodo;
  if (nodo1->get_bal() == -1)
  {
    nodo->get_bal() = 0;
    nodo1->get_bal() = 0;
  }
  else
  {
    nodo->get_bal() = -1;
    nodo1->get_bal() = 1;
  }
  nodo = nodo1;
}

template <class Clave>
void ArbolAVL<Clave>::rotacion_ID(Nodo<Clave>* &nodo)
{
  Nodo<Clave>* nodo1 = nodo->get_izq();
  Nodo<Clave>* nodo2 = nodo1->get_dcho();
  nodo->get_izq() = nodo2->get_dcho();
  nodo2->get_dcho() = nodo;
  nodo1->get_dcho() = nodo2->get_izq();
  nodo2->get_izq() = nodo1;
  if (nodo2->get_bal() == -1)
    nodo1->get_bal() = 1;
  else nodo1->get_bal() = 0;
  if (nodo2->get_bal() == 1)
    nodo->get_bal() = -1;
  else nodo->get_bal() = 0;
  nodo2->get_bal() = 0;
  nodo = nodo2;
}

template <class Clave>
void ArbolAVL<Clave>::rotacion_DI(Nodo<Clave>* &nodo)
{
  Nodo<Clave>* nodo1 = nodo->get_dcho();
  Nodo<Clave>* nodo2 = nodo1->get_izq();
  nodo->get_dcho() = nodo2->get_izq();
  nodo2->get_izq() = nodo;
  nodo1->get_izq() = nodo2->get_dcho();
  nodo2->get_dcho() = nodo1;
  if (nodo2->get_bal() == 1)
    nodo1->get_bal() = -1;
  else nodo1->get_bal() = 0;
  if (nodo2->get_bal() == -1)
    nodo->get_bal() = 1;
  else nodo->get_bal() = 0;
  nodo2->get_bal() = 0;
  nodo = nodo2;
}

template <class Clave>
void ArbolAVL<Clave>::Insertar(Clave dato)
{
  Nodo<Clave>* nuevo = new Nodo<Clave>(dato);
  bool crece = false;
  inserta_bal(this->get_raiz(), nuevo, crece);
}

template <class Clave>
void ArbolAVL<Clave>::inserta_bal(Nodo<Clave>* &nodo, Nodo<Clave>* nuevo,
                                  bool& crece)
{
  if (nodo == NULL)
  {
    nodo = nuevo;
    crece = true;
  }
  else if (nuevo->get_dato() < nodo->get_dato())
  {
    inserta_bal(nodo->get_izq(), nuevo, crece);
    if (crece) insert_re_balancea_izq(nodo,crece);
  }
  else
  {
    inserta_bal(nodo->get_dcho(), nuevo, crece);
    if (crece) insert_re_balancea_dcha(nodo,crece);
  }
}

template <class Clave>
void ArbolAVL<Clave>::insert_re_balancea_izq(Nodo<Clave>* &nodo, bool& crece)
{
  //Arreglar bool referencia 
  switch (nodo->get_bal())
  {
    case -1: 
      nodo->get_bal() = 0;
      crece = false;
      break;
    case 0:
      nodo->get_bal() = 1;
      break;
    case 1:
      Nodo<Clave>* nodo1 = nodo->get_izq();
      if (nodo->get_bal() == 1)
        rotacion_II(nodo);
      else 
        rotacion_ID(nodo);
      crece = false;
  }
}
template <class Clave>
void ArbolAVL<Clave>::insert_re_balancea_dcha(Nodo<Clave>* &nodo, bool& crece)
{
  switch (nodo->get_bal())
  {
    case 1: 
      nodo->get_bal() = 0;
      crece = false;
      break;
    case 0:
      nodo->get_bal() = -1;
      break;
    case -1:
      Nodo<Clave>* nodo1 = nodo->get_dcho();
      if (nodo1->get_bal() == -1)
        rotacion_DD(nodo);
      else 
        rotacion_DI(nodo);
      crece = false;
  }
}

template <class Clave>
void ArbolAVL<Clave>::Eliminar(Clave dato)
{
  bool decrece = false;
  elimina_rama(this->get_raiz(), dato, decrece);
}

template <class Clave>
void ArbolAVL<Clave>::elimina_rama(Nodo<Clave>* &nodo, Clave dato, 
                                  bool& decrece)
{
  if (nodo == NULL) return;
  if (dato < nodo->get_dato())
  {
    elimina_rama(nodo->get_izq(),dato,decrece);
    if (decrece)
      eliminar_re_balancea_izq(nodo, decrece);
  }
  else if (dato > nodo->get_dato())
  {
    elimina_rama(nodo->get_dcho(), dato, decrece);
    if (decrece)
      eliminar_re_balancea_dcha(nodo, decrece);
  }
  else
  {
    Nodo<Clave>* Eliminado = nodo;
    if (nodo->get_izq() == NULL)
    {
      nodo = nodo->get_dcho();
      decrece = true;
    }
    else if (nodo->get_dcho() == NULL)
    {
      nodo = nodo->get_izq();
      decrece = true;
    }
    else
    {
      sustituye(Eliminado, nodo->get_izq(), decrece);
      if (decrece)
        eliminar_re_balancea_izq(nodo, decrece);
    }
    delete Eliminado;
  }
}

template <class Clave>
void ArbolAVL<Clave>::sustituye(Nodo<Clave>* &eliminado, Nodo<Clave>* &sust,
                                bool &decrece)
{
  if (sust->get_dcho() != NULL)
  {
    sustituye(eliminado, sust->get_dcho(), decrece);
    if (decrece)
      eliminar_re_balancea_dcha(sust, decrece);
  }
  else
  {
    eliminado->get_dato() = sust->get_dato();
    eliminado = sust;
    sust = sust->get_izq();
    decrece = true;
  }
}

template <class Clave>
void ArbolAVL<Clave>::eliminar_re_balancea_izq(Nodo<Clave>* &nodo, bool &decrece)
{
  switch (nodo->get_bal())
  {
    case -1:
    {
      Nodo<Clave>* nodo1 = nodo->get_dcho();
      if (nodo1->get_bal() > 0)
        rotacion_DI(nodo);
      else
      {
        if(nodo1->get_bal() == 0)
          decrece = false;
        rotacion_DD(nodo);
      }
    } break;
    case 0:
      nodo->get_bal() = -1;
      decrece = false;
      break;
    case 1:
      nodo->get_bal() = 0;
  }
}

template <class Clave>
void ArbolAVL<Clave>::eliminar_re_balancea_dcha(Nodo<Clave>* &nodo, bool &decrece)
{
  switch (nodo->get_bal())
  {
    case 1:
    {
      Nodo<Clave>* nodo1 = nodo->get_izq();
      if (nodo1->get_bal() < 0)
        rotacion_ID(nodo);
      else
      {
        if(nodo1->get_bal() == 0)
          decrece = false;
        rotacion_II(nodo);
      }
    } break;
    case 0:
      nodo->get_bal() = 1;
      decrece = false;
      break;
    case -1:
      nodo->get_bal() = 0;
      break;
  }
}

}

#endif
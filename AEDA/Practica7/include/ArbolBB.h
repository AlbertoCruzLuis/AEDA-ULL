//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Mayo 2020
//@Name: ArbolBB.h
//@Version: Práctica 7 - ​​Implementación árbol binario búsqueda balanceado
//=======================================================================

#ifndef ARBOLBB_H
#define ARBOLBB_H

#include "Nodo.h"
#include "ArbolB.h"

namespace AEDA
{

template <class Clave>
class ArbolBB : public ArbolB<Clave>
{
  public:
    ArbolBB();
    ~ArbolBB();

    Nodo<Clave>* Buscar(Clave);
    void Insertar(Clave);
    void Eliminar(Clave);

  private:
    Nodo<Clave>* BuscarRama(Nodo<Clave>*,Clave);
    void InsertarRama(Nodo<Clave>*&,Clave);
    void EliminarRama(Nodo<Clave>*&,Clave);
    void Sustituye(Nodo<Clave>*&, Nodo<Clave>*&);
};

template <class Clave>
ArbolBB<Clave>::ArbolBB() : 
ArbolB<Clave>()
{}

template <class Clave>
ArbolBB<Clave>::~ArbolBB()
{
}

//Buscar un nodo en el arbol
template <class Clave>
Nodo<Clave>* ArbolBB<Clave>::Buscar(Clave dato)
{
  //std::cout << "Clave a Buscar: " << dato << "\n"; 
  return BuscarRama(this->get_raiz(), dato);
}

template <class Clave>
Nodo<Clave>* ArbolBB<Clave>::BuscarRama(Nodo<Clave>* nodo, Clave dato)
{
  if(nodo == NULL)
    return nullptr;
  if(dato == nodo->get_dato())
    return nodo;
  if(dato < nodo->get_dato())
    return BuscarRama(nodo->get_izq(), dato);
  return BuscarRama(nodo->get_dcho(), dato);
}

//Insertar un nodo en el arbol
template <class Clave>
void ArbolBB<Clave>::Insertar(Clave dato)
{
  InsertarRama(this->get_raiz(), dato);
}

template <class Clave>
void ArbolBB<Clave>::InsertarRama(Nodo<Clave>* &nodo, Clave dato)
{
  if(nodo == NULL)
    nodo = new Nodo<Clave>(dato);
  else if(dato < nodo->get_dato())
    InsertarRama(nodo->get_izq(), dato);
  else
    InsertarRama(nodo->get_dcho(), dato);
}

//Eliminar un nodo del arbol
template <class Clave>
void ArbolBB<Clave>::Eliminar(Clave dato)
{
  EliminarRama(this->get_raiz(), dato);
}

template <class Clave>
void ArbolBB<Clave>::EliminarRama(Nodo<Clave>* &nodo, Clave dato)
{
  if(nodo == NULL)
    return;
  if(dato < nodo->get_dato())
    EliminarRama(nodo->get_izq(), dato);
  else if(dato > nodo->get_dato())
    EliminarRama(nodo->get_dcho(), dato);
  else
  {
    Nodo<Clave>* Eliminado = nodo;
    if(nodo->get_dcho() == NULL)
      nodo = nodo->get_izq();
    else if(nodo->get_izq() == NULL)
      nodo = nodo->get_dcho();
    else
      Sustituye(Eliminado, nodo->get_izq());
    
    delete Eliminado;
  }
}

template <class Clave>
void ArbolBB<Clave>::Sustituye(Nodo<Clave>* &eliminado, Nodo<Clave>* &sust)
{
  if(sust->get_dcho() != NULL)
    Sustituye(eliminado, sust->get_dcho());
  else
  {
    eliminado->get_dato() = sust->get_dato();
    eliminado = sust;
    sust = sust->get_izq();
  }
}

}

#endif

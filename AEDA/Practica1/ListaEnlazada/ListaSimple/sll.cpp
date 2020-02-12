//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: sll.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "sll.h"

template <class TDato>
AEDA::sll<TDato>::sll() :
head_(nullptr)
{}

//Destructor que elimina los nodos de la lista simple
template <class TDato>
AEDA::sll<TDato>::~sll()
{
  //Implementar el metodo
}

//Insertar nuevo nodo por la cabeza
template <class TDato>
void AEDA::sll<TDato>::insert_head(sll_node<TDato>* n)
{
     //Implementar el metodo
}

//Extraer un nodo por la cabeza
template <class TDato>
AEDA::sll_node<TDato>* AEDA::sll<TDato>::extract_head()
{
  //Implementar el metodo
}

//Insertar un nodo posterior a otro
template <class TDato>
void AEDA::sll<TDato>::insert_after(AEDA::sll_node<TDato>* prev,
                                    AEDA::sll_node<TDato>* n)
{
  //Implementar el metodo
}

//Extraer un nodo posterior a otro
template <class TDato>
AEDA::sll_node<TDato>* AEDA::sll<TDato>::insert_after(
AEDA::sll_node<TDato>* prev)
{
  //Implementar el metodo
}

//Comprobar si la lista esta vacia
template <class TDato>
bool AEDA::sll<TDato>::is_empty()
{
  return ( head_ == nullptr );
}



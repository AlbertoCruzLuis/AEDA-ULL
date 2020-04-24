//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: HeapSort.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

namespace AEDA
{
  namespace HeapSort
  {
    template<class Clave>
    void swap(Clave& a, Clave& b)
    {
      //Intercambiar valores
      Clave aux = a;
      a = b;
      b = aux;
    }

    template<class Clave>
    void print(std::vector<Clave>& sec, int pos_l, int pos_r, int tam)
    {
      //Codigo de Colores
      //Rojo: 31 - Verde: 32 - Azul: 34
      for(int i = 0; i < sec.size(); i++)
      {
        if(i == tam)
          std::cout << "\e[34m" << sec[i] << " ";
        else if(i == pos_l)
          std::cout << "\e[31m" << sec[i] << " ";
        else if(i == pos_r)
          std::cout << "\e[32m" << sec[i] << " ";
        else
          std::cout << "\e[0m" << sec[i] << " ";
        std::cout << "\e[0m";
      }
      std::cout << "\n";
    }

    template<class Clave>
    void baja(int i, std::vector<Clave>& sec, int n)
    {
      while ( 2*i <= n )
      {
        int l = 2*i;
        int r = l + 1;
        int tam;
        //Pulsar Enter para reanudar la ejecucion del programa
        getchar();
        print(sec,l,r,tam);
        if(l == n)
          tam = l;
        else if(sec[l] > sec[r])
          tam = l;
        else 
          tam = r;
        if(sec[tam] <= sec[i])
          break;
        else 
        {
          swap(sec[i],sec[tam]);
          i = tam;
        }
      }
    }

    template<class Clave>
    void HeapSort(std::vector<Clave>& sec, int n)
    {
      //Algoritmo HeapSort
      for(int i = n/2; i > 0; i--)
      {
        baja(i, sec, n);
      }
      for(int i = n; i > 1; i--)
      {
        swap(sec[1],sec[i]);
        baja(1,sec,i-1);
      }
    }
  }
}

#endif
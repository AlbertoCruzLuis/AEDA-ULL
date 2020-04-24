//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: BubbleSort.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

namespace AEDA
{
  namespace BubbleSort
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
    void print(std::vector<Clave>& sec, int pos_i, int pos_j)
    {
      //Codigo de Colores
      //Verde: 32 - Rojo: 31
      for(int i = 0; i < sec.size(); i++)
      {
        if(i == pos_i)
          std::cout << "\e[31m";
        else if(i == pos_j)
          std::cout << "\e[32m";
        else
          std::cout << "\e[0m";
        std::cout << sec[i] << " ";
        std::cout << "\e[0m";
      }
      std::cout << "\n";

    }

    template<class Clave>
    void BubbleSort(std::vector<Clave>& sec, int n)
    {
      //Algoritmo de BubbleSort
      for(int i = 1; i < n; i++)
      {
        for(int j = n-1; j >= i; j--)
        {
          //Pulsar Enter para reanudar la ejecucion del programa
          getchar();
          print(sec,j-1,j);
          if(sec[j] < sec[j-1])
          {
            swap(sec[j-1],sec[j]);
            //std::cout << "Intercambio\n";
          }
        }
      }
    }
  }
}

#endif
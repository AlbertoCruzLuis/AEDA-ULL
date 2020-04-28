//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: HeapSort.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

extern int mode;

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
    void print(std::vector<Clave>& sec, int n, int pos_l, int pos_r, int tam)
    {
      //Codigo de Colores
      //Rojo: 31 - Verde: 32 - Azul: 34
      for(int i = 0; i < n; i++)
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
      int l = 2*i + 1;
      int r = l + 1;
      int tam = i;
      //Pulsar Enter para reanudar la ejecucion del programa
      if(mode == 1)
      {
        getchar();
        print(sec, n, l,r,tam);
      }
      if((l < n) && (sec[l] > sec[tam]))
      {
        //std::cout << "Baja\n";
        tam = l;
      }
      if((r < n) && (sec[r] > sec[tam]))
      {
        //std::cout << "Sube\n";
        tam = r;
      }
      if(tam != i) 
      {
        //std::cout << "Colocado\n";
        swap(sec[i],sec[tam]);
        baja(tam,sec,n);
      }
    }

    template<class Clave>
    std::vector<Clave> HeapSort(std::vector<Clave> sec, int n)
    {
      //Algoritmo HeapSort
      for(int i = (n/2)-1; i >= 0; i--)
      {
        baja(i, sec, n);
      }
      for(int i = n-1; i >= 0; i--)
      {
        swap(sec[0],sec[i]);
        baja(0,sec,i);
      }
      //Retornamos la secuencia ordenada
      return sec;
    }
  }
}

#endif
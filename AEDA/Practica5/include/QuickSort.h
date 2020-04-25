//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: QuickSort.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

extern int mode;

namespace AEDA
{
  namespace QuickSort
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
    void print(std::vector<Clave>& sec)
    {
      for(int i = 0; i < sec.size(); i++)
      {
        std::cout << sec[i] << " ";
      }
      std::cout << "\n";
    }

    template<class Clave>
    void QuickSort(std::vector<Clave>& sec, int pos_ini, int pos_fin)
    {
      //Algoritmo QuickSort
      int i = pos_ini;
      int f = pos_fin;
      Clave p = sec[(i+f)/2];
      //Pulsar Enter para reanudar la ejecucion del programa
      if(mode == 1)
      {
        getchar();
        print(sec);
      }
      while (i <= f)
      {
        while(sec[i] < p) i++;
        while(sec[f] > p) f--;
        if (i <= f)
        {
          swap(sec[i],sec[f]);
          i++;
          f--;
        }
      }
      if (pos_ini < f) QuickSort(sec, pos_ini, f);
      if (i < pos_fin) QuickSort(sec, i, pos_fin);
    }
  }
}

#endif
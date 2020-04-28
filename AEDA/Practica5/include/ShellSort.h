//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: ShellSort.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef SHELL_SORT_H
#define SHELL_SORT_H

extern int mode;

namespace AEDA
{
  namespace ShellSort
  {
    template<class Clave>
    void print(int del, std::vector<Clave>& sec, int n, int j)
    {
      //Codigo de Colores
      //Rojo: 31 - Verde: 32 - Azul: 34
      for(int i = 0; i < n; i++)
      {
        if(i == j)
          std::cout << "\e[34m" << sec[i] << " ";
        else if(i == (j-del))
          std::cout << "\e[32m" << sec[i] << " ";
        else
          std::cout << "\e[0m" << sec[i] << " ";
        std::cout << "\e[0m";
      }
      std::cout << "\n";
    }

    template<class Clave>
    void deltasort(int del, std::vector<Clave>& sec, int n)
    {
      for (int i = del; i < n; i++)
      {
        Clave x = sec[i];
        int j = i;
        if(mode == 1)
        {
          getchar();
          print(del,sec,n,j);
        }
        while ((j >= del) && (x < sec[j-del]))
        {
          sec[j] = sec[j-del];
          j = j - del;
        }
        sec[j] = x;
      }
    }

    template<class Clave>
    std::vector<Clave> ShellSort(std::vector<Clave> sec, int n, double a)
    {
      int del = n * a;
      while (del > 1)
      {
        del = del * a;
        deltasort(del,sec, n);
      }
      //Retornamos la secuencia ordenada
      return sec;
    }
  }
}

#endif
//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Insercion.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef INSERCION_H
#define INSERCION_H

extern int mode;

namespace AEDA
{
  namespace Insercion
  {
    template<class Clave>
    void print(std::vector<Clave>& sec, int pos_i, int pos_j)
    {
      //Codigo de Colores
      //Rojo: 31 - Azul: 34
      //Mostrar (pos: i + secuencia)
      if(pos_i != -2)
      {
        std::cout << "i = " << pos_i << " ";
        for(int i = 0; i < sec.size(); i++)
        {
          if(i < pos_i)
            std::cout << "\e[34m";
          else if(i == pos_i)
            std::cout << "\e[31m";
          else
            std::cout << "\e[0m";
          std::cout << " " << sec[i] << "  ";
          std::cout << "\e[0m";
        }
      }
      //Mostrar (pos: j)
      if(pos_j != -2)
        std::cout << "j = " << pos_j << "\n";
    }

    template<class Clave>
    std::vector<Clave> Insercion(std::vector<Clave> sec, int n)
    {
      //Algoritmo de Insercion
      int i,j;
      Clave aux;
      for(i = 1; i < n; i++)
      {
        aux = sec[i];
        //Pulsar Enter para reanudar la ejecucion del programa
        if(mode == 1)
        {
          getchar();
          print(sec, i, -2);
        }
        j = i-1;
        while (j >= 0 && sec[j] > aux)
        {
          sec[j+1] = sec[j];
          j--;
        }
        sec[j+1] = aux;
        if(mode == 1)
        {
          print(sec, -2, j+1);
        }
      }
      //Retornamos la secuencia ordenada
      return sec;
    }
  }
}

#endif
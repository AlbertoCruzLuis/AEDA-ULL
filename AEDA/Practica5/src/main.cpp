//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: main.cpp
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#include "Demostracion/demostracion.cpp"
#include "Estadistica/estadistica.cpp"

int mode;

int main()
{
  std::cout << "-------------------------------------\n";
  std::cout << "| Practica 5: Metodos de Ordenacion |\n";
  std::cout << "-------------------------------------\n";
  std::cout << "Modo: 1.Demostracion\t2.Estadisticas\n";
  std::cout << "Modo: ";
  std::cin >> mode;
  while(mode != 1 && mode != 2)
  {
    std::cout << "Error\nIntroducir modo 1 o 2: ";
    std::cin >> mode;
  }
  switch (mode)
  {
    // Programa A: Mostrar el funcionamiento del algoritmo
    case 1: demostracion();
      break;
    // Programa B: Analizar el rendimiento del algoritmo
    case 2: estadistica();
      break;
  }
}
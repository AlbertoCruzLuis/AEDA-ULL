//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: main.cpp
//@Version: Práctica 6 - ​​ Implementación de un árbol binario de búsqueda
//=======================================================================

#include "Demostracion/Demostracion.cpp"
#include "Estadistica/Estadisticas.cpp"

int mode;

int main()
{
  std::cout << "-----------------------------------------------\n";
  std::cout << "| Practica 6: Arbol Binario de Busqueda (ABB) |\n";
  std::cout << "-----------------------------------------------\n";
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
    // Programa A: Mostrar el funcionamiento del ABB
    case 1: demostracion();
      break;
    // Programa B: Analizar el rendimiento del ABB
    case 2: estadistica();
      break;
  }
}
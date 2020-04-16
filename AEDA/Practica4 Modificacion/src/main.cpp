//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: main.cpp
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#include "../include/Tabla.h"
#include "../include/Dni.h"
#include <iostream>
#include <vector>
#include <map>
#include "../include/Celda.h"
#include "../include/Contador.h"
#include "../include/DatosEstaditicos.h"

int main()
{
  //Parametros para crear la tabla Hash
  int nCeldas;
  int nClaves;

  //Solicitar los parametros para crear la tabla Hash
  std::cout << "Introducir Numero de Celdas: ";
  std::cin >> nCeldas;
  std::cout << "Introducir NUmero de Claves: ";
  std::cin >> nClaves;

  //Guardar Tipo de Funcion de Dispersion en un mapa
  std::map<int,std::string> Dispersion = {
    {0,"Modulo"},
    {1,"Suma"},
    {2,"Pseudoaleatoria"},
    {3,"Suma2Plegado"}
  };
  int tipoFDispersion;   //Tipo de Funcion de Dispersion
  std::cout << "Elegir una Funcion de Dispersion\n";
  std::cout << "Modulo: 0\tSuma: 1\tPseudoaleatoria: 2\tSuma2Plegado: 3\n";
  std::cout << "Tipo: ";
  std::cin >> tipoFDispersion;
  //Comprobar si la clave se encuentra en el mapa
  auto itD = Dispersion.find(tipoFDispersion);
  while(itD == Dispersion.end())
  {
    std::cout << "Error" << "\nTipo: ";
    std::cin >> tipoFDispersion;
    itD = Dispersion.find(tipoFDispersion);
  }

  //Guardar Tipo de Funcion de Exploracion en un mapa
  std::map<int,std::string> Exploracion = {
    {0,"Lineal"},
    {1,"Cuadratica"},
    {2,"Dispersion Doble"},
    {3,"Rehashing"}
  };
  int tipoFExploracion;   //Tipo de Funcion de Exploracion
  std::cout << "Elegir una Funcion de Exploracion\n";
  std::cout << "Lineal: 0\tCuadratica: 1\tDispersion Doble: 2\tRehashing: 3\n";
  std::cout << "Tipo: ";
  std::cin >> tipoFExploracion;
  //Comprobar si la clave se encuentra en el mapa
  auto itE = Exploracion.find(tipoFExploracion);
  while(itE == Exploracion.end())
  {
    std::cout << "Error" << "\nTipo: ";
    std::cin >> tipoFExploracion;
    itE = Exploracion.find(tipoFExploracion);
  }

  //Pedir Funcion de Dispersion
  //Pedir Funcion de Exploracion

  //Parametros del experimento
  double factor;     //Valor entre [0...1]
  int nPruebas;

  //Solicitar los parametros del experimento
  std::cout << "Introducir el factor de carga entre [0..1]: ";
  std::cin >> factor;
  while(factor < 0 || factor > 1)
  {
    std::cout << "Error\nIntroducir el factor de carga entre [0..1]: ";
    std::cin >> factor;
  }
  std::cout << "Introducir el Numero de Pruebas: ";
  std::cin >> nPruebas;

  //Crear un banco de prueba
  //2*N Valores Tipo Dni Random
  //Tamaño banco de pruebas
  int N = factor * nCeldas * nClaves;
  // Cremos el Banco de Pruebas
  //std::vector<AEDA::Dni> banco_pruebas(N);
  std::vector<AEDA::Dni> banco_pruebas(2*N);
  //Instanciamos de forma aleatoria los datos del banco de pruebas
  srand(0);
  for(int i = 0; i < banco_pruebas.size(); i++)
  {
    banco_pruebas[i] = AEDA::Dni(rand());
    //std::cout << banco_pruebas[i] << "\n";
  }

  //Crear Tabla Hash e insertar los N valores obtenidos del Banco de Pruebas
  AEDA::Tabla<AEDA::Dni> tabla(nCeldas, nClaves, tipoFDispersion, tipoFExploracion);

  //Insertar en la tabla los N primeros valores del banco
  for(int i = 0; i < N; i++)
  {
    tabla.Insertar(banco_pruebas[i]);
  }

  //Valores para el experimento
  //Capacidad de la Tabla: 100, 1000 y 10000
  //Factores de carga: 0.3 0.5 0.7 0.8 0.9 

  //1) Experimento Operacion Busqueda
  //Creamos el contador puesto a 0
  AEDA::Contador contador;
  //Realizar nPruebas iteraciones y buscar aleatoreamente en la tabla hash
  for(int i = 0; i < nPruebas; i++)
  {
    std::cout << "Experimento Busqueda\n";
    if(tabla.Buscar(banco_pruebas[rand() % N]))
    {
      contador.inc_vector();
      AEDA::Contador::nComparaciones = 0;
    }
  }
  //Mostar los valores del vector para comprobaciones
  // for(auto i : AEDA::Contador::v_comparacion)
  //   std::cout << "IterClave: " << i << "\n";

  //Hallamos los datos de min ,max ,media a partir de los datos recogidos
  //Para el experimento de Busqueda
  AEDA::DatosEstaditicos datos_busqueda(contador.v_comparacion);
  //Reiniciamos el contador
  contador.reset();

  //2) Experimento Operacion Insercion
  //Buscar las nPruebas aleatorimente de las utimas N claves no insertadas
  for(int i = 0; i < nPruebas; i++)
  {
    std::cout << "Experimento Insercion\n";
    if(tabla.Buscar(banco_pruebas[rand() %
      (banco_pruebas.size()-N) + N]))
      {
        contador.inc_vector();
        AEDA::Contador::nComparaciones = 0;
      }
  }
  //Hallamos los datos de min ,max ,media a partir de los datos recogidos
  //Para el experimento de Busqueda
  AEDA::DatosEstaditicos datos_insercion(contador.v_comparacion);
  //Reiniciamos el contador
  contador.reset();

  //Mostramos la Tabla Hash
  tabla.Mostrar();

  //3)Mostrar los Datos obtenidos
  std::cout << "+++++++++++++++++++++++++\n";
  std::cout << "| Datos del Experimento |\n"; 
  std::cout << "+++++++++++++++++++++++++\n";

  //Texto
  std::cout << "Celdas\tnClaves\t\tDispersion\t\tExploracion" <<
  "\t\tCarga\tPruebas\n";

  //Resultados
  std::cout << nCeldas << "\t" << nClaves << "\t\t" <<
  Dispersion[tipoFDispersion] << "\t\t\t" << Exploracion[tipoFExploracion] << "\t\t" <<
  factor << "\t" << nPruebas << "\n\n";

  //Texto
  std::cout << "           " <<
  "Minimo\t\tMedio\t\tMaximo\t\tTotal\n";
  std::cout << "Busquedas";

  //Resultados Busquedas
  std::cout << "\t" << datos_busqueda.min() << "\t\t" <<
  datos_busqueda.media() << "\t\t" <<
  datos_busqueda.max() << "\t\t" <<
  datos_busqueda.total() << "\n";

  //Texto
  std::cout << "Insercion";
  
  //Resultados Insercion
  std::cout << "\t" << datos_insercion.min() << "\t\t" <<
  datos_insercion.media() << "\t\t" <<
  datos_insercion.max() << "\t\t" <<
  datos_insercion.total() << "\n";
  
  return 0;
}
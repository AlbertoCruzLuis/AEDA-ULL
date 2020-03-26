//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: tablero.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "tablero.h"

AEDA::Tablero::Tablero(int n, int m) :
n_(n),
m_(m)
{
  //Se crea un vector puntero para que cada vector en la matriz 
  //tenga diferente direcciones de memoria
  std::vector<Celula*> *aux;
  for(int i = 0; i < n+2; i++)
  {
    aux = new std::vector<Celula*>;
    for(int j = 0; j < m+2; j++)
    {
      aux->push_back(new Celula(std::make_pair(i,j)));
    }
    malla_.push_back(aux);
  }
}

AEDA::Tablero::~Tablero()
{
  for(int i = 0; i < n_+2; i++)
  {
    for(int j = 0; j < m_+2; j++)
    {
      delete malla_[i]->data()[j];
    }
  }
}

void AEDA::Tablero::poner_celula(int n, int m, int type)
{
  //Colocar las celulas en el tablero
  //1) Destruimos la celula que habia
  delete malla_[n]->data()[m];
  //2)Creamos la nueva celula
  malla_[n]->data()[m] = Celula::create_celula(type, n, m);
}

void AEDA::Tablero::rellenar_tablero()
{
  int type,i,j,mode = 1;
  while(mode)
  {
    std::cout << "Introducir Tipo de Celula: [1,2,3]\n";
    std::cin >> type;

    std::cout << "Introducir Posicion de la Celula Viva\n";
    std::cout << "Disponibles Columnas[1-" << n_ << "] Filas[1-" << m_ << "]\n";

    std::cout << "POS: ";
    std::cin >> i >> j;
    if((i <= 0 || i > n_) || j <= 0 || j > m_)
    {
      std::cout << "Posicion Incorrecta\n"
      << "Volver a Introducir una Posicion Disponible\n";
    }else
    {
      poner_celula(i,j,type);
      std::cout << "Pulse 0 para dejar de rellenar el tablero\n"
      << "Pulse 1 para Continuar rellenando el tablero\n";
      std::cin >> mode;
    }
  }
}

void AEDA::Tablero::random_tablero()
{
  //Inicializar a null para que la sucesion de numeros sea aleatoria
  srand(time(NULL));
  //Generar la cantidad de celulas a crear
  int numero_celulas = rand() % (n_ * m_) + 1;

  //Creamos un vector de parejas para almacenar las posiciones creadas
  //Hacemos esto para evitar que se repitan las posiciones aleatoriamente
  std::vector<std::pair<int, int>> pos_random;

  //Generamos la posicion aleatoria de la celula
  //std::cout << numero_celulas << "\n";
  while(numero_celulas--)
  {
    int i = rand() % n_ + 1;
    int j = rand() % m_ + 1;
    //std::cout << "V[" << i << j << "]  ";
    for(auto p : pos_random)
      while(p.first == i && p.second == j)
      {
        //std::cout << "Repetido" << "\n";
        i = rand() % n_ + 1;
        j = rand() % m_ + 1;
        //std::cout << "[" << i << j << "]\n";
      }

    //Generar el Tipo de Celula (nunca de tipo 0)
    int type = rand() % 3 + 1;
    
    poner_celula(i,j,type);
    pos_random.push_back(std::make_pair(i,j));
  }
  //std::cout << "\n";
}

void AEDA::Tablero::update()
{
  //Contar vecinas de cada celula del Tablero
  for(int i = 1; i < n_+1; i++)
    for(int j = 1; j < m_+1; j++)
    {
      //1) Contar sus vecinas y guardarlas
      get_malla()[i]->data()[j]->contar_vecinas(*this);
    }
  //Actulizar estado de cada celula del Tablero
  for(int i = 1; i < n_+1; i++)
    for(int j = 1; j < m_+1; j++)
    {
      //2) Actualizar su estado y creas el tipo de celula
      //Guardamos el estado a actualizar antes de elimiarla
      int siguiente_estado = get_malla()[i]->data()[j]->actualizar_estado();
      //Elimanamos la celula 
      delete malla_[i]->data()[j];
      //Creamos la nueva celula
      malla_[i]->data()[j] = Celula::create_celula(siguiente_estado, i, j);
    }
}

void AEDA::Tablero::contar_tipos_celulas()
{
  //Creamos un vector para guardar la cantidad de celulas de cada tipo
  std::vector<int> tipo(4);
  //Recorremos cada celula del tablero
  for(int i = 1; i < n_+1; i++)
    for(int j = 1; j < m_+1; j++)
    {
      //Contar cuantas celulas hay de cada tipo
      for(int k = 0; k < tipo.size(); k++)
        if(malla_[i]->data()[j]->get_Estado() == k)
          tipo[k]++;
    }

  for(int i = 0; i < tipo.size(); i++)
    std::cout << "Tipo " << i << ": " << tipo[i] << "\n";
}

void AEDA::Tablero::print(std::ostream& os)
{
  for(int i = -1; i <= n_+2; i++)
  {
    for(int j = -1; j <= m_+2; j++)
    {
      //Colocar un marco exterior
      if((j == -1) || (j == m_+2))
        os << "║";
      else if((i == -1) || (i == n_+2))
        os << "≡";
      else
        malla_[i]->data()[j]->print(os);
    }
    os << "\n";
  }
}
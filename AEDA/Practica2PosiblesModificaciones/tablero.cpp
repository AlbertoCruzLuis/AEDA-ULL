//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: tablero.h
//@Version: Práctica 2 - El juego de la Vida
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
      aux->push_back(new Celula(0,std::make_pair(i,j)));
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

void AEDA::Tablero::poner_celula_viva(int n, int m)
{
  //Al tener un vector puntero necesitamos acceder al dato
  malla_[n]->data()[m]->set_Estado(1);
}

void AEDA::Tablero::rellenar_tablero()
{
  std::cout << "Introducir Posicion de la Celula Viva\n";
  std::cout << "Disponibles Columnas[1-" << n_ << "] Filas[1-" << m_ << "]\n";

  int i,j,mode = 1;
  while(mode)
  {
    std::cout << "POS: ";
    std::cin >> i >> j;
    if((i <= 0 || i > n_) || j <= 0 || j > m_)
    {
      std::cout << "Posicion Incorrecta\n"
      << "Volver a Introducir una Posicion Disponible\n";
    }else
    {
      poner_celula_viva(i,j);
      std::cout << "Pulse 0 para dejar de rellenar el tablero\n"
      << "Pulse 1 para continuar rellenando el tablero\n";
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

  //Generamos la posicion aleatoria de la celula
  while(numero_celulas--)
  {
    int i = rand() % n_ + 1;
    int j = rand() % m_ + 1;
    poner_celula_viva(i,j);
  }
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
      //2) Actualizar su estado
      get_malla()[i]->data()[j]->actualizar_estado();
    }
}

int AEDA::Tablero::maximo_vecinos()
{
  //Calcular el numero maximo de vecinos

  int max = 0;

  for(int i = 1; i < n_+1; i++)
    for(int j = 1; j < m_+1; j++)
    {
       if(get_malla()[i]->data()[j]->contar_vecinas(*this)  > max)
        max = get_malla()[i]->data()[j]->contar_vecinas(*this);
    }
  return max;
}

int AEDA::Tablero::celulas_vivas()
{
  int vivas = 0;

  //Cantidad de celulas vivas en un turno
  for(int i = 1; i < n_+1; i++)
    for(int j = 1; j < m_+1; j++)
    {
      if(malla_[i]->data()[j]->get_Estado())
        vivas++;
    }
  std::cout << "Celulas vivas: " << vivas << "\n";
  return vivas;
}

bool AEDA::Tablero::comparar_patron(
  std::vector<std::pair<int,int>> previous_vivas)
{
  //Comparamos el vector de las posiciones de las celulas vivas 
  //del turno anterior con el de este turno 
  // Si son iguales retornamos true sino false
  std::vector<std::pair<int,int>> pos_vivas;
  pos_vivas = almacenar_patron();
  if(previous_vivas.size() != pos_vivas.size())
    return false;
  for(int i = 0; i < previous_vivas.size(); i++)
  {
    if(previous_vivas[i].first != pos_vivas[i].first ||
    previous_vivas[i].second != pos_vivas[i].second)
      return false;
  }
  return true;
}

std::vector<std::pair<int,int>> AEDA::Tablero::almacenar_patron()
{
  //Almacenamos las posiciones de la celulas vivas en un vector
  std::vector<std::pair<int,int>> pos_vivas;
  for(int i = 1; i < n_+1; i++)
    for(int j = 1; j < m_+1; j++)
    {
       if(get_malla()[i]->data()[j]->get_Estado())
        pos_vivas.push_back(std::make_pair(i,j));
    }
  return pos_vivas;
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
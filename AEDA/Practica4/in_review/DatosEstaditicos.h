//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: DatosEstadisticos.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef DATOS_ESTADISTICOS_H
#define DATOS_ESTADISTICOS_H

namespace AEDA
{

class DatosEstaditicos
{
  public:
    DatosEstaditicos();
    ~DatosEstaditicos();
    int get_nComparaciones();
    int get_maxComparaciones();
    void Incremento();
    void max();

  private:
    int nComparaciones_;
    int maxComparaciones_;
};

}

#endif

//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: queue.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "queue.h"

int main(void)
{
    AEDA::queue<int> A(5);
    AEDA::queue<char> B(5);
    AEDA::queue<int> C(5);
    for( int i = 0; i < A.get_size(); i++ )
    {
        A.push(i);
        B.push('a' + i);
        C.push(i*i);
        std::cout << C.front() << " - ";
    }
    A.write();
    B.write();
    C.write();
    A.pop();
    A.write();
    A.push(40);
    A.write();
    return 0;
}

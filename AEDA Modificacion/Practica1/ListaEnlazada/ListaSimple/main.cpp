//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: main.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "sll_node.h"
#include "sll.h"

int main()
{
    AEDA::sll<int> List_A;
    for(int i = 0; i < 6; i++)
        List_A.insert_head(new AEDA::sll_node<int>(i));
    List_A.write();
    std::cout << "Tamaño de la Lista: " << List_A.size() << "\n";
    AEDA::sll_node<int>* nodo = List_A.extract_head();
    std::cout << "Tamaño de la Lista: " << List_A.size() << "\n";
    std::cout << "Dato del nodo Extraido: " <<nodo->get_data() << "\n";
    delete nodo;

    AEDA::sll<char> List_B;
    AEDA::sll_node<char>* letter_a = new AEDA::sll_node<char>('a');
    List_B.insert_head(letter_a);
    for(int i = 0; i < 4; i++)
    {
        List_B.insert_after(letter_a,new AEDA::sll_node<char>('c' + i));
    }
    List_B.write();
    std::cout << "Resultado de la Busqueda: " << List_B.search('d');
    return 0;
}
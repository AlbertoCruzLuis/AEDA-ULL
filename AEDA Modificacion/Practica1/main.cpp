#include <iostream>
#include "./Vector/vector.h"
#include "./ListaEnlazada/ListaSimple/sll.h"

struct Profesor
{
    //Identificar y nombre del profesor
    std::string dni;
    std::string name;
};

struct Asignatura
{
    //Codigo,Nombre y Lista de Profesores de la Asignatura
    std::string cod;
    std::string name;
    AEDA::sll<Profesor> list_profesores;

};

void ver_profesorado(AEDA::vector<Asignatura>&, std::string);

int main()
{
    //Modificacion
    //Creamos un Profesor 1
    Profesor profe;
    profe.dni = "45678978";
    profe.name = "Jose Ignacio";

    //Creamos un Profesor 2
    Profesor profe2;
    profe.dni = "456778888";
    profe.name = "Felipe";

    //Ahora metemos el Profesor en el nodo
    AEDA::sll_node<Profesor> *node_profesor = new AEDA::sll_node<Profesor>;
    
    //Creamos una vector de Asignaturas
    AEDA::vector<Asignatura> Asignaturas(2);

    //1 Asigantura matematicas
    //Asignaturas.resize(1);
    Asignaturas[0].cod = "01";
    Asignaturas[0].name = "Matematicas";
    Asignaturas[0].list_profesores.insert_head(node_profesor);
    node_profesor->set_data(profe2);
    //2 Asignatura
    //Asignaturas.resize(2);
    Asignaturas[1].cod = "02";
    Asignaturas[1].name = "Lengua";
    Asignaturas[1].list_profesores.insert_head(node_profesor);
    node_profesor->set_data(profe);

    ver_profesorado(Asignaturas, "02");

    return 0;
}

void ver_profesorado(AEDA::vector<Asignatura> &v, std::string cod)
{
    for(int i = 0; i < v.get_size(); i++)
    {
        //Mostrar la lista de profesores para cada asignatura
        if(cod == v[i].cod)
            v[i].list_profesores.write();
    }    
}
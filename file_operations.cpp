#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "menu_txts.h"

void write_person_with_format(const std::string &Ruta, const std::vector<Persona> & P){
    std::ofstream PersonFile;

    // PersonFile.open(Ruta, ios_base::app); //hacer append
    PersonFile.open(Ruta); //sobreescribir el archivo

    for (int i = 0; i < P.size(); ++i){
        PersonFile << P[i].matricula <<" , " <<  P[i].name << " , " << P[i].fecha_nacimineto << " , " << P[i].telefono << " , " << P[i].domicilio;
        PersonFile << std::endl;
    }
    PersonFile.close();
}


void formato_servidor(std::vector<Persona> &P, const std::vector<std::string> &A){

    Persona new_person;
    std::string name;
    std::string domicio;
    new_person.matricula = A[0];
    int i = 2;
    // while(true){
    //     if (A[i + 1] == ",")
    //         break;
    //     else{
    //         if (A[i + 1] == ",")
    //             name.append(A[i]);
    //         else{
    //             name.append(A[i]);
    //             name.append(" ");
    //         }
    //         ++i;
    //     }
    // }
    name = A[i];
    new_person.name = name;
    new_person.fecha_nacimineto = A[i + 2];
    new_person.telefono = A[i + 4];
    for (i += 6; i < A.size(); ++i){
        domicio.append(A[i]);
        domicio.append(" ");
    }
    new_person.domicilio = domicio;

    P.push_back(new_person);


}




// void add_person_from_file(std::vector<Persona>&P, const std::vector<std::string> &A){
    
//     Persona new_person;
//     std::string name;
//     std::string domicilio;
//     int i = 3;
//     while (true){
//         if (A[i] == "Age:")
//             break;
//         else{
//             if (A[i + 1 ] == "Age:")
//                 name.append(A[i]);
//             else{
//                 name.append(A[i]);
//                 name.append(" ");
//             }
//             ++i;
//         }
//     }
//     new_person.matricula = A[1];
//     new_person.name = name;
//     new_person.age = stoi(A[i + 1]);
//     new_person.telefono = A[i + 3];

//     for (i += 5; i < A.size(); ++i){
//         domicilio.append(A[i]);
//         domicilio.append(" ");
//     }
//     new_person.domicilio = domicilio;

//     P.push_back(new_person);

// }

void read_person(const std::string &Ruta, std::vector<Persona> &P){

    std::vector<std::string> temp;
    
    std::ifstream PersonFile;
    PersonFile.open(Ruta, std::ifstream::in);

    if (!PersonFile.is_open())
        std::cout << "No pude abrir el archivo" << std::endl;
    
    std::string line;
    while(getline(PersonFile, line)){
        temp = splitted_by_char(line);
        formato_servidor(P, temp);
        temp.clear();

    }

    PersonFile.close();
}
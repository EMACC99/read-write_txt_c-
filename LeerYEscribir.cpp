#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <list>
#include "menu_txts.h"

using namespace std;

/* 
@ Ya Esta listo creo
*/

void print_struct(const vector <Persona> &P){
    for (int i = 0; i < P.size(); ++i)
        cout << i+1 <<" Matricula: " << P[i].matricula <<" Name: " << P[i].name << " Age: " << P[i].fecha_nacimineto << " telefono: " << P[i].telefono << " domicilio: " << P[i].domicilio;
        cout << std::endl;
}

void add_person(vector<Persona> &P){

    Persona new_person;
    cout << "Matricula: " << endl;
    cin.ignore();
    getline(cin ,new_person.matricula);
    cout << "Nombre de la persona: " << endl;
    getline(cin, new_person.name);
    cout << "Edad de la persona" << endl;
    cin >> new_person.fecha_nacimineto;
    cout << "Telefono: " << endl;
    cin >> new_person.telefono;
    cout << "Domicilio: " << endl;
    cin >> new_person.domicilio;
    P.push_back(new_person);
    
}


void remove_person(const int &pos, vector <Persona> &P){
    P.erase(P.begin() + pos);
}

std::list<Persona> pasar_de_vector_a_lista(const std::vector<Persona> &P){
    std::list<Persona> LP (P.begin(), P.end());
    return LP;
}

int main(){

    vector <Persona> P;
    string Ruta;
    Ruta = nombre_archivo();
    read_person(Ruta, P); //Leer del archivo
    
    int option = -1;
    while (option != 4){
        option = menu();
        switch (option){
            case 0:
                print_struct(P);
                break;
            case 1:
                int n;
                cout << "Número de Personas que desea añadir" << endl;
                cin >> n;
                for (int i = 0; i<n; ++i)
                    add_person(P);
                break;

            case 2:
                print_struct(P);
                int pos;
                cout << "Indice que quieres eliminar" << endl;
                cin >> pos;
                remove_person(pos - 1, P);
                break;

            case 3:{
                string matri;
                cout << "Matricula que desea buscar: " << endl;
                cin.ignore();
                getline(cin ,matri);
                int indice = buscar_matricula(matri, P);
                if (indice == -1)
                    cout << "Matricula no encontrada" << endl;
                else{
                    cout << "El indice de la matricula es " << indice + 1 << endl;
                    cout << indice+1 <<" Matricula: " << P[indice].matricula <<" Name: " << P[indice].name << " Age: " << P[indice].fecha_nacimineto << " telefono: " << P[indice].telefono << " domicilio: " << P[indice].domicilio;
                    cout << std::endl;
                }
                    
                break; 
            }
            case 4:
                cout << "saliendo..." << endl;
                break;

            default:
                cout << "opcion incorrecta" << endl;
                break;
        }
    }
    write_person_with_format(Ruta, P);
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include"menu_txts.h"


int menu(){
    
    int choice;

    std::cout << "Programa para leer y escribir txt's" << std::endl;
    std::cout << "Que decea hacer?" << std::endl;
    std::cout << "1.- Ver lista de personas" << std::endl;
    std::cout << "2.- Añadir persona" << std::endl;
    std::cout << "3.- Quitar Persona" << std::endl;
    std::cout << "4.- Buscar por matricula" << std::endl;
    std::cout << "5.- salir" << std::endl;
    std::cin >> choice;
    
    return choice - 1;

}

std::string nombre_archivo(){
    std::string Ruta;
    std::cout << "Nombre del archivo" << std::endl;
    std::cin >> Ruta;

    return Ruta;

}


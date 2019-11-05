#include <string>
#include<vector>

struct Persona{
    int age;
    std::string matricula;
    std::string name;
    std::string telefono;
    std::string domicilio;
};


int menu();
std::string nombre_archivo();
std::vector<std::string> splitted_by_char(std::string &str);
int buscar_matricula(std::string &matricula, std::vector<Persona> &P);
void write_person_with_format(const std::string &Ruta, const std::vector<Persona> & P);
void add_person_from_file(std::vector<Persona>&P, const std::vector<std::string> &A);
void read_person(const std::string &Ruta, std::vector<Persona> &P);
#include <vector>
#include <string>
#include "menu_txts.h"

int buscar_matricula(std::string &matricula, std::vector<Persona> &P){
    for (int i = 0; i < P.size(); ++i){
        if(P[i].matricula == matricula)
            return i;
    }
    return -1;
}
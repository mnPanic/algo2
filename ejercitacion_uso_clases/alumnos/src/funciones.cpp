#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1

bool __contiene(vector<int> s, int elem) {
    bool contiene = false;

    for(int otro : s) {
        if (otro == elem) {
            contiene = true;
            break;
        }
    }

    return contiene;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> s_sin_rep;

    for(int elem : s) {
        if(!__contiene(s_sin_rep, elem)){
            s_sin_rep.push_back(elem);
        }
    }

    return s_sin_rep;
}

// Ejercicio 2
vector<int> __set_to_vector(set<int> s) {
    vector<int> res;

    for (int elem : s) {
        res.push_back(elem);
    }

    return res;
}

set<int> __vector_to_set(vector<int> s) {
    set<int> res;

    for (int elem : s) {
        res.insert(elem);
    }

    return res;
}

vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res = __set_to_vector(__vector_to_set(s));

    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool mismos = true;
    for(int elem : a) {
        if(!__contiene(b, elem)) {
            mismos = false;
            break;
        }
    }

    return mismos;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return __vector_to_set(a) == __vector_to_set(b);
}

// Ejercicio 5
int __apariciones(int elem, vector<int> s) {
    int ap = 0;

    for(int otro : s) {
        if(otro == elem) {
            ap++;
        }
    }

    return ap;
}

map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;

    for(int elem : s) {
        res[elem] = __apariciones(elem, s);
    }

    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;

    map<int, int> apariciones = contar_apariciones(s);

    for(pair<int, int> p : apariciones) {
        int elem = p.first;
        int ap = p.second;

        if (ap == 1) {
            res.push_back(elem);
        }
    }

    return res;
}

// Ejercicio 7
bool __contiene(set<int> s, int elem) {
    for(int otro : s) {
        if (otro == elem) {
            return true;
        }
    }

    return false;
}
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int elem : a) {
        if(__contiene(b, elem)){
            res.insert(elem);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;

    for(int elem : s) {
        res[elem % 10].insert(elem);
    }

    return res;
}

// Ejercicio 9
char __obtener_traduccion(char c, vector<pair<char, char>> tr) {
    // Si no encuentro traducción devuelvo el mismo
    char traduccion = c;
    for (pair<char, char> entry : tr) {
        if (entry.first = c) {
            traduccion = entry.second;
        }
    }
    return traduccion;
}

vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> str_traducido;
    for (char c : str) {
        str_traducido.push_back(__obtener_traduccion(c, tr));
    }
    return str_traducido;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}

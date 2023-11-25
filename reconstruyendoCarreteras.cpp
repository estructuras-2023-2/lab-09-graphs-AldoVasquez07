#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<string, string> padre;

string buscar(const string& s) {
    if (padre.find(s) == padre.end())
        padre[s] = s;
    else if (padre[s] != s)
        padre[s] = buscar(padre[s]);
    return padre[s];
}

void unir(const string& a, const string& b) {
    string nodoA = buscar(a);
    string nodoB = buscar(b);
    if (nodoA != nodoB)
        padre[nodoA] = nodoB;
}

bool ciudadesConectadas(const string& a, const string& b) {
    return buscar(a) == buscar(b);
}

bool coneccionTotal(const vector<string>& ciudades) {
    if (ciudades.empty()) return true;
    string nodo = buscar(ciudades.front());
    for (const auto& ciudad : ciudades) {
        if (buscar(ciudad) != nodo) return false;
    }
    return true;
}

struct Carretera {
    string id;
    string ciudad1;
    string ciudad2;
    int costo;

    Carretera(const string& i, const string& c1, const string& c2, int co = -1) : id(i), ciudad1(c1), ciudad2(c2), costo(co) {}
};

vector<string> dividir(const string& str, char delim) {
    vector<string> tok;
    size_t inicio = 0;
    size_t fin = str.find(delim);
    while (fin != string::npos) {
        tok.push_back(str.substr(inicio, fin - inicio));
        inicio = fin + 1;
        fin = str.find(delim, inicio);
    }
    tok.push_back(str.substr(inicio));
    return tok;
}

string reconstruye(const vector<string>& carreteras) {
    vector<Carretera> todasCarreteras;
    vector<string> todasCiudades;
    set<string> carreterasReconstruir;

    for (const auto& carreteraStr : carreteras) {
        auto tok = dividir(carreteraStr, ' ');
        todasCiudades.push_back(tok[1]);
        todasCiudades.push_back(tok[2]);

        if (tok.size() == 4) {
            todasCarreteras.emplace_back(tok[0], tok[1], tok[2], stoi(tok[3]));
        } else {
            unir(tok[1], tok[2]);
        }
    }

    for (const auto& carretera : todasCarreteras) {
        if (!ciudadesConectadas(carretera.ciudad1, carretera.ciudad2)) {
            unir(carretera.ciudad1, carretera.ciudad2);
            carreterasReconstruir.insert(carretera.id);
        }
    }

    if (!coneccionTotal(todasCiudades)) {
        return "IMPOSIBLE";
    }

    string resultado;
    for (const auto& id : carreterasReconstruir) {
        resultado += id + " ";
    }

    return resultado.empty() ? "" : resultado.substr(0, resultado.length() - 1);
}


int main() {
    vector<string> descripcionesCarreteras = {"C1 Lima Trujillo 1", "C2 Tacna Trujillo", "C3 Tacna Arequipa"};;
    cout << reconstruye(descripcionesCarreteras);

    return 0;
}
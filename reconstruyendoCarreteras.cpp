#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, string> padre;

string buscar(const string& s) {
    if (padre.find(s) == padre.end())
        padre[s] = s;
    else if (padre[s] != s)
        padre[s] = buscar(padre[s]);
    return padre[s];
}

struct Carretera {
    string id;
    string ciudad1;
    string ciudad2;
    int costo;

    Carretera(const string& i, const string& c1, const string& c2, int co = -1) : id(i), ciudad1(c1), ciudad2(c2), costo(co) {}
};



string reconstruye(const vector<string>& carreteras) {
    vector<Carretera> todasCarreteras;
    vector<string> todasCiudades;
    set<string> carreterasReconstruir;
    
    
}

int main() {
    vector<String> carreteras = {"C1 Lima Trujillo 1", "C2 Tacna Trujillo", "C3 Tacna Arequipa"}
    cout << reconstruye(carreteras);

    return 0;
}

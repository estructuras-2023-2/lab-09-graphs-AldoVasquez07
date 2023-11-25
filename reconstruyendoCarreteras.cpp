#include <iostream>
#include <map>

using namespace std;

map<string, string> padre;

struct Carretera {
    string id;
    string ciudad1;
    string ciudad2;
    int costo;

    Carretera(const string& i, const string& c1, const string& c2, int co = -1) : id(i), ciudad1(c1), ciudad2(c2), costo(co) {}
};

int main() {
    cout<<"Hello World";

    return 0;
}

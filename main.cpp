#include "maquinadebusca.h"

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    MB a("./Documentos");
    string input;
    cout << "Olá, o que quer buscar?" << endl;
    getline(cin, input);
    set<string> documentos = a.Busque(input);
    cout << "O termo pesquisado se encontra em: " << endl;
    for(auto it = documentos.begin(); it != documentos.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
#include "maquinadebusca.h"

#include <fstream>
#include <filesystem>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

namespace fs = std::filesystem;

using namespace std;

MB::MB(string path){
    for (const auto & entry : fs::directory_iterator(path)){ 
        string plv;
        ifstream in;
        in.open(entry.path());
        while(in >> plv){
            string entryPath = entry.path();
            string nome = entryPath.substr((path.length() + 1), (entryPath.length() - path.length())); 
            MB_[Normalize(plv)].insert(nome);
        }
        in.close();
    }
}
set<string> MB::Busque(string input){
    int numplv = 0;
    set<string> encontradas;
    string plvs;
    stringstream stream(input);
    while(getline(stream, plvs, ' ')){
        encontradas.insert(Normalize(plvs));
        numplv++;
    } return Selecione(encontradas, numplv);  
}
set<string> MB::Selecione(set<string> encontradas, int numplv){
    map<string, int> docsantes;
    set<string> docsdepois;
    for(auto it1 = encontradas.begin(); it1 != encontradas.end(); it1++){ 
        if(MB_.find(*it1) != MB_.end()){ 
            for(auto it2 = (MB_.find(*it1)->second).begin(); it2 != (MB_.find(*it1)->second).end(); it2++){ 
                docsantes[*it2]++; 
            }
        }
    }
    for(auto it3 = docsantes.begin(); it3 != docsantes.end(); it3++){ 
        if (docsantes[it3->first] == numplv){ 
            docsdepois.insert(it3->first);
        }
    } return docsdepois;
}
vector<string> letras = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
    "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
bool MB::Letra(string str) { 
    for(int i = 0; i < letras.size(); i++) {
        if (letras[i] == str) {
            return true;
        }
    } return false;
}
string MB::Normalize(string texto) {
    string output = "";
    for (int i = 0; i < texto.length(); i++) { 
        string buffer = "";
        for (int j = 0; j < texto.length() - i; j++) {
            buffer += texto[i + j]; 
            
            if (Letra(buffer)) { 
                output += tolower(buffer[0]);
            } else if (buffer == "á" || buffer == "ã" || buffer == "à" || buffer == "â" || buffer == "ä" || buffer == "Á" || buffer == "Ã" || buffer == "À" || buffer == "Â" || buffer == "Ä") {
                output += 'a';
            } else if (buffer == "é" || buffer == "è" || buffer == "ê" || buffer == "ë" || buffer == "É" || buffer == "È" || buffer == "Ê" || buffer == "Ë") {
                output += 'e';
            } else if (buffer == "í" || buffer == "ì" || buffer == "î" || buffer == "ï" || buffer == "Í" || buffer == "Ì" || buffer == "Î" || buffer == "Ï") {
                output += 'i';
            } else if (buffer == "ó" || buffer == "õ" || buffer == "ò" || buffer == "ö" || buffer == "ô" || buffer == "Ó" || buffer == "Õ" || buffer == "Ö" || buffer == "Ò" || buffer == "Ô") {
                output += 'o';
            } else if (buffer == "ú" || buffer == "ù" || buffer == "û" || buffer == "ü" || buffer == "Ú" || buffer == "Ù" || buffer == "Û" || buffer == "Ü") {
                output += 'u';
            } else if (buffer == "ç" || buffer == "Ç") {
                output += 'c';
            }
        }
        buffer = "";
    } return output;
}
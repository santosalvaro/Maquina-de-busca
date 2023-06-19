#ifndef _MAQUINADEBUSCA_H_
#define _MAQUINADEBUSCA_H_

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

/* Cria uma máquina de busca que mapeia uma string
a um set de files.*/
class MB{
    private:
        map<string, set<string>> MB_; // Índice invertido.
    public:
        // Cria um índice invertido com os documentos do diretório.
        MB(string path);
        // Recebe uma lista de palavras e retorna os documentos encoontrados.
        set<string> Busque(string input);
        // Seleciona os documentos que possuem todas as palavras encontradas, organizando o mesmo.
        set<string> Selecione(set<string> encontradas, int numplv);
        //Normaliza as letras.
        bool Letra(string str);
        // Normaliza o texto.
        string Normalize(string input); 
};

#endif
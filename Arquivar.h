#include <iostream>
#include <string>
#include <fstream>
#include "Estoque.h"

#pragma once
//acho que estoque pode herdar de arquivo para poder usar os metodos na hora de inicializar o vetor
class Arquivar : public Estoque
{
protected:

public:
//isso deve abrir o arquivo
std::ifstream open(){
    std::ifstream is;
    is.open ("texto.txt", ios::in);
    //deve retornar o diretorio do arquivo que foi aberto
    return is;
}
//como o arquivo ja foi aberto, para escrever dentro dele basta chamar o arquivo e escrever dentro

//colocar isso dentro de um while (!ifstream.eof), dentro do metodo presente em estoque
std::string linha(ifstream is){
        std::string line;
        std::getline(is, line);
        return line;
}
//fechar o arquivo
void fclose(ifstream is){
    is.close();
}

};
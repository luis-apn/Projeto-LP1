#include <iostream>
#include <string>
#include <fstream>

#pragma once
//acho que estoque pode herdar de arquivo para poder usar os metodos na hora de inicializar o vetor
class Arquivar
{
protected:

public:
//isso deve abrir o arquivo
std::ifstream openEstoque(){
    std::ifstream is;
    is.open("estoque.txt", ios::in);
    //deve retornar o diretorio do arquivo que foi aberto
    return is;
}
std::ifstream openLog(){
    std::ifstream is;
    is.open("log.txt", ios::in);
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
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#pragma once
//acho que estoque pode herdar de arquivo para poder usar os metodos na hora de inicializar o vetor
class Arquivar{ 
protected:

public:
void  salvarEstoque();

void salvarlog(std::string s){
      ofstream log;
      
      //Abertura do arquivo para escrita 
      log.open("log.txt", ios::app);

      if(!log.is_open())
          cout << "ERRO AO ABRIR O LOG!\n";
      else{
        
        log << s << endl;
        log.close();
      }
    }

};

//Salvar o estoque no arquivo - Metodo sobrescrito em Estoque
void Arquivar::salvarEstoque(){}
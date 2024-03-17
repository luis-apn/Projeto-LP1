#include <iostream>
#include <string>
#include <fstream>
#include "Mercado.h"

using namespace std;

#pragma once
//acho que estoque pode herdar de arquivo para poder usar os metodos na hora de inicializar o vetor
class Arquivar : public Mercado{ 
protected:

public:
void virtual salvarEstoque();
void relatorio();

//Metodo para elaboracao do relatorio de registros dos acontececimentos no codigo
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

//EXIBE O TUDO QUE O
void Arquivar::relatorio(){

  string linha;
  ifstream relatorio("log.txt");

  //Leitura do conteudo do relatorio e expondo
  cout << "\n\n-----------------RELATORIO DE LOGS DO SISTEMA-----------------\n";
  if(relatorio.is_open()){
    while (!relatorio.eof()){
      getline(relatorio, linha);
      cout << linha << endl;
    }
  }
  else  
    cout << "ERRO AO ABRIR O ARQUIVO\n";
}
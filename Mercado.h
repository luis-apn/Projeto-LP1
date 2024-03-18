#include <iostream>
#include <string>
#include "Data.h"

using namespace std;
#pragma once

class Mercado {
  
public:

  //METODOS UTILIZADOS PARA SEREM SOBRESCRITOS DENTRO DAS SUBCLASSES
  void virtual cadastro(){}
  void virtual listarProdutos(){}
  void virtual alterarProduto(){}
  void virtual removerProduto(){}
  void virtual salvarEstoque(){}
  void virtual aberturaArquivo(){}
  void virtual compra(){}
  void virtual relatorio(){}

};
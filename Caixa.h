#include "Estoque.h"
#include "Produto.h"
#include "Mercado.h"

#pragma once
//caixa herda de estoque 
class Caixa : public Estoque {
public:

Caixa(){

aberturaArquivo();
}

//carrinho de compra
  float compra() {
    //salva antes de fazer a compra
    salvarEstoque();
    //std::ofstream log = openLog();
    int num;
    std::cout << "Digite o codigo do produto: ";
    int codigo;
    std::cin >> codigo;
    for (int i = 0; i < MAX_PRODUTOS; i++){
      if (p[i].getCodigo() == codigo){
        int qtd = p[i].getQtd();
        float preco = p[i].getPreco();
        
        std::cout << "Digite o numero de produtos a serem comprados: ";
        std::cin >> num;
       
        if (num <= qtd) { 
          std::cout << "Valor: R$ " <<(num * preco);
          std::stringstream ss;
          ss << "Valor: R$ " <<(num * preco);
          salvarlog(ss.str());

          qtd -= num;
          
          p[i].setQtd(qtd);
          salvarEstoque();
        } else {
          std::cout << "Não temos estoque suficiente para essa quantidade";
          salvarEstoque();
          return -1; //erro
        }
      }
    }
  }   
};
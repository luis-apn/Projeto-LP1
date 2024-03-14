#include "Estoque.h"
#include "Produto.h"
#include "Mercado.h"

#pragma once
//caixa herda de estoque 
class Caixa : public Estoque {
public:


//carrinho de compra
  float compra() {
    std::ifstream log = openLog();
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
        std::cout << (num * preco);
        std::cout << "Valor: R$" <<(num * preco);
        if (num <= qtd) { 
          qtd -= num;
          //nao sei o motivo de estar alertando erro, log deveria ser o local do arquivo a noite vemos como resolver isso
          if (log.is_open())
          {
            std::stringstream ss;
            ss << "Compra no valor de: R$" << (float)num * (float)preco << " realizada\n";
            log << ss.str();
          }
          
          p[i].setQtd(qtd);
        } else {
          std::cout << "Não temos estoque suficiente para essa quantidade";
          return -1; //erro
        }
      }
    }
  }
};
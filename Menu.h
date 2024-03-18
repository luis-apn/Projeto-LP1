#include "Estoque.h"
#include  "Produto.h"
#include "Caixa.h"
#include "Mercado.h"
#include "Arquivar.h"

using namespace std;

#pragma once

class Menu{
public:
  void exibir();
  
  
};

void Menu::exibir(){ 

  Mercado *registro[2];
  registro[1] = new Estoque();
  
  //ABRE O ARQUIVO DO ESTOQUE E INICIALIZA AS POSICOES DO VETOR DE PROTUDOS
  registro[1]->aberturaArquivo();

  while (true) {
      int op;
      
      // Interface basica para sistema
      cout << "\n-------------------SISTEMA---------------------";
      cout << "\n(1) - Cadastro de novos produtos";
      cout << "\n(2) - Listar produtos";
      cout << "\n(3) - Alterar produto registrado";
      cout << "\n(4) - Remover produto";
      cout << "\n(5) - Registrar venda";
      cout << "\n(6) - Exibir Relatorio";
      cout << "\n(7) - Sair";
      cout << "\nDigite a opcao desejada: ";
      cin >> op;

      switch (op) {
        case 1: 
          registro[1]->cadastro();
          registro[1]->salvarEstoque();
          break;
        case 2:
          registro[1]->listarProdutos();
          break;    
        case 3:
          registro[1]->alterarProduto();
          registro[1]->salvarEstoque();
          break; 
        case 4:
          registro[1]->removerProduto();
          registro[1]->salvarEstoque();
          break;
        case 5:
          registro[2]  = new Caixa();
          registro[2]->compra();
          registro[1]->aberturaArquivo();
          break;
        case 6:
          registro[2] = new Arquivar();
          registro[2]->relatorio();
          break;

        case 7: 
          registro[1]->salvarEstoque();
          break;

      default:
        cout << "\nOPCAO INVALIDA!\n\n";
        break;
      }

    //TESTE DE CONDICAO DE SAIDA
    if (op == 7) {
      cout << "\n\nFINALIZANDO...";
      break;
    }
  }
}
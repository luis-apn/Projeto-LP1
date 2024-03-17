#include "Estoque.h"
#include  "Produto.h"
#include "Caixa.h"
#include "Mercado.h"
#include "Arquivar.h"
#include "Menu.h"

int main() {

  /*Estoque registro;
  Arquivar salvar;

  //ABRE O ARQUIVO DO ESTOQUE E INICIALIZA AS POSICOES DO VETOR DE PROTUDOS
  registro.aberturaArquivo();

  while (true) {
      int op;
      
      // Interface basica para sistema
      cout << "\n-------------------SISTEMA---------------------";
      cout << "\n(1) - Cadastro de novos produtos";
      cout << "\n(2) - Listar todos os itens cadastrados";
      //cout << "\n(3) - Exibir quantidade dos produto por nome";
      cout << "\n(4) - Alterar produto registrado";
      cout << "\n(5) - Remover produto";
      cout << "\n(6) - Exibir Relatorio";
      cout << "\n(7) - Sair";
      cout << "\nDigite a opcao desejada: ";
      cin >> op;

      switch (op) {
        case 1: 
          registro.cadastro();
          break;
        case 2:
          registro.listarProdutos();
          break;    
        case 4:
          registro.alterarProduto();
          break; 
        case 5:
          registro.removerProduto();
          break;
          
        
      case 7: 
        registro.salvarEstoque();
        break;

      default:
        cout << "\n\nOPCAO INVALIDA!\n";
        break;
      }

    //TESTE DE CONDICAO DE SAIDA
    if (op == 7) {
      cout << "\n\nFINALIZANDO...";
      break;
    }
  }*/
  Menu m;
  m.exibir();

  return 0;
}
#include <iostream>
#include <string>
#include "Caixa.h"
using namespace std;

#pragma once

class Menu : public Caixa{
public:
  
  void interface(){
    while (true) {
      int op;
      
      // Interface basica para sistema
      cout << "\n-------------------SISTEMA---------------------";
      cout << "\n(1) - Cadastro de novos produtos";
      cout << "\n(2) - Listar todos os itens cadastrados";
      cout << "\n(3) - Exibir quantidade dos produto por nome";
      cout << "\n(4) - Alterar produto registrado";
      cout << "\n(5) - Remover produto";
      cout << "\n(6) - Exibir Relatorio";
      cout << "\n(7) - Sair";
      cout << "\nDigite a opcao desejada: ";
      cin >> op;

      switch (op) {
        case 1: 
          Estoque::cadastro();
        
        case 2:
          std::cout << "Voce deseja lista por tipo (1), por nome(2), todos(3): ";
          int opt;
          std::cin >> opt;
          switch (opt){
            case 1:
              int a;
              cin >> a;
              Estoque::listarProdutos(a);
            
          }   
          std::cout << "Digite o tipo";
           
        case 3:
          
      case 7: 
        break;

      default:
        break;
      

      if (op == 7) {
        cout << "\n\nFINALIZANDO...";
        break;
        }
    }
  }
}
};


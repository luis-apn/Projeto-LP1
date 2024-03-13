#include "Mercado.h"
#include "Produto.h"
#include <string>
#define MAX_PRODUTOS 100
#pragma once

class Estoque : public Mercado {
protected:
  Produto p[MAX_PRODUTOS];
  int temp = 1;
public:
  void cadastro();
  void listarProdutos();
  void qtdProdutos(); //Exibe a quantidade de produtos por nome  
};

void Estoque::cadastro() {

  string tipo, produto;
  float preco;
  int qtd, codigo;
  
  // Cadastro dos produtos
  cout << "Digite o tipo do produto(limpeza, comida, bebida): ";
  cin.ignore();
  getline(cin, tipo);
  cout << "Digite o nome do produto: ";
  getline(cin, produto);
  cout << "Digite a quantidade do produto: ";
  cin >> qtd;
  cout << "Digite o preco do produto: ";
  cin >> preco;
  cout << "Digite o codigo do produto: ";
  cin.ignore();
  cin >> codigo;

  // Criando um objeto Produto com os dados fornecidos
  p[temp] = Produto(tipo, produto, qtd, preco, codigo);
  temp++;
}

//Exibe todos os produtos de todos os tipos
void Estoque::listarProdutos(){
  int op, codigo;
  cout << "(1) - Exibir produto por codigo\n(2) - Exibir produto por tipo\n(3) - Exibir todos os produtos\nDigite a opcao desejada: ";
  cin >> op;
  switch(op){
    case 1:
        cout << "Digite o codigo do produto: ";
        for(int i=0; i<MAX_PRODUTOS; i++){
          if(p[i].getCodigo() == codigo)
            cout << "Tipo: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade: " << p[i].getQtd() << "\nPreco: " << p[i].getPreco() << "\nCodigo: " << p[i].getCodigo() << endl;
          
        }
        break;
    
    case 2:
      
    
  }

}




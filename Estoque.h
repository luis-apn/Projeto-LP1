#include "Mercado.h"
#include "Produto.h"
#include <string>
#include "Arquivar.h"
#define MAX_PRODUTOS 100
#pragma once
//adicionei Estoque herdando de arquivar para chamar os metodos com mais facilidade, apesar de estarem publicos
class Estoque : public Mercado, public Arquivar {
protected:
  Produto p[MAX_PRODUTOS];

public:
  void cadastro();
  void listarProdutos();
  void alterarProduto();
  void removerProduto();

};

//CADASTRO DOS PRODUTOS - Realiza um cadastro por vez
void Estoque::cadastro() {

  string tipo, produto;
  float preco;
  int qtd, codigo, v_controle = 0;
  
  // Cadastro dos produtos
  //Eu acho que esse for não precisa ser aqui, se quiser pode fazer no menu um for que chama o metodo o numero de vezes que quiser!!
  for(int i=0; i<MAX_PRODUTOS; i++){
    //Caso o valor esteja zerado, significa que o produto n foi cadastrado
    if( p[i].getPreco() == 0){
      cout <<"\n--------------CADASTRO--------------\n";
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
      cin >> codigo;
      
      //Essa condicao de teste para o a existencia de codigos repetidos precisa ser melhor desenvolvida
      
        for (int i = 0; i < MAX_PRODUTOS; i++)
        {
          if (codigo != 0 && codigo == p[i].getCodigo()) {

            cout << "Codigo invalido, por favor, insira um novo codigo: ";
            cin >> codigo;
            i = 0;
          }
        
        }
      

      /*while (true){
        for(int j=0; j<MAX_PRODUTOS; j++){
          if((p[j].getCodigo() != 0) && (p[j].getCodigo() ==  codigo)) {
            cout << "Codigo digitado ja foi cadastrado, por favor, insira um novo codigo: ";
            cin >> codigo;
          }
          else
            v_controle = 1;
        }
        //Condicao de saida do teste
        if(v_controle == 1)
          break;
      }*/

      //Cadastro do produto
      p[i] = Produto(tipo, produto, qtd, preco, codigo);
      break;
    }
  }
}


//Exibe todos os produtos de todos os tipos
void Estoque::listarProdutos(){
  int op, codigo, controle = 0;
  string tipo;
  cout << "(1) - Exibir produto por codigo\n(2) - Exibir produto por tipo\n(3) - Exibir todos os produtos\nDigite a opcao desejada: ";
  cin >> op;
  switch(op){
    
    //Exibe o produto por codigo
    case 1:
        cout << "Digite o codigo do produto dejado: ";
        cin >> codigo;

        for(int i=0; i<MAX_PRODUTOS; i++){
          if(p[i].getCodigo() == codigo){ 
            cout << "Tipo: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade: " << p[i].getQtd() << "\nPreco: R$ " << p[i].getPreco() << "\nCodigo: " << p[i].getCodigo() << endl;
            controle = 1;
          }
        }
        if(controle == 0)
          cout << "CODIGO INSERIDO NAO POSSUI REGISTRO\n\n";

        break;
    case 2:
      cout << "Digite a classificacao do produto: ";
      cin.ignore();
      getline(cin, tipo);
      for(int i=0; i< MAX_PRODUTOS; i++){
        if(p[i].getTipo().find(tipo) != -1){ 
          cout << "Tipo: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade: " << p[i].getQtd() << "\nPreco: R$ " << p[i].getPreco() << "\nCodigo: " << p[i].getCodigo() << endl;
          controle = 1;
        }
      }
      if(controle == 0)
          cout << "CODIGO INSERIDO NAO POSSUI REGISTRO\n\n";
      break;

    case 3:
      cout << "\n\n------------PRODUTOS CADASTRADOS------------\n";
      for(int i=0; i<MAX_PRODUTOS; i++){
        
        //Exibe todos os produtos que possuem preco diferente de zero e exibe
        if(p[i].getPreco() != 0){ 
        cout << "Tipo: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade: " << p[i].getQtd() << "\nPreco: R$ " << p[i].getPreco() << "\nCodigo: " << p[i].getCodigo() << endl;

        }
      }
      break;
    
    default:
      cout << "OPCAO INVALIDA!\n\n";
      break;
  }

}

//ALTERA PRODUTOS POR CODIGO
void Estoque::alterarProduto(){

  int codigo, qtd, controle = 0;
  string tipo, produto;
  float preco;

  cout << "\n\n-----------ALTERAR PRODUTO-----------\n";
  cout << "Digite o codigo do produto que voce deseja alterar: ";
  cin >> codigo;
  for(int i=0; i<MAX_PRODUTOS; i++){
    if(codigo == p[i].getCodigo()){

      //Recebendo os novos dados a serem alterados
      cout << "Digite o tipo do produto(limpeza, comida, bebida): ";
      cin.ignore();
      getline(cin, tipo);
      cout << "Digite o nome do produto: ";
      getline(cin, produto);
      cout << "Digite a quantidade do produto: ";
      cin >> qtd;
      cout << "Digite o preco do produto: ";
      cin >> preco;

      //Mudando no vetor de produtos
      p[i] = Produto(tipo, produto, qtd, preco, codigo);
      controle = 1;
    }
    else
      continue;
  }

  if(controle == 0)
    cout << "CODIGO INSERIDO NAO POSSUI REGISTRO\n\n";
}

//REMOVE PRODUTOS INSERINDO ZERO E LIMPANDO O CONTEUDO DAS STRING
void Estoque::removerProduto(){
  int codigo, controle=0;
  cout << "\n\n-----------DELETAR PRODUTO-----------\n";
  cout << "Digite o codigo do produto que vc deseja deletar: ";
  cin >> codigo;
  for(int i=0; i<MAX_PRODUTOS; i++){
    if(codigo == p[i].getCodigo()){   

      //Chamada do construtor vazio para limpar o conteudo do produto
      p[i] = Produto();
    }
    else
      continue;
  }

  if(controle == 0)
    cout << "CODIGO INSERIDO NAO POSSUI REGISTRO\n\n";
}

//Tem que alterar o recebimento da variavel codigo, pois n pode haver codigos repetidos
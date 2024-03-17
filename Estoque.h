#include "Produto.h"
#include <string>
#include <sstream>
#include "Arquivar.h"
#define MAX_PRODUTOS 100
#pragma once
//adicionei Estoque herdando de arquivar para chamar os metodos com mais facilidade, apesar de estarem publicos
class Estoque : public Arquivar{
protected:
  Produto p[MAX_PRODUTOS];

public:
  void cadastro();
  void listarProdutos();
  void alterarProduto();
  void removerProduto();
  void salvarEstoque();
  void aberturaArquivo();

};

//CADASTRO DOS PRODUTOS - Realiza um cadastro por vez
void Estoque::cadastro() {

  string tipo, produto;
  float preco;
  int qtd, codigo;
  
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
        
        for (int t = 0; t < MAX_PRODUTOS; t++)
        {
          if ((codigo != 0 && codigo == p[t].getCodigo()) || codigo == 0) {

            cout << "Codigo invalido, por favor, insira um novo codigo: ";
            t = - 1;
            cin >> codigo;
            
          }
        }

      //Cadastro do produto
      p[i] = Produto(tipo, produto, qtd, preco, codigo);

      stringstream ss;
      ss << "Foi adicionado: " << "Produto :" << produto << " - Quantidade: " << qtd << " - Preco: " << preco;
      salvarlog(ss.str());
      break;
    }
  }
}

//Exibe todos os produtos de todos os tipos 
void Estoque::listarProdutos(){
  int op, codigo, controle = 0;
  string tipo;
  cout << "\n------------------EXIBIR PRODUTOS------------------\n";
  cout << "(1) - Exibir produto por codigo\n(2) - Exibir produto por tipo\n(3) - Exibir todos os produtos\nDigite a opcao desejada: ";
  cin >> op;
  
  switch(op){
    //Exibe o produto por codigo
    case 1:
        cout << "Digite o codigo do produto dejado: ";
        cin >> codigo;

        for(int i=0; i<MAX_PRODUTOS; i++){
          if(p[i].getCodigo() == codigo){ 
            
            cout << "Tipo de Produto: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade em Estoque: " << p[i].getQtd() << "\nPreco: R$ " << p[i].getPreco() << "\nCodigo de Registro: " << p[i].getCodigo() << endl << endl;
            stringstream ss;
            ss << "Foi exibido o produto: " << codigo;
            salvarlog(ss.str());
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
           cout << "Tipo de Produto: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade em Estoque: " << p[i].getQtd() << "\nPreco: R$ " << p[i].getPreco() << "\nCodigo de Registro: " << p[i].getCodigo() << endl << endl;
          controle = 1;
          stringstream ss;
          ss << "Foi exibido os produto do tipo: " << tipo;
          salvarlog(ss.str());
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
        cout << "Tipo de Produto: " << p[i].getTipo() << "\nProduto: " << p[i].getProduto() << "\nQuantidade em Estoque: " << p[i].getQtd() << "\nPreco: R$ " << p[i].getPreco() << "\nCodigo de Registro: " << p[i].getCodigo() << endl << endl;
        }
      }
      for (int i = 0; i < 0; i++)
      {
        stringstream ss;
        ss << "Foram exibidos todos os produtos ";
        salvarlog(ss.str());
      }
      
      
      break;
    
    default:
      cout << "OPCAO INVALIDA!\n\n";
      break;
  }

}

//ALTERA PRODUTOS POR CODIGO?
void Estoque::alterarProduto(){

  int codigo, qtd, controle = 0;
  string tipo, produto;
  float preco;

  cout << "\n\n-----------ALTERAR PRODUTO-----------\n";
  cout << "Digite o codigo do produto que voce deseja alterar: ";
  cin >> codigo;
  for(int i=0; i<MAX_PRODUTOS; i++){
    if(codigo == p[i].getCodigo()){
      string temp = p[i].getProduto();
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

      //adicionar no log
      stringstream ss;
      ss << "Produto alterado: " << temp << " - Para -> " << "tipo: "<<tipo << ", "<< "quantidade: "<< qtd <<", Produto: " << produto << ", Preco: " << preco << std::endl;
      salvarlog(ss.str());
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
      cout << "PRODUTO REMOVIDO COM SUCESSO!\n";
      stringstream ss;
      ss << "foi removido o porduto: " << p[i].getProduto();
      salvarlog(ss.str());
      controle++;
    }
    else
      continue;
  }

  if(controle == 0)
    cout << "CODIGO INSERIDO NAO POSSUI REGISTRO\n\n";
}

//SALVA OS PRODUTOS QUE ESTAO NA MEMORIA NO ARQUIVO DO ESTOQUE
void Estoque::salvarEstoque(){
  ofstream estoque;
  int total = 0;

    //Abertura do arquivo para escrita 
  estoque.open("Estoque.txt");

  if(!estoque.is_open())
        cout << "ERRO AO ABRIR O ESTOQUE!\n";
    
    //Contagem de produtos cadastrados
  for(int i=0; i < MAX_PRODUTOS; i++)
    if(p[i].getCodigo() != 0 )
      total++;

  //MANDANDO PARA O ESTOQUE O TOTAL DE PRODUTOS CADASTRADOS
  estoque << total << endl;

  //CADASTRO DOS PRODUTOS
  for(int i = 0; i< MAX_PRODUTOS; i++){
    if(p[i].getCodigo() > 0){
      estoque << p[i].getTipo() << endl;
      estoque << p[i].getProduto() << endl;
      estoque << p[i].getQtd() << endl;
      estoque << p[i].getPreco() << endl;
      estoque << p[i].getCodigo() << endl;
    }
    else
      continue;
  }

  estoque.close();
}
//LER OS DADOS CONTIDOS NO ARQUIVO E INSERE DENTRO DAS VARIAVEIS DOS PRODUTOS
void Estoque::aberturaArquivo(){
  ifstream abertura;
  int i=0, qtd, codigo, total = 0;
  float preco;
  string produto, tipo;

  //Abertura do arquivo para leitura
  abertura.open("Estoque.txt");

  if(!abertura.is_open())
    cout << "ERRO AO ABRIR O ARQUIVO\n";
  
  abertura >> total;
  abertura.ignore();
  
  if(total > 0){
    while (!abertura.eof()){
      getline(abertura, tipo);
      getline(abertura, produto);
      abertura >> qtd;
      abertura >> preco;
      abertura >> codigo;
      abertura.ignore();
      p[i] = Produto(tipo, produto, qtd, preco, codigo);
      i++; 
      if(i == total)
        break;
    }
  }
  abertura.close();
}
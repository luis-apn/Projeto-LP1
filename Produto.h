#include <iostream>
#include <string>

#pragma once

class Produto {
private:
  std::string tipo; // LIMPEZA: desodorante, pasta de dente etc, comidas: batata, arroz, feijao, etc
  std::string produto;
  int qtd; // Quantidade de produtos de um mesmo tipo
  float preco;
  int codigo;

public:
  Produto(){}
  Produto(std::string tipo, std::string produto, int qtd, float preco, int)
      : tipo(tipo), produto(produto), qtd(qtd), preco(preco) {}
  
  //Metodos set para os Produtos
  void setTipo(std::string tipo) { this->tipo = tipo; }
  void setProduto(std::string produto) { this->produto = produto; }
  void setQtd(int qtd) { this->qtd = qtd; }
  void setPreco(float preco) { this->preco = preco; }
  void setCodigo(int codigo) { this->codigo = codigo; }
  // Metodos get para os Produtos
  std::string getTipo() { return tipo; }
  std::string getProduto() { return produto; }
  int getQtd() { return qtd; }
  float getPreco() { return preco; }
  int getCodigo() { return codigo; }
};
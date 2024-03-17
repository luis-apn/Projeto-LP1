#include <iostream>
#include <string>
#pragma once

using namespace std;

class Data {
public:
  Data(int d, int m, int a);
  Data();
  int getDia();
  int getMes();
  int getAno();
  void exibirData();

private:
  int dia, mes, ano;
};

Data::Data(int d, int m, int a) {
  dia = d;
  mes = m;
  ano = a;
}

Data::Data() {}

int Data::getDia() { return dia; }
int Data::getMes() { return mes; }
int Data::getAno() { return ano; }

void Data::exibirData(){
  if(dia < 10 && mes < 10)
     cout << "0" << dia << "/0" << mes << "/"<< ano;
  else if(dia < 10 )
    cout << "0" << dia << "/" << mes << "/"<< ano;
  else if(mes < 10)
    cout  << dia << "/0" << mes << "/"<< ano;
  else 
     cout  << dia << "/" << mes << "/" <<  ano;
}
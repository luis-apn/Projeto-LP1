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

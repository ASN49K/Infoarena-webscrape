//
//  main.cpp
//  euclid
//
//  Created by Vlad Fara on 01.03.2016.
//  Copyright (c) 2016 Algoritmi S.R.L. All rights reserved.
//

#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
  int rez = -1;
  while(a != 0 && b != 0)
  {
    if(a == max(a, b)){
      a = a-b;
    }
    else{
      b = b-a;
    }
  }
  if(a)
    rez=a;
  else
    rez=b;
  return rez;
}

int main() {
  int a, b, len;
  fin >> len;
  for(int i = 0;i<len;i++)
  {
    fin >> a;
    fin >> b;
    fout << euclid(a,b);
  }
  return 0;
}
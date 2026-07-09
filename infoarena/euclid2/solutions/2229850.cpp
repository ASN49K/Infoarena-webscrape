//
//  main.cpp
//  1_euclid_infoarena
//  Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din
//  fiecare pereche in parte.
//  Created by Cristinel Gabriel Rusu on 08.08.2018.
//  Copyright © 2018 Cristinel Gabriel Rusu. All rights reserved.
//

#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a, b, T, maxim=0;

int cmmdc (int a, int b)
{
    if(b == 0)
        return a;
    else return cmmdc(b, a % b);
}

int main()
{
    
    fin>>T;
    for(int i=0; i<T; i++)
    {
        
        fin>>a>>b;
        cmmdc(a,b);
        fout<<a<<'\n';
    }
    
    
}

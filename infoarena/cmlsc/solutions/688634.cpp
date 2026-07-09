#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdlib.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025];
int b[1025];
int a_nr;
int b_nr;
int matrice[1025][1025];
void sir(int lin,int col)
{
    if(lin==0||col==0)
    return;
    if(a[lin]==b[col])
    {
        sir(lin-1,col-1);
        out<<a[lin]<<" ";
    }
    else
    {
        if(matrice[lin-1][col]>matrice[lin][col-1])
            sir(lin-1,col);
        else sir(lin,col-1);
    }
}
inline int max(int x,int y)
{
    if(x>y)
        return x;
    return y;
}
int main()
{
    string tmp;
    in>>tmp;
    a_nr= atoi(tmp.c_str());
    in>>tmp;
    b_nr= atoi(tmp.c_str());
    for(int i=1;i<=a_nr;i++)
    {
        in>>tmp;
        a[i]= atoi(tmp.c_str());
    }
     for(int i=1;i<=a_nr;i++)
    {
        in>>tmp;
        b[i]= atoi(tmp.c_str());
    }
    for(int i=1;i<=a_nr;i++)
    {
        for(int j=1;j<=b_nr;j++)
        {
            if(a[i]==b[j])
            {
                matrice[i][j] = 1+ matrice[i-1][j-1];
            }
            else matrice[i][j] = max (matrice[i][j-1],matrice[i-1][j]);
        }
    }
    out<<matrice[a_nr][b_nr]<<"\n";
    sir(a_nr,b_nr);
    //for(int i=1;i<=a_nr;i++)
    //{
    //    for(int j=1;j<=b_nr;j++)
    //        out<<matrice[i][j]<<" ";
    //    out << "\n";
   // }
    return 0;
}

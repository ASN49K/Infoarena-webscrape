#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[1025];
int b[1025];
int T[1026][1026]={};
int p1, p2;//Cautatorii, pozitiile in matrice a elem maxim

void Citire()
{
   f>>n>>m;
   for(int i = 1; i <= n; i++)
   {
      f>>a[i];
   }

   for(int i = 1; i <= m; i++)
   {
      f>>b[i];
   }
}

/*
void AfT()
{
   for(int i = 0; i <= n; i++)
   {
      for(int j = 0; j<= m; j++)
      {
         cout<<T[i][j]<<" ";
      }
      cout<<endl;
   }
}*/

void SC()
{
   //Dinamica, construit invers ca sa tiparim crescator
   int max1 = -1;

   for(int i = n; i >= 1; i--)
   {
      for(int j = m; j >= 1; j--)
      {
         if( a[i] == b[j] )
         {
            T[i][j] = T[i+1][j+1] + 1;
         }
         else
         {
            T[i][j] = max(T[i+1][j], T[i][j+1]);
         }

         if(T[i][j] > max1)
         {
            max1 = T[i][j];
            p1 = i; p2 = j;
         }
      }
   }

}

void Constr()
{
   //Construim secventa maxima comuna
   //p1,p2 sunt intotdeauna ultimul element din matrice sau primul daca tiparim crescator
   p1 = 1; p2 = 1;
   g<<T[1][1]<<endl;
   while(p1<=n || p2<=m)
   {
      if(T[p1][p2]!=T[p1+1][p2] && T[p1][p2]!=T[p1][p2+1])
      {
         //Vine de pe diagonala, deci este element
         g<<a[p1]<<" ";
         p1 +=1; p2 +=1;
      }
      else//Vine de sus sau de jos
      {
         if(T[p1][p2]==T[p1][p2+1])
         {
            //Vine din dreapta
            p2 += 1;
         }
         else
         {
            //Vine din jos
            p1 += 1;
         }
      }
   }
}

int main()
{
    Citire();
    SC();
    //AfT();
    Constr();
}

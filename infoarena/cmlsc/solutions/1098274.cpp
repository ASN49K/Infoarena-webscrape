#include<iostream>
#include<fstream>
using namespace std;
  int main ()
  {
       int n,i,j;
            bool ciur[2000000];
            ifstream fin("ciur.in");
            ofstream fout("ciur.out");
            fin>>n;
     for(i=2;i<=n;i++)

           ciur[i]=true;

            for(i=2;i<n;i++)
       if(ciur[i]==true)
       for(j=i+i;j<=n;j=j+i)

            ciur[j]=false;

         int contor=0;
          for(i=2;i<=n;i++)
              if(ciur[i]==true)
             contor ++;

                 fout<<contor;
            return 0;

  }

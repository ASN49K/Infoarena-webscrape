#include<iostream.h>
#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
    int lsc[100][100];
int maxx (int x,int y)
{
     if(x>y)
      return x;
     else 
      return y;
}
int main()
{
    
 
int m,n,i,j,max;
   int x[100],y[100];
    
       //citim din fisier
    fin>>m>>n;
for(i=0;i<=m-1;i++)
  fin>>x[i];


for(j=0;j<=n-1;j++)
  fin>>y[j];
 
//rezolvarea
      for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
        if(x[i-1]==y[j-1])
         lsc[i][j]=lsc[i-1][j-1]+1;
        else
         lsc[i][j]=maxx(lsc[i][j-1],lsc[i-1][j]);



int sir[100],poz=0;
i=m;j=n;
 
 //avem construita matricea lsc
 //  lsc[i][j]=lungimea subsirului comun din primele i elemente
 // din primul sir si primele j elem din al doilea
 
 // avand matricea construim subsirul
 while(lsc[i][j]>0)
 if(x[i-1]==y[j-1])//daca avem doua elem egale
 {poz++;
                   sir[poz]=x[i-1];//punem in sir
                 
 i=i-1;//mergem pe diag  stanga sus
 j=j-1;
 }
 else //daca nu avem doua elem egale ne deplasam la maximul din matricea lsc
  if(lsc[i-1][j]>lsc[i][j-1])//daca elem de sus mai mare decat cel din st i=i-1
 i=i-1;
 else  //daca cel din stanga este mai mare j=j-1
  j=j-1;
  fout<<lsc[m][n]<<endl;
for(i=poz;i>=1;i--)
   fout<<sir[i]<<" ";
/*
         

                            for(i=1;i<=m;i++)
                            {cout<<endl;
                             for(j=1;j<=n;j++)
                             cout<<lsc[i][j]<<" ";}*/
                            
 fin.close();
 fout.close();                     
return 0;

}        

#include<iostream>
#include<fstream>
using namespace std;
  long n , a, b,i,aux ;
  int main()
{
  
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;
do 
{
        aux=a%b;
        a=b;
        b=aux;
        }
        while (aux);
        
        g<<a<<endl;
        
        }
        
        f.close();
        g.close();
return 0;

}


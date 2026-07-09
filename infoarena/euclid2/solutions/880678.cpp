#include <iostream>
#include <fstream>
using namespace std;

int main()
{ int a,b,i,k;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>i;
 for(k=1;k<=i;k++)
 {
     f>>a>>b;

     while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
     }
     g<<a<<"\n";
 }

f.close();
g.close();

    return 0;
}

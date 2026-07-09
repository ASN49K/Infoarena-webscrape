#include <iostream>
#include <fstream>
using namespace std;

int main()
{ int a, b,n;
    ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
   fin>> n;
   for (int i=1;i<=n;i++)
     {fin>> a>> b;
        while(a%b!=0)
        {
          if (a<b)
            swap(a,b);
          a%=b;
        }
       fout<<b<<"\n";
     }
    return 0;
}

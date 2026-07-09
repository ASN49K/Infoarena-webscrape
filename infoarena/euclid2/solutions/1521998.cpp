#include <iostream>
#include <fstream>
using namespace std;

int main()

{
int cmmdc,i,r ;
long T;
long long a ,b;
    ifstream f ("euclid2.in") ;
    ofstream g ("euclid2.out") ;

    f >> T ;
        for (i=0;i<T; i++)
      {
         f>> a;
        f>> b;

        while(b!=a)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }

         g<<a<<endl ;

      }










    return 0;
}

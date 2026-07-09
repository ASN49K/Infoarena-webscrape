#include<fstream>
#include<stdio.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{

    long n,i;
    long long d,c,aux;

    f>>n;
    for(i=1;i<=n;i++)
    {

           f>>c;
           f>>d;
            while(d!=0)
            {
                aux=d;
                d=c%d;
                c=aux;

            }

                g<<aux<<"\n";
        }







}

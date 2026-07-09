#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t,i;
    long int a,b,aux;
    in>>t;
    for(i=0;i<t;i++)
        {
            in>>a>>b;
            while(b!=0)
                {
                    aux=b;
                    b=a%b;
                    a=aux;
                }
            out<<a<<"\n";
        }
    in.close();
    out.close();
    return 0;
}

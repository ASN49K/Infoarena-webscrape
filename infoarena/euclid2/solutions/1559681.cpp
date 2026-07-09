#include <fstream>
using namespace std;

int cmmdc(int &a, int &b)
{
    int aux;
    while (b!=0)
    {
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a,b,n;
    in>>n;
    for (int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;
    }
}

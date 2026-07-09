#include <fstream>

using namespace std;
int n,k,x,y,aux,s,t;
int main()
{
    ifstream f("euclid2.in",ios::in);
    ofstream g("euclid2.out",ios::out);
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        while(x%y!=0)
        {
            aux=y;
            y=x%y;
            x=aux;
        }
        g<<y<<endl;
    }
    }









#include<fstream>
#include<limits.h>
using namespace std;

int main()
{
    fstream f;
    fstream g;
    f.open("euclid2.in",ios::in);
    g.open("euclid2.out",ios::out);
    int n;
    f>>n;
    int min,max;
    for(int i=0;i<n;i++)
    {
        int aux;
        f>>min>>max;
        if(min>max){aux=min;min=max;max=aux;}
        aux=max%min;

        while(aux!=0)
        {
            max=min;
            min=aux;
            aux=max%min;
        }
        g<<min<<"\n";
    }
    f.close();
    g.close();
}

#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    int x, y, n;
    fin>>n;
    ofstream fout("euclid2.out");
    for(int i=0; i<n; i++)
    {
        fin>>x>>y;
        if(x>y)
        {
            int aux=y;
            y=x;
            x=aux;
        }
        while(y>0)
        {
            int aux=y;
            y=x%y;
            x=aux;
        }
        fout<<x<<endl;
    }
    return 0;
}

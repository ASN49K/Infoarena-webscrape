#include <fstream>

using namespace std;

int main()
{
    ifstream fin("cmmdc.in");
    int x, y;
    fin>>x>>y;
    fin.close();
    ofstream fout("cmmdc.out");
    if(x>y)
    {
        int aux=x;
        x=y;
        y=aux;
    }
    while(y!=0)
    {
        int aux=y;
        y=x%y;
        x=aux;
    }
    if(x!=1)
        fout<<x;

    fout.close();
    return 0;
}

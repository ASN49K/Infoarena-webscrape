#include <fstream>
using namespace std;
int main()
{
    int a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;

    while(T--)
    {

    fin>>a>>b;
    while(a!=b)
        if(a>b)
            a=a-b;
        else b=b-a;

    fout<<b;

    }
    fin.close();
    fout.close();
    return 0;
}

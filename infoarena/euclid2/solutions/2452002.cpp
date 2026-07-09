#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b;

int euclid2(int a, int b)
{
    if(b==0)
        return a;
    return euclid2(b,a%b);
}
int main()
{
    fin>>T;
    for(int i=0; i<T; i++)
    {
        fin>>a>>b;
        fout<<euclid2(a,b)<<"\n";
    }
    fin.close();
    fout.close();

    return 0;
}

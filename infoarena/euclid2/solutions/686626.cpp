#include <fstream>
using namespace std;
int main ()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T,a,b;
    fin>>T;
    for (int i=1; i<=T; i++)
    {fin>>a>>b;
    while (a!=b)
    {if (a>b)
    a=a-b;
    if (b>a)
    b=b-a;}
    fout<<a<<endl;}
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
    

#include<fstream>
using namespace std;
int main()
{
    int T,a,b,i,r;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(i=1;i<=T;i++)
    {
    fin>>a>>b;
    while(b)
    {r=a%b;
    a=b;
    b=r;}
    fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}

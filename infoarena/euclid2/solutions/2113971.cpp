#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void Euclid(int a,int b,int& d)
{
    if(!b)d=a;
    else Euclid(b,a%b,d);
}

int t,a,b,d;
int main()
{
    fin>>t;
    while(t--)
        {fin>>a>>b;
         Euclid(a,b,d);
         fout<<d<<'\n';
        }


    fin.close(); fout.close();
    return 0;
}

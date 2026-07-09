#include <fstream>
using namespace std;
int main ()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long long int a,b;
    int t;
    fin>>t;
    while(t!=0)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if (a>b) a-=b;
            else b-=a;
        }
        fout<<a<<endl;
        t--;
    }
}


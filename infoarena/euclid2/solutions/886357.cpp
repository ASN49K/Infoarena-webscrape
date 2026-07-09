#include<fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t,a,b,i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a;
        fin>>b;
        while(a!=b)
        {
            if(a>b) a-=b;
            else b-=a;
        }
    fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}

#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    return cmmdc(b,a%b);
}
int a,b,t;
int main()
{
     ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}


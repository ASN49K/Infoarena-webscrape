#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    while(a)
    {
        if(a%b==0)
            return b;
        else if(b%a==0)
            return a;

        if(a==1 || b==1)
            return 1;
        if(a>b)
            a=a%b;
        else b=b%a;
    }

}

int main()
{
    int t, a,b,i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }


    fin.close();
    fout.close();
    return 0;
}

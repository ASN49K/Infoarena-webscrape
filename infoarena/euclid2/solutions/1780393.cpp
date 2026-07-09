#include<fstream>
using namespace std;
int main()
{
    int nrteste,i,a,b,t;
     ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>nrteste;
    for(;nrteste>0;--nrteste)
    {
        fin>>a>>b;
        while(b!=0)
        {
            t=b;
            b=a%b;
            a=t;

        }
        fout<<a<<endl;
    }
}

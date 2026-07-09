#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
    long long T,i,a,b,t;
     ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>T;
    for(i=1;i<=T;++i)
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

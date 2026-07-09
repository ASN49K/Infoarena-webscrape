#include<fstream>
using namespace std;
int main()
{
    int n,a,b,t,i;
     ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>a>>b;
        while(b!=a)
        {
            if(a>b){
                a=a-b;
            }
            else{
                b=b-a;
            }

        }
        fout<<a<<"\n";
    }
}

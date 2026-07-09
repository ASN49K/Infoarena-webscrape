#include <fstream>
using namespace std;
int main()
{
    ifstream fin("cmmdc.in");
    ofstream fout("cmmdc.out");

    int a,b,T,i;

    fin>>T;
    for(i=0;i<T;i++)
    fin>>a>>b;

    for(i=0;i<T;i++)
    while (a!=0 || b!=0){
        if(a>b)
        a = a%b;
        else if (a<b)
        b = b%a;
    }


    if(a==0)
    fout<<b<<'\n';
    else
    fout<<a<<'\n';

    fin.close();
    fout.close();
    return 0;

}
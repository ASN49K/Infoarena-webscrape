#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int t;

int cmmdc(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}


int main()
{
    int i,a,b;
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    return 0;
}


//Am doua nr a si b
//Eu trebuie sa le aflu cmmdcul
//Eu stiu de asemenea ca cmmdcul este cuprins intre 1 si min(a,b)
//Putem folosi de asemenea algoritmul lui Euclid prin scaderi repetate

#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int t;

int cmmdc(int a,int b)
{
    int i;
    for(i=min(a,b);i>=1;i--)
        if(a%i==0 and b%i==0)
            return i;
    //1 va fi mereu divizor ptr ambele nr deci putem ajunge in acel caz
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
//Deci as putea lua toate nr de la 1 la min(a,b) daca gasesc un nr care le divide pe ambele il pot afisa ca solutie
//Ca solutie bruta

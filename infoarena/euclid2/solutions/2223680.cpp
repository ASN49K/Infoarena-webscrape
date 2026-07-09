#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int t;

int putere(int a,int b)
{
    int i,prod=1;
    for(i=1;i<=b;i++)
        prod*=a;
    return prod;
}

void desc(int nr,int factori[15],int exp[15],int &lung)
{
    lung=0;
    int i,cur=nr;
    for(i=2;cur>1;i++)
        if(cur%i==0)
        {
            factori[++lung]=i;
            exp[lung]=1;
            cur/=i;
            while(cur%i==0)
                exp[lung]++,cur/=i;
        }
}

int cmmdc(int a,int b)
{
    int i,j,nr=1;
    int factori1[15],factori2[15],exp1[15],exp2[15],l1,l2;
    for(i=1;i<=10;i++)
        factori1[i]=factori2[i]=exp1[i]=exp2[i]=0;
    //Initializez vectori cu 0
    desc(a,factori1,exp1,l1);
    desc(b,factori2,exp2,l2);
    //Fac cele doua descompuneri
    i=1;j=1;
    while(i<=l1 and j<=l2)
    {
        if(factori1[i]==factori2[j])
            nr*=putere(factori1[i],min(exp1[i],exp2[j])),i++,j++;
        else
            if(factori1[i]<factori2[j])
                i++;
            else
                j++;
    }
    return nr;
    //Selectez numai factori comuni ptr a forma un nr
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
//Putem observa ca fiecare nr se descompune in factori primi
//Iar ptr a forma cmmdcul a lui a si b il putem forma numai din factori prezenti atat in a cat si b
//Deci o a doua solutie ar fi sa luam a si b sa ii descompunem in factori primi si apoi sa luam numai factori comuni la exponentul cel mai mai mic

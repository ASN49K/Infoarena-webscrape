#include <fstream>
#include <iostream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int ma[260][260],n,m,v[260],p=0;
struct nod
{
    int v;
    nod *urm;
}*first1,*last1,*nou1,*first2,*nou2,*last2;
void citire()
{
    int i;
    nou1=new nod;
    in>>nou1->v;
    nou1->urm=NULL;
    first1=nou1;
    for(i=1; i<m; i++)
    {
        last1=new nod;
        nou1->urm=last1;
        in>>last1->v;
        last1->urm=NULL;
        nou1=last1;
    }
    nou2=new nod;
    in>>nou2->v;
    nou2->urm=NULL;
    first2=nou2;
    for(i=1; i<n; i++)
    {
        last2=new nod;
        nou2->urm=last2;
        in>>last2->v;
        last2->urm=NULL;
        nou2=last2;
    }
}
int main()
{
    int i,j;
    in>>m>>n;
    citire();
    in.close();

    while(first1!=NULL)
    {
        nou2=first2;
        while(nou2!=NULL)
        {

            if(first1->v==nou2->v)
            {
                    first2=nou2;
                    p++;
                    v[p]=first2->v;
            }
            nou2=nou2->urm;
            j++;
        }
        first1=first1->urm;
        i++;
    }
    out<<p<<"\n";
    for(i=1;i<=p;i++)
        out<<v[i]<<" ";
    out.close();
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int a[1025], b[1025];

int main()
{
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int i, j, n, m, l, lmax=0, ia, ib, f, s[1025], c[1025];
cin>>n>>m;

for(i=1;i<=n;i++)
    cin>>a[i];
for(i=1;i<=m;i++)
    cin>>b[i];

for(i=1;i<=n;i++)
{
    l=0;
    ib=1;
    for(ia=i;ia<=n;ia++)
    {
       for(f=ib;f<=m;f++)
       {
           if(a[ia]==b[f])
           {
               ib=f+1;
               l++;
               c[l]=a[ia];
               break;
           }
       }
    }
    if(l>lmax)
    {
        lmax=l;
        for(f=1;f<=l;f++)
            s[f]=c[f];
    }
}
cout<<lmax<<endl;
for(f=1;f<=lmax;f++)
    cout<<s[f]<<" ";
    return 0;
}

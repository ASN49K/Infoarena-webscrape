#include <iostream>
#include <fstream>


using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int a[100],b[50],h=1,k,a2,b2,i,j,c;
int main()
{
    f>>a2>>b2;
    c=a2+b2;
    for(i=1;i<=c;i++)
        f>>a[i];
    for(i=1;i<=a2;i++)
    {
        for(j=a2+1;j<=c;j++)
        {
            if(a[i]==a[j]) {b[h++]=a[i]; i++; k++;}
        }
        g<<k<<"/n";
    }
    for(i=1;i<=k;i++)
        g<<b[i]<<" ";

    return 0;
}

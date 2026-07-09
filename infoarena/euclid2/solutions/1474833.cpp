#include <fstream>

using namespace std;

int main()
{
    unsigned long a[100000];
    unsigned long T;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(int i=1;i<=T;i+2)
        f>>a[i]>>a[i+1];
    while(a[i]!=a[i+1])
    {
        if(a[i]>a[i+1])
            a[i]=a[i]-a[i+1];
        else
            a[i+1]=a[i+1]-a[i];
    } for(i=1;i<=t;i++)
    g<<a[i]<<endl;

    return 0;
}

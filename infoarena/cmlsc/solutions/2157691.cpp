#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m, a[1100], b[1100], k=0, c[2200];
    f>>n>>m;
    for(int i=0; i<n;i++)
        f>>a[i];
    for(int i=0; i<m; i++)
        f>>b[i];
    sort(a, a+n);
    sort(b, b+m);
    for(int i=0, j=0; i<n&&j<m;)
    {
        if(a[i]==b[j])
            c[k++]=a[i], j++, i++;
        else if(a[i]<b[j])
            i++;
        else if(b[j]<a[i])
            j++;
    }
    g<<k<<endl;
    for(int i=0; i<k; i++)
    {
        g<<c[i]<<" ";
    }
    return 0;
}

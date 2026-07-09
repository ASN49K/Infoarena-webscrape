#include <fstream>
using namespace std;
ifstream in("copaci4.in");
ofstream out("copaci4.out");
int n,a[200005],nr;
int main()
{
    in>>n;
    for(int i=1;i<=n;i++) in>>a[i];
    for(int i=2;i<n;i++)
    {
        int st=i-1,dr=i+1;
        while(st && a[st] < a[i])st--;
        if(st && a[st] > a[i])
        {
            while(dr <= n && a[dr] < a[i]) dr++;
            if(st && dr <= n && a[dr] > a[i] && a[st] >a [i]) nr++;
        }
    }
    out<<nr<<'\n';
    return 0;
}

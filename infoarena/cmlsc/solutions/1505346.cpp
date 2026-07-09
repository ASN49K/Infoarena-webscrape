#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;
int a[1025],b[1025],c[1025][1025],la,lb,i,j;
vector <int> v;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    cin >> la >> lb;
    for(i=1;i<=la;i++)
        cin >> a[i];
    for(i=1;i<=lb;i++)
        cin >> b[i];
    for(i=1;i<=la;i++)
        for(j=1;j<=lb;j++)
        {if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }

    cout << c[la][lb] << endl;
    for(i=la;i>=1;)
        for(j=lb;j>=1;)
        {
            if(a[i]==b[j]){v.push_back(a[i]);i--;j--;}
            else if(c[i-1][j]>=c[i][j-1]) i--;
            else j--;
        }
    for(vector <int>::reverse_iterator it=v.rbegin();it!=v.rend();it++) cout << *it<<" ";
    return 0;
}

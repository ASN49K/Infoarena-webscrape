#include<fstream>
using namespace std;
ifstream cin("subsiruri.in");
ofstream cout("subsiruri.out");
int v[2000],n,i,j,lung[2000],subsir[2000],lmax,num;
int main()
{
cin >> n;
for ( i = 1 ; i <= n; ++ i)
cin >> v[i];
for(i = n ; i >= 1 ; -- i)
{
lung[i] = 1;
subsir[i] = 1;
for (j = n; j > i; -- j)
if (v[i] < v[j] && lung[i] < lung[j] + 1)
{
lung[i] = lung[j] + 1;
if (lung[i] > lmax)
lmax = lung[i];
subsir[i] = subsir[j];
}
else
if (v[i] < v[j] && lung[i] == lung[j] + 1)
subsir[i] = (subsir[i] + subsir[j]) % 9901;
}
for (i = 1; i <= n ; ++ i)
if (lung[i] == lmax)
num = (num + subsir[i]) % 9901;
cout << lmax << "\n" << num;
}

#include <bits/stdc++.h>

using namespace std;
ifstream f("ciur.in");
ofstream g("ciur.out");
int n,c;
int main()
{
f>>n;
bool prime[n+1];
memset(prime,true, sizeof(prime));
for(int i=2; i*i<=n;i++)
{
    if(prime[i]==true)
    {
        for(int p=i*i; p<=n; p=p+i)
            prime[p]=false;

    }

}

for(int i=2; i<=n; i++)
    if(prime[i]==true)
    c++;

    g<<c;


    return 0;
}

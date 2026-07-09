#include<bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
void sol(long long a,long long b)
{int r;
while(b)
{r=a%b;
a=b;
b=r;}
 out<<a<<'\n';}
int main()
{long long n,a,b,i;
in>>n;
for(i=1;i<=n;++i)
    {in>>a>>b;
    sol(a,b);}
in.close();
out.close();
return 0;
}

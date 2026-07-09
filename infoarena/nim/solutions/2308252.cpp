#include <bits/stdc++.h>
using namespace std;main(){int x,n,s,i,a;freopen("nim.in","r",stdin);freopen("nim.out","w",stdout);scanf("%d",&x);while(x--){scanf("%d", &n);for(i=1,s=0;i<=n;i++)scanf("%d",&a),s^=a;printf("%s\n",(s==0)?"NU":"DA");}return 0;}

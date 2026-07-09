#include <stdio.h>

using namespace std;
int euclid(int a, int b){
if (!b) return a;
return euclid(b,a%b);
}

int main()
{ int n;
freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d", &n);
for (int i=0; i<n; i++){
    int a,b;
    scanf("%d%d", &a, &b);
    printf("%d/n", euclid(a,b));
}
    return 0;
}

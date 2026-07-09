#include <iostream>
#include <bits/stdc++.h>
#include <fstream>


using namespace std;
int T,A,B;
int smecherie(int a, int b){
    if (b==0) return a;
    return smecherie(b, a%b);
}

int main()
{
freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d", &T);
for (int j=T; j--; j!=0)
{
    scanf("%d %d", &A, &B);
    printf("&d\n", smecherie(A,B));
}
return 0

}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, aux, r;
    cin>>a>>b;
    if (a<b)
        aux=a;
        a=b;
        b=aux;
    while (b!=0) {
        r=a%b;
        a=b;
        b=r;
}
    cout<<a;
    return 0;
}

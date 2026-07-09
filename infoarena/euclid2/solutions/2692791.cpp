#include <iostream>
#include <fstream>

using namespace std;

int n;
int values[100005][2];

void read()
{
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d\n", &values[i][0],&values[i][1]);
    }
}

int cmmdc(int a,int b){
    if(b == 0)
        return a;
    return cmmdc(b, a%b);
}

void solve()
{
    for(int i = 0; i < n ; i++)
        printf("%d\n", cmmdc(values[i][0],values[i][1]));
}


int main()
{
    freopen("euclid2.in	","r",stdin);
    freopen("euclid2.in	","w",stdout);

    read();
    solve();

    return 0;
}

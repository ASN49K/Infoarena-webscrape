#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
#include <map>
#include <math.h>
using namespace std;
int cmmdc(int a,  int b)
{
    if(!b)return a;
    else return cmmdc(b, a%b);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a , b;
        cin>>a>>b;
        cout<<cmmdc(a, b)<<endl;
    }
    return 0;
}


#include<cstdio>
using namespace std;

int swap(int &a,int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int gcd(int a,int b){
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
    
}

int main(){
    int t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);

    while (t)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
        --t;
    }
    
}
#include <cstdio>

using namespace std;

int n,s,sum,v[11];

int abs(int a){

    if(a<0) return -a;
    return a;

}

void printsol(){
    int j;
    for(j=1;j<=n;++j){

        printf("%d ",v[j]);

    }

    printf("\n");

}

void back(int k){

    if(k>n){

        if(sum==s){

            printsol();
            return;

        }

    }
    else{

        for(int i=-1;i<=1;++i){

            v[k]=i;
            sum+=abs(i);
            back(k+1);
            sum-=abs(i);

        }

    }

}


int main()
{

    freopen("surj.in","r",stdin);
    freopen("surj.out","w",stdout);

    scanf("%d%d",&n,&s);

    back(1);


    return 0;
}

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    freopen("cmlcs.in", "r", stdin);
    freopen("cmlcs.out", "w", stdout);

    std::vector<int> a, b, sol;
    a.push_back(257);
    b.push_back(257);

    int i, j, val;
    char m[1025][1025]={0};

    int n, _m;
    scanf("%d %d", &n, &_m);
    for(i=1;i<=n;i++){
        scanf("%d", &val);
        a.push_back(val);
    }
    for(i=1;i<=_m;i++){
        scanf("%d", &val);
        b.push_back(val);
    }

    for(i=1;i<=n;i++)
        for(j=1;j<=_m;j++)
            if(a[i]==b[j])
                m[i][j]=m[i-1][j-1]+1;
            else if(m[i-1][j]>m[i][j-1])
                m[i][j]=m[i-1][j];
            else
                m[i][j]=m[i][j-1];

    for(i=n, j=_m;j;){
        if(a[i]==b[j]){
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(m[i-1][j]>m[i][j-1])
            i--;
        else j--;
    }
    printf("%d\n", sol.size());
    for(i=sol.size()-1;i>=0;i--)
        printf("%d ", sol[i]);
    fflush(stdout);
    fclose(stdout);
    fclose(stdin);

}

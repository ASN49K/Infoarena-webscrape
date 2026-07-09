#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<int> v1,v2,vrez;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n,nr,i,j;
    int a[1025][1025];
    a[0][0]=0;
    f >> m >> n;

    for(i=0;i<m;i++){
        a[i][0]=0;
        f >> nr;
        v1.push_back(nr);
    }

    for(j=0;j<n;j++){
        a[0][j]=0;
        f >> nr;
        v2.push_back(nr);
    }
    a[m][0] = a[0][n]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(v1[i-1] == v2[j-1])
                a[i][j] = a[i-1][j-1]+1;
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
    i=m;
    j=n;
    while(i>0 && j>0){
        if(a[i-1][j] == a[i][j])
            i--;
        else if(a[i][j-1] == a[i][j])
            j--;
        else{
            vrez.push_back(v1[i-1]);
            i--;
            j--;
        }
    }
    g << a[m][n] << endl;
    for(i=vrez.size() - 1;i>=0;i--)
        g << vrez[i] << " ";
    return 0;
}

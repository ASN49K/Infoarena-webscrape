#include <fstream>

#define maxi(a,b) ((a>b)?a:b)
#define V 1050

using namespace std;

int m,n,a[V],b[V],d[V][V],s[V],l;

ifstream in("cmlsc.in");
ofstream ex("cmlsc.out");

void readFunc(){

    in>>m>>n;

    for(int i=1; i<=m; i++)
        in>>a[i];

    for(int j=1; j<=n; j++)
        in>>b[j];

    in.close();

}

void constructorDynamicMatrix(){

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            d[i][j] = (a[i]==b[j])?
                1+d[i-1][j-1]:
                maxi(d[i-1][j],d[i][j-1]);

}

void createSolutionArray(){

   for(int i=m,j=n;i;){
        if(a[i]==b[j])
            s[++l] = a[i],--i,--j;
        else if(d[i][j-1]<d[i-1][j])
            --i;
        else
            --j;
    }



}

void showFunc(){
    ex<<l<<endl;
    for(int i=l; i; --i)
        ex<<s[i]<<" ";
    ex.close();

}
int main(){

    readFunc();
    constructorDynamicMatrix();
    createSolutionArray();
    showFunc();

    return 0;
}


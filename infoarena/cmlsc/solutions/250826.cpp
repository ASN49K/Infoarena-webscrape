#include <fstream>

#define for(i,li,lf) for(typeof(li) i=(li);i<=(lf);i++)
#define max(a,b) (a) > (b) ? (a) : (b)

using namespace std;

int main()
{
    int m,n;
    int a[1026],b[1026];
    fstream f("cmlsc.in",ios::in);
    fstream f2("cmlsc.out",ios::out);

    f>>m>>n;

    for(i,1,m) f>>a[i];
    for(i,1,n) f>>b[i];


    //imi fac matricea:

    char mat[1026][1026];

    for(i,0,m) mat[0][i]=0;
    for(i,0,n) mat[i][0]=0;

    for(i,1,n)
        for(j,1,m)
            mat[i][j]= ( (b[i]==a[j]) ? ( 1 + mat[i-1][j-1] ) : max(mat[i-1][j],mat[i][j-1]) );

    int len = (int)mat[n][m];

    f2<<len<<endl;

    //refac un subsir:

    int sol[1026];

    int lin=n,col=m;
    int p=0;
    while(p<len)
    {
        int x=mat[lin][col];
        int y=mat[lin-1][col];
        int z=mat[lin][col-1];

        if( x>y && x>z)
        {
            sol[len- (p++)]=a[col];
            if(y>=z) lin--;
            else col--;
        }

        else if(z<=y) lin--;

        else col--;
    }

    for(i,1,len) f2<<sol[i]<<" ";



    f.close();
    f2.close();
    return 0;
}

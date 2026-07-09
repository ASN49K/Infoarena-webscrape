#include <fstream>

#define for(i,li,lf) for(typeof(li) i=(li);i<=(lf);i++)
#define max(a,b) (a) > (b) ? (a) : (b)

using namespace std;

unsigned long long power2[] = {1LL,2LL,4LL,8LL,16LL,32LL,64LL,128LL,256LL,512LL,
1024LL,2048LL,4096LL,8192LL,16384LL,32768LL,65536LL,131072LL,262144LL,524288LL,
1048576LL,2097152LL,4194304LL,8388608LL,16777216LL,33554432LL,67108864LL,134217728LL,268435456LL,536870912LL,
1073741824LL,2147483648LL,4294967296LL,8589934592LL,17179869184LL,34359738368LL,68719476736LL,137438953472LL,274877906944LL,549755813888LL,
1099511627776LL,2199023255552LL,4398046511104LL,8796093022208LL,17592186044416LL,35184372088832LL,70368744177664LL,140737488355328LL,281474976710656LL,562949953421312LL,
1125899906842624LL,2251799813685248LL,4503599627370496LL,9007199254740992LL,18014398509481984LL,36028797018963968LL,72057594037927936LL,144115188075855872LL,288230376151711744LL,576460752303423488LL,
1152921504606846976LL,2305843009213693952LL,4611686018427387904LL,9223372036854775808LL};

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

    unsigned char mat[1026][1026];

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
            if(y>z) lin--;
            else col--;
        }

        else if(z<y) lin--;

        else col--;
    }

    for(i,1,len) f2<<sol[i]<<" ";



    f.close();
    f2.close();
    return 0;
}

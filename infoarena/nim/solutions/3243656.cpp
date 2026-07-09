#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t, n, i, j, a, sum;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++){
        fin>>n;
        sum=0;
        for(j=1;j<=n;j++){
            fin>>a;
            sum=sum^a;
        }
        if(sum>0){
            fout<<"DA\n";
        }else{
            fout<<"NU\n";
        }
    }




    return 0;
}

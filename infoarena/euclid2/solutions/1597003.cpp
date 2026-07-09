#include <fstream>

using namespace std;

int t,i,a,b,c;
int div(int a,int b){
if(b==0)return a;
else return div(b,a%b);
}
int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
    int t,i,c;
    fin>>t;
for(i=1;i<=t;i++){fin>>a>>b;
fout<<div(a,b)<<endl;
 }


    return 0;
}

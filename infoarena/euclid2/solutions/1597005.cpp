#include <fstream>

using namespace std;


int div(int a,int b){
if(b==0)return a;
else return div(b,a%b);
}
int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
    int a,b,t,i,c;
    fin>>t;
for(i=1;i<=t;i++){fin>>a>>b;
fout<<div(a,b)<<endl;
 }


    return 0;
}

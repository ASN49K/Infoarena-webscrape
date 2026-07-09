#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;
int euclid(int a,int b){
    if(b==0)
        return a;
    else
        return euclid(b,a%b);
}
int main()
{
    fin>>t;
   for (int i=1; i<=t; i++){
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
    return 0;
}

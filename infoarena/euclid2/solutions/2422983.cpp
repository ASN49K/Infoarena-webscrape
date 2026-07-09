#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void add(){
int a, b;
fin>>a>>b;

while(a!=b){
    if(a>b)
        a=a-b;
        else
        b=b-a;
        }
    fout<<a;
}
int main(){
int t;
fin>>t;
for(int i=1; i<=t; ++i)
    add();
    return 0;
}

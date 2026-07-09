#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b, c, T, i;

int cmmdc(int a,int b){
while(b){c=a%b;
a=b;
b=c;
}
return a;
}
int main(){
fin>>T;
for(i=1;i<=T;i++){    
fin>>a>>b;
fout<<cmmdc(a,b)<<"\n";
}
    fin.close();
    fout.close();
    return 0;
}

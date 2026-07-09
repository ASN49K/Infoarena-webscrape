
#include <fstream>

using namespace std;
ifstream fin("x.in");
ofstream fout("x.out");

int n,a,b,r;
int main(){
    fin>>n;
while(n){
    fin>>a>>b;

            while(b){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
        n--;
}
}

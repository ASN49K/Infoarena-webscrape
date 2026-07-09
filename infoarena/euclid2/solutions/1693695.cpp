#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,r,h;
int main(){
    fin>>n;
while(n){
    fin>>a>>b;
    if(b>a){
        h=a;a=b;b=h;
    }
            while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
        n--;
}


    fin.close();
    fout.close();
    return 0;

}

#include <iostream>
#include <cmath>

using namespace std;
int v[100000];
int Euclid(int b,int c){
    while (c !=0){
        int r=b%c;
        b=c;
        c=r;
        }
    return b;
}


int main(){
int a,b,c;
cin >>a;
for (int i=1;i<=a;i++){
    cin >>b>>c;
        v[i] = Euclid(b,c);
}
for (int i=1;i<=a;i++){
cout << v[i]<<endl;
}

return 0;
}

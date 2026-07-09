#include <bits/stdc++.h>
#include "rearrange.h"
using namespace std;

void write_cmmdc(int a, int b){
int div;
ofstream out("data.out",ios::app);
for(int i=1;i<max(a,b);i++){
    if(a%i==0&&b%i==0){
            div=i;
        }
    }

out<<div<<endl;
out.close();
}

int main()
{
int num, a,b;
ifstream in("data.in");
in>>num;
for(int i=0;i<num;i++){
    in>>a>>b;
    write_cmmdc(a,b);
}
in.close();
}

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f("date.in.txt");
ofstream g("date.out");

int cmmdc(int a,int b){
int next;
while(b != 0){
    next=a%b;
    a=b;
    b=next;

}



return a;//acum scoatem cmmdc :)
}


int main(){
int a,b,n;
f >> n;
for(int i=0;i < n;i++){
    f >> a >>  b;
    g << cmmdc(a,b) << endl;
}

return 0;
}

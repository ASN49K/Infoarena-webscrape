#include<fstream>
using namespace std;
int t,i;
long int a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
                fin>>t;
                for(i=0;i<t;i++){
                                    fin>>a>>b;
                                    while(a!=0&&b!=0){
                                                    while(a>=b&&a!=0&&b!=0) a=a%b;
                                                    while(a<=b&&b!=0&&a!=0) b=b%a;
                                                    if(a==0) {
                                                                fout<<b<<"\n";
                                                                return 0;
                                                             }
                                                    if(b==0) {
                                                            fout<<a<<"\n";
                                                            return 0;
                                                            }
                                                }
                                }
            }

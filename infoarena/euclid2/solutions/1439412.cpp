#include <fstream>
using namespace std;
FILE *f=fopen("cmmdc.in","r");
FILE *g=fopen("cmmdc.out","w");
int main()
{
    int a,b,n,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d %d",&a,&b);
        while(a!=b)
        {
            if(a>b)
            a=a%b;
            else
            b=b%a;
        if(a==1){
            fprintf(g,"%d",0);
            return 0;
            }
            else
        if(a==0||a==b){
            fprintf(g,"%d",b);
            return 0;
        }
        else if(b==0){
            fprintf(g,"%d",a);
            return 0;
            }
        }
    }
    return 0;
}

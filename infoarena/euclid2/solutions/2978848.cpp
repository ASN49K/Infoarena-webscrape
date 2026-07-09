#include <fstream>
using namespace std;
ifstream cin("nrcurat.in");
ofstream cout("nrcurat.out");

int ciur[1000001],prime[100001],nrprime;
#define mil 1000000

void gen_ciur()
{
    ciur[1] = ciur[0] = 1;
    for(int i = 2; i*i <=mil;i++)
        if(ciur[i]==0)
            for(int j = 2;i*j<=mil;j++)
                ciur[i*j]=1;
    for(int i =2 ; i<=mil;i++)
        if(ciur[i]==0)
            prime[++nrprime] =i;

}

bool is_prim(int n)
{
    int cnt=1;
    int ind = 1;
    if(n == 1 || n == 0)
        return false;
    if(n==2)
        return true;
    while(n>1)
    {
        int p = 0;
        while(n%prime[ind]==0)
            n/=prime[ind],p++;
        if(p)
            return false;
        ind++;
        if(prime[ind]*prime[ind] >n)
            return true;
    }
    return true;
}
int s;
int main(){
    int n;
    cin >> n;
    int a,b;
    for(int i = 1; i<=n;i++){
        cin >> a >> b;
        while(b)
        {
            int r = a%b;
            a = b;
            b = r;

        }
        cout << a << endl;
    }
    return 0;
}

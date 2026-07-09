#include<fstream>
std::ifstream F("nim.in");
std::ofstream G("nim.out");
int n,t,a,l;
int main()
{
    for(F>>t;t--;G<<(!l?"NU\n":"DA\n"))
        for(F>>n,l=0;n--;F>>a,l^=a);
    return 0;
}

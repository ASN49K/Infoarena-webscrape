#include <fstream>
int main(){std::ifstream f("euclid2.in");std::ofstream g("euclid2.out");int t,a,b,r;for(f>>t;t--;){f>>a>>b;while(b)r=a%b,a=b,b=r;g<<a<<'\n';}}//Po pricolu Ionita :D 

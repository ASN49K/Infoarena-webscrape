#import<fstream>
std::fstream f("euclid2.in"),g("euclid2.out");main(){int t,a,b,r;f>>t;while(t--){f>>a>>b;while(b)r=a%b,a=b,b=r;g<<a<<'\n';}}

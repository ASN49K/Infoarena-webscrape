//Friday, April 04 2008
//Source created by Harabula Adrian
//for infoarena.ro
/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <iostream.h>
#include <fstream.h>
int hack(int x, int y)  
{  
    if (!y) return x;  
    return hack(y, x % y);  
}  
int main()
{
  ifstream f("euclid2.in");   
  ofstream g("euclid2.out");   
  int t,a,b;
 f>>t;   
 for(t;t;--t)   
  {f>>a>>b;   
    g<<cmmdc(a,b)<<"\n";
  //  I was here
  // rEbyTer was here
  // http://89.43.162.48  available only when my computer is online 
  return 0;
}
 

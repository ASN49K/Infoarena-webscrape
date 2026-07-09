program p12;
var a,b,r,j:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a,b);
repeat
      r:=b mod a;
      b:=a;
      a:=r;
until r=0;
writeln(g,b);
{for j:=2 to a div 2 do
    if (a mod j=0)and(b mod j=0)then break;
writeln(g,j);}
close(g);
end.
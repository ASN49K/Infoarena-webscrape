program p12;
var a,b,r,t,i,j:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
repeat
      r:=b mod a;
      b:=a;
      a:=r;
until r=0;
writeln(g,b);
end;
close(g);
end.
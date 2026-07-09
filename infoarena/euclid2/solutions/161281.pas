var a,b,t,i,r:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do  begin
 readln(f,a,b);
repeat
r:=a mod b;
a:=b;
b:=r;
until r=0;
writeln(g,a);
end;
close(f);
close(g);
end.
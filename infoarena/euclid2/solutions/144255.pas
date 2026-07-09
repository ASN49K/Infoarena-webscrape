var f,g:text;
    a,b,r:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a,b);
repeat
r:=a mod b;
a:=b;
b:=r;
until r=0;
if a=1 then writeln(g,'0')
else write(g,a);
close(f);
close(g);
end.
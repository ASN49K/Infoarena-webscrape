var a,b,t,i,r:longint;
    f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,t); i:=1;
repeat
read(a,b);
while b<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
writeln(g,a);
i:=i+1;
until i=t;
close(f);
close(G);
end.
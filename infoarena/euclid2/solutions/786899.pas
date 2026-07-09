var f,g:text;
a,b,k,i,n,r:longint;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,n);
for i:=1 to n do
begin
read(f,a,b);
r:=a mod b;
while(0<b)do
begin
a:=b;
b:=r;
if (b>0) then r:=a mod b;
end;
writeln(g,a);
end;
close(f);
close(g);
end.

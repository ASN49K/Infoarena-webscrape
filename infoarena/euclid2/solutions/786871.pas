var f,g:text;
a,b,k,i,n,j:longint;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,n);
for i:=1 to n do
begin
read(f,a,b);
while(a<>b)do
begin
if(a>b) then  a:=a-b;
if(b>a) then  b:=b-a;
end;
writeln(g,a);
end;
close(f);
close(g);
end.

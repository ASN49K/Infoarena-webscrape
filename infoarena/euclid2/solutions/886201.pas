var a,b:text;
c,d:longint;
m,n,q,r,p:longint;
{function cmm(p,q:longint):longint;
var r:longint;
begin
if q<>0 then
begin
r:=p mod q;
p:=q;
q:=r;
cmm:=cmm(p,q);
end else cmm:=p;
end;}
begin
assign(a,'euclid2.in');
assign(b,'euclid2.out');
reset(a);
rewrite(b);
read(a,c);
for d:=1 to c do
begin
read(a,m);
read(a,n);
while n>0 do
begin
r:=m mod n;
m:=n;
n:=r;
end;
writeln(b,m);
{writeln(b,cmm(m,n));}
end;
close(a);
close(b);
end.


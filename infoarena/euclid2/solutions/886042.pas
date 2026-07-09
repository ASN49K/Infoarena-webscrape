var a,b:text;
c,d:longint;
m,n:longint;
function cmm(p,q:longint):longint;
begin
if (p>0) and (q>0) then
begin
if p=q then cmm:=p;
if p>q then cmm:=cmm((p mod q),q);
if q>p then cmm:=cmm((q mod p),p);
end else if p=0 then cmm:=q else cmm:=q;
end;
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
writeln(b,cmm(m,n));
end;
close(a);
close(b);
end.


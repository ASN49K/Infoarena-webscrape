program euclid2;
var f,g:text;
n,i,j,k,p,q:longint;

function cmmdc(p,q:longint):longint;
var d,i,r:longint;
begin
if p>q then d:=p else d:=q;
if p<q then i:=p else i:=q;
r:=d mod i;
while r<>0 do begin
d:=i;
i:=r;
r:=d mod i;
end;
cmmdc:=i;
end;

begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,n);
for j:=1 to n do begin
readln(f,p,q);
writeln(g,cmmdc(p,q));
end;
close(f);
close(g);
end.

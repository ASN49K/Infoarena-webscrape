program euclid2;
var
f1,f2:text;
n,m,k,i:longint;
function cmmdc(a,b:longint):longint;
begin
if b=0 then cmmdc:=a else
cmmdc:=cmmdc(b,a mod b);
end;
begin
assign (f1,'euclid2.in');
assign (f2,'euclid2.out');
reset(f1);
rewrite (f2);
readln (f1,m);
for i:=1 to m do begin
readln (f1,n,k);
writeln (f2,cmmdc(n,k));
end;
close (f1);
close (f2);
end.

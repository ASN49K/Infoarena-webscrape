program euclid2;
var
f1,f2:text;
n,m,k,i:longint;
begin
assign (f1,'euclid2.in');
reset(f1);
readln (f1,m);
assign (f2,'euclid2.out');
rewrite (f2);
for i:=1 to m do begin
readln (f1,n,k);
while (n<>0) and (k<>0) do
if n>k then n:=n mod k else k:=k mod n;
if n=0 then writeln (f2,k) else
writeln (f2,n);
end;
close (f1);
close (f2);
end.

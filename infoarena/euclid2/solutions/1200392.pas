program euclid2;
var
fi,fo:text;
n,m,k,i:longint;
begin
assign (fi,'euclid2.in');
assign (fo,'euclid2.out');
reset(fi);
rewrite (fo);
readln (fi,m);
for i:=1 to m do begin
readln (fi,n,k);
while (n<>0) and (k<>0) do
if n>k then n:=n mod k else k:=k mod n;
if n=0 then writeln (fo,k) else
writeln (fo,n);
end;
close (fi);
close (fo);
end.

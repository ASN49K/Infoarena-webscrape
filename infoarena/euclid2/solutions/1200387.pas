program euclid2;
var
n,m,k,i:longint;
begin
assign (input,'euclid2.in');
assign (output,'euclid2.out');
reset(input);
rewrite (output);
readln (m);
for i:=1 to m do begin
readln (n,k);
while (n<>0) and (k<>0) do
if n>k then n:=n mod k else k:=k mod n;
if n=0 then writeln (k) else
writeln (n);
end;
close (input);
close (output);
end.

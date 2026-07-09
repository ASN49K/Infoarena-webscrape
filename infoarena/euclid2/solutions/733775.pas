var i,j,k,l,m,n:longint; f1,f2:text;
begin
assign(f1,'euclid2.in');
reset(f1);
assign(f2,'euclid2.out');
rewrite(f2);
readln(f1,n);
for i:=1 to n do begin
readln(f1,k,l);
while (k>1) and (l>1) and (k<>l) do begin
if k>l then k:=k-l
else l:=l-k;
end;
if l=1 then writeln(f2,1)
else if k=1 then writeln(f2,1)
else
writeln(f2,k);
end;

close(f1);
close(f2);
end.

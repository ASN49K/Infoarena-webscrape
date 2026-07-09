var i,j,k,l,m,n:integer; a:array[0..1024,0..1024] of integer;
ar1,ar2:array[1..1024] of integer;
f1,f2:text;
function Max(x,y:integer):integer;
begin
if x>y then Max:=x
else Max:=y;
end;
procedure Solutie(k,h:integer);
begin
if a[k,h]>0 then begin
if ar1[k]=ar2[h] then begin
Solutie(k-1,h-1);
write(f2,ar1[k],' ');
end
else if (a[k,h]=a[k-1,h]) then Solutie(k-1,h)
else Solutie(k,h-1);
end;
end;
begin
assign(f1,'cmlsc.in');
reset(f1);
readln(f1,m,n);
for i:=1 to m do
read(f1,ar1[i]);
readln(f1);
for i:=1 to n do
read(f1,ar2[i]);
close(f1);
for i:=1 to m do
for j:=1 to n do
if ar1[i]=ar2[j] then a[i,j]:=1+a[i-1,j-1]
else a[i,j]:=Max(a[i-1,j],a[i,j-1]);
assign(f2,'cmlsc.out');
rewrite(f2);
writeln(f2,a[m,n]);
Solutie(m,n);
close(f2);
end.
uses math;
var t:array[0..1030,0..1030] of longint;
    a,b,s:array[1..1024] of longint;
    n,m,i,j,k:longint;
begin
assign(input,'cmlsc.in');
assign(output,'cmlsc.out');
reset(input);
rewrite(output);
read(n,m);
for i:=1 to n do read(a[i]);
for j:=1 to m do read(b[j]);
for i:=1 to n do
for j:=1 to m do
if a[i]=b[j] then t[i,j]:=t[i-1,j-1]+1 else
t[i,j]:=max(t[i-1,j],t[i,j-1]);
writeln(t[n,m],' ');
i:=n; j:=m;
while (i<>0) and (j<>0) do begin
if a[i]=b[j] then begin inc(k); s[k]:=a[i]; dec(i); dec(j) end else
if t[i-1,j]>t[i,j-1] then dec(i) else dec(j) end;
for i:=k downto 1 do write(s[i],' ');
close(input);
close(output);
end.


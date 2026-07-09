program cmlsc; uses math;
type tabel=array[0..1025,0..1025] of longint;
     vector1=array[0..1025] of longint;
var t:tabel; v1,v2,sol:vector1;
    n,m,i,j,nr:longint;
begin
assign (input,'cmlsc.in');
assign (output,'cmlsc.out');
reset (input);
rewrite (output);
readln (n,m);
for i:=1 to n do read (v1[i]);
for i:=1 to m do read (v2[i]);
for i:=1 to n do
for j:=1 to m do
if v1[i]=v2[j] then t[i,j]:=t[i-1,j-1]+1 else
t[i,j]:=max(t[i-1,j],t[i,j-1]);
i:=n; j:=m; nr:=0;
while t[i,j]<>0 do begin
while t[i,j]=t[i-1,j] do i:=i-1;
while t[i,j]=t[i,j-1] do j:=j-1;
nr:=nr+1; sol[nr]:=v1[i];
i:=i-1; j:=j-1;
end;
writeln (nr);
for i:=nr downto 1 do write (sol[i],' ');
close (input);
close (output);
end.
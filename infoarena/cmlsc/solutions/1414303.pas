program cmlsc;
type tabel=array[0..1025,0..1025] of longint;
     vector1=array[0..1024] of longint;
var t:tabel; v,vv,sol:vector1;
    nr,n,m,i,j:longint;
    f1,f2:text;
function max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;
begin
assign (f1,'cmlsc.in');
assign (f2,'cmlsc.out');
reset (f1);
rewrite (f2);
readln (f1,n,m);
for i:=1 to n do read (f1,v[i]);
for i:=1 to m do read (f1,vv[i]);
for i:=1 to n do
for j:=1 to m do
if v[i]=vv[j] then t[i,j]:=t[i-1,j-1]+1 else
t[i,j]:=max(t[i-1,j],t[i,j-1]);
i:=n; j:=m;
while t[i,j]<>0 do begin
while (t[i,j]=t[i-1,j]) do i:=i-1;
while (t[i,j]=t[i,j-1]) do j:=j-1;
nr:=nr+1; sol[nr]:=v[i];
i:=i-1; j:=j-1;
end;
writeln (f2,nr);
for i:=nr downto 1 do write (f2,sol[i],' ');
close (f1);
close (f2);
end.
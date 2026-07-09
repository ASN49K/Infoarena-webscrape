program cmlsc;
type tabel=array[0..1029,0..1029] of integer;
     tabb=array[0..1029] of longint;
var t,v,sol:tabb; vv:tabel;
    n,i,j,k,m:longint;
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
for i:=1 to n do read (f1,t[i]);
for i:=1 to m do read (f1,v[i]);
k:=0;
for i:=1 to n do
 for j:=1 to m do
  if (t[i]=v[j]) then vv[i,j]:=vv[i-1,j-1]+1 else
  vv[i,j]:=max(vv[i,j-1],vv[i-1,j]);
i:=n; j:=m;
while (vv[i,j]>0) do begin
while (vv[i-1,j]=vv[i,j]) do i:=i-1;
while (vv[i,j-1]=vv[i,j]) do j:=j-1;
k:=k+1; sol[k]:=t[i];
i:=i-1; j:=j-1;
end;
writeln (f2,k);
for i:=k downto 1 do write (f2,sol[i],' ');
close (f1);
close (f2);
end.
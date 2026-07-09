program codul;
var d:array[0..1025,0..1025]of longint;
v1,v2,nr:array[0..1025]of longint;
n,m,i,j,k:longint; 
function max(a,b:longint):longint;
begin if a>b then max:=a else max:=b; end;
begin
assign(input,'cmlsc.in');reset(input);
assign(output,'cmlsc.out');rewrite(output);
readln(n,m);
for i:=1 to n do read(v1[i]);readln();
for i:=1 to m do read(v2[i]);
for i:=1 to n do
  for j:=1 to m do
   if v1[i]=v2[j] then
     d[i,j]:=d[i-1,j-1]+1 else
     d[i,j]:=max(d[i,j-1],d[i-1,j]);
k:=d[n,m];
i:=n;j:=m;
while (i>0)do
begin
if v1[i]=v2[j] then
begin
inc(nr[0]);
nr[nr[0]]:=v1[i];
dec(i);dec(j);
end else
if d[i-1,j]>=d[i,j-1] then dec(i) else dec(j);
end;
for i:=k downto 1 do write(nr[i]);
close(input);close(output);
end.
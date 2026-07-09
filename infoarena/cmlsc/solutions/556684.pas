uses crt;
type matr=array[1..1025,1..1025] of integer;
     vek=array[1..1025] of integer;
var x:matr;
    v1,v2,v:vek;
    a,u,h,k,d,b,c,i,n,m,j:integer;
    f,g:text;
function max(i,j:integer):integer;
var a:integer;
begin
a:=0;
for h:= 1 to i do
 for k:= 1 to j do
  if x[h,k]>a then a:=x[h,k];
max:=a;
end;
begin
clrscr;
assign(f,'cmlsc.in');
reset(f);
read(f,n,m);
for i:= 1 to n do
 read(f,v1[i]);
for j:= 1 to m do
 read(f,v2[j]);
for i:=1 to n do
 for j:= 1 to m do
  if v1[i]=v2[j] then x[i,j]:=max(i-1,j-1)+1;
c:=max(n,m);
k:=0;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,c);
for i:= n downto 1 do
 begin
  for j:=1 to m do
   if (x[i,j]=c) and (c<>0) then
                        begin
                           inc(k);
                           v[k]:=v1[i];
                           dec(c);
                        end;
 end;
for i:= k downto 1 do
write(g,v[i],' ');
close(g);
close(f);
end.
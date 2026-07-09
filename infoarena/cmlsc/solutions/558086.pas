uses crt;
type matr=array[0..1025,0..1025] of integer;
     vek=array[0..1025] of integer;
var x:matr;
    v1,v2,v,u:vek;
    a,h,k,d,b,c,i,n,m,j:integer;
    f,g:text;
    ke:boolean;
function max(i,j:integer):integer;
begin
d:=0;
for i:= 1 to n do
for j:= 1 to m do
 if x[i,j]>d then d:=x[i,j];
max:=d;
end;



begin
clrscr;
assign(f,'cmlsc.in');
reset(f);
read(f,n,m);
ke:=false;
for i:= 1 to n do
 read(f,v1[i]);
for j:= 1 to m do
 read(f,v2[j]);
close(f);
for i:=1 to m do
begin
ke:=false;
 for j:= 1 to n do
  if v2[i]=v1[j] then
  begin
  d:=u[j-1]+1;
  u[j]:=d;
  x[i,j]:=d;
  ke:=true;
  end;
if ke then
begin
  d:=0;
for j:=1 to n do
 begin
  if d<u[j] then

   d:=u[j]
  else
   u[j]:=d;

  end;
  end;
end;




c:=u[n];
k:=0;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,c);
for i:= m downto 1 do
 begin
  for j:=1 to n do
   if (x[i,j]=c) and (c<>0) then
                        begin
                           inc(k);
                           v[k]:=v2[i];
                           dec(c);
                        end;
 end;
for i:= k downto 1 do
write(g,v[i],' ');
close(g);
end.

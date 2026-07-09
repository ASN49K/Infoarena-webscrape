uses crt;
type
     rec=record
      x,y,z:integer;
     end;
     vektor1=array[1..2000] of rec;
     matrix=array[1..2000,1..2000] of integer;
     vektor=array[1..2000] of integer;
var i,j,max,db,a,b,n,m,x1,y1:integer;
    v,v1,v3:vektor;
    v2:vektor1;
    x:matrix;
    f,g:text;
function maxi(a,b:integer):integer;
 var i,j,s:integer;
 begin
  s:=0;
  for i:= 1 to a do
   for j:= 1 to b do
    if x[i,j]>s
     then
      s:=x[i,j];
  max:=s;
 end;
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,n,m);
for i:= 1 to n do
 read(f,v[i]);
readln(f);
for i:= 1 to m do
 read(f,v1[i]);
close(f);
{for i:= 1 to n do
 begin
 db:=0;
 for j:=1 to m do
  begin
   if v[i]=v1[j]
    then
     begin
     inc(db);
     if db<=1
      then
       begin
        v2[i]:=v2[i]+1;
        v2[i].a:=1;
        v2[i].b:=j;
        a:=v2[i];
        for k:= i+1 to n do
          v2[k]:=a;
     end;
  end; }
for i:= 1 to n do
 for j:= 1 to m do
  begin
   if v[i]=v1[j]
    then
     begin
     x[i,j]:=maxi(i-1,j-1)+1;
     inc(db);
    { v2[db].x:=i;
     v2[db].y:=j;}
     v2[db].z:=x[i,j];
     end;
   end;
max:=0;
for i:= 1 to db do
 if v2[i].z>max
  then
   begin
   max:=v2[i].z;
  { x1:=v2[i].x;
   y1:=v2[i].y; }
   end;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,max);
{for i:= 1 to x1 do
 begin
  db:=0;
 for j:= 1 to y1 do
  if (x[i,j]<>0) and (db<2)
   then
    begin
     inc(db);
     write(g,v[i],' ');
    end;
 end;    }
db:=0;
for i:= n downto 1 do
 for j:= 1 to m do
  if (x[i,j]=max) and (x[i,j]<>0)
   then
    begin
     inc(db);
     v3[db]:=v[i];
     dec(max);
    end;
{for i:= 1 to n do
 write(v[i],' ');
writeln;
for i:= 1 to m do
 write(v1[i],' ');}
for i:= db downto 1 do
 write(g,v3[i],' ');
{for i:= 1 to x1 do
 begin
 for j:= 1 to y1 do
  write(x[i,j],' ');
 writeln;
 end;               }
close(g);
 readln;
end.

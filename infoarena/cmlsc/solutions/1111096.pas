program romanfeladat;
uses crt;
type vektor=array[1..10024] of integer;
     matrix=array[0..10024,0..10024] of integer;
var x:matrix;
   v,v1,v2:vektor;
   i,j,n,m,k:integer;
   f,g:text;
procedure beolvas(var v,v1:vektor; var n,m:integer);
var i:integer;
begin
  assign(f,'cmlsc.in');
  reset(f);
  read(f,n,m);
  readln(f);
  for i:=1 to n do
    read(f,v[i]);
  readln(f);
  for i:=1 to m do
    read(f,v1[i]);
  close(f);
end;

{foooo}
begin
beolvas(v,v1,n,m);
for i:=1 to n do
  x[0,i]:=0;
for i:=1 to m do
  x[i,0]:=0;
for i:=1 to n do
  for j:=1 to m do
    begin
      if v[i]=v1[j] then x[i,j]:=x[i-1,j-1]+1
                    else if x[i,j-1]>x[i-1,j]
                           then x[i,j]:=x[i,j-1]
                           else x[i,j]:=x[i-1,j];
    end;
i:=n;
j:=m;
for k:=1 to x[m,n] do
begin
  while x[i,j-1]=x[i,j] do
    dec(j);
  while x[i-1,j]=x[i,j] do
    dec(i);
  v2[k]:=v[i];
  i:=i-1;
  j:=j-1;
end;
assign(g,'cmlsc.out');
rewrite(g);
write(g,x[n,m]);
writeln(g);
for i:=x[n,m] downto 1 do
  write(g,v2[i],' ');
close(g);
for i:=1 to m do
 begin writeln;
  for j:=1 to m do
    write(x[i,j]) ;
  end;
end.









program fel;
uses crt;
type matrix=array[0..1024,0..1024] of integer;
var v1,v2:array[1..1024] of integer;
i,j,m,n,a:integer;
f,g:text;
x:matrix;
function max(a,b:integer):integer;
begin
 if a>b then max:=a
   else max:=b;
end;
begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 for i:=1 to n do
  begin
  read(f,v1[i]);
  x[i,0]:=0;
  end;
 for i:=1 to m do
  begin
  read(f,v2[i]);
  x[0,i]:=0;
  end;
 for i:=1 to n do
  begin
   for j:= 1 to m do
    begin
     if v1[i]=v2[j] then
       x[i,j]:=x[i-1,j-1]+1
      else x[i,j]:=max(x[i-1,j],x[i,j-1]);
    end;
  end;
 write(x[n,m]);
 for a:= 1 to x[n,m] do
  begin
   while x[i,j]=x[i-1,j] do dec(i);
   while x[i,j]=x[i,j-1] do dec(j);
   v1[a]:=v2[j];
   dec(i);
   dec(j);
  end;
 assign(g,'cmlsc.out');
 rewrite(g);
  writeln(g,x[n,m]);
  for i:= x[n,m] downto 1 do
    write(g,v1[i],' ');
  close(g);
end.

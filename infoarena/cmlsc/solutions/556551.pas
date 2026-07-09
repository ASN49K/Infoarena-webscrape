type matr=array[1..1024,1..1024] of integer;
     vek=array[1..1024]of longint;
var x:matr;
    v1,v2,v3:vek;
    i,j,k,l,o,m,n:integer;
    f:text;
function max(a,b:integer):integer;
 var k,l:integer;
  begin
   max:=x[1,1];
   for k:=1 to a do
    for l:=1 to b do
     if x[k,l]>max then max:=x[k,l];
  end;
begin
 assign(f,'cmlsc.in');
 reset(f);
 readln(f,n,m);
 for i:=1 to n do
  read(f,v1[i]);
 readln(f);
 for i:=1 to n do
  read(f,v2[i]);
 for i:=1 to n do
  begin
   for j:=1 to m do
    if v1[i]=v2[j]
     then x[i,j]:=max(i-1,j-1)+1;
  end;
 o:=max(n,m);
 assign(f,'cmlsc.out');
 rewrite(f);
 writeln(f,o);
 close(f);
 l:=1;
 for i:=n downto 1 do
  begin
   for j:=1 to n do
    if (x[i,j]=o) and (o<>0) then
     begin
      v3[l]:=v1[i];
      inc(l);
      dec(o);
     end;
  end;
 dec(l);
 assign(f,'cmlsc.out');
 append(f);
 for i:=l downto 1 do write(f,v3[i],' ');
 close(f);
end.
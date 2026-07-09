program ssaf;
var f,g:text;
i,j,n,m,k:integer;
v:array[1..1025,1..1025] of integer;
a,b,rez:array[1..260] of integer;
function max(x,y:longint):longint;
  begin
    if x>y then max:=x else max:=y;
  end;
begin
assign(f,'cmlsc.in'); reset(f);
assign(g,'cmlsc.out'); rewrite(g);
readln(f,m,n);
  for i:=1 to m do
    read(f,a[i]);
  for i:=1 to n do
     read(f,b[i]);
  for i:=1 to m do
    for j:=1 to n do
       begin
         if a[i]=b[j] then
          v[i,j]:=v[i-1,j-1]+1
          else
          v[i,j]:=max(v[i-1,j],v[i,j-1]);
       end;
  writeln(g,v[m,n]);
  i:=m;
  j:=n;
    for k:=v[m,n] downto 1 do
      begin
        while v[i,j]=v[i-1,j] do i:=i-1;
        while v[i,j]=v[i,j-1] do j:=j-1;
        rez[k]:=a[i];
        i:=i-1;
      end;
    for i:=1 to v[m,n] do
      write(g,rez[i],' ');
close(f);
close(g);
end.
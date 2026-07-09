program cmlsc;
type vector=array[1..1024] of integer;
     matrice=array[0..1024,0..1024] of integer;
var a,b,sol:vector;
    t:matrice;
    m,n,f,g,c:integer;
    i,o:text;
procedure scrie(x,y:integer);
begin
  if (x>0)and(y>0) then
    if a[x]=b[y] then
      begin
        scrie(x-1,y-1);
        write(o,a[x],' ')
      end
    else
      if (t[x-1,y]>=t[x,y-1]) then
        scrie(x-1,y)
      else
        scrie(x,y-1)
end;
begin
  c:=0;
  assign(i,'cmlsc.in');reset(i);
  assign(o,'cmlsc.out');rewrite(o);
  read(i,m,n);
  for f:=1 to m do
    begin
      read(i,a[f]);
      t[f,0]:=0
    end;
  for f:=1 to n do
    begin
      read(i,b[f]);
      t[0,f]:=0
    end;
  for f:=1 to m do
    for g:=1 to n do
      if a[f]=b[g] then
          t[f,g]:=t[f-1,g-1]+1
      else
        if t[f-1,g]>=t[f,g-1] then
          t[f,g]:=t[f-1,g]
        else
          t[f,g]:=t[f,g-1];
  writeln(o,t[f,g]);
  scrie(f,g);
  close(o)
end.

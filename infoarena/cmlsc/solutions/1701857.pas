var x,i,j,bst,n,m:integer;
a,b,sir:array [0..1024] of integer;
d:array [0..1024,0..1024] of integer;

function maxim(a,b:integer):integer;
begin
  if a>b then maxim:=a else maxim:=b;
end;

procedure lire;
var i:integer;
begin
  assign(input,'cmlsc.in');
  reset(input);
  read(m,n);
  for i:=1 to m do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  close(input);
end;

procedure ecrire;
var i:integer;
begin
  assign(output,'cmlsc.out');
  rewrite(output);
  writeln(bst);
  for i:=bst downto x do
    write(sir[i]);
  close(output);
end;

begin
  lire;
  for i:=1 to m do
    for j:=1 to n do
      if (a[i]=b[j]) then d[i,j]:=1+d[i-1,j-1] else d[i,j]:=maxim(d[i-1,j],d[i,j-1]);
  i:=m;
  while (j=n) do
    if (a[i]=b[j]) then begin bst:=bst+1; sir[bst]:=a[i]; i:=i-1; j:=j-1; end else
      if d[i-1,j]<d[i,j-1] then j:=j-1 else i:=i-1;
  ecrire;
  x:=i;
  ecrire;
end.
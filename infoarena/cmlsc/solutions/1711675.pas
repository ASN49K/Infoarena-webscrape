var q,a,b:array [0..1024] of integer;
d:array [0..1024,0..1024] of integer;
i,j:integer;

function mm(a,b:integer):integer;
begin
  if a>b then mm:=a else mm:=b;
end;

procedure lire;
var i:integer;
begin
  assign(input,'cmlsc.in');
  reset(input);
  readln(a[0],b[0]);
  for i:=1 to a[0] do
    read(a[i]);
  for i:=1 to b[0] do
    read(b[i]);
  close(input);
end;

procedure ecrire;
var i:integer;
begin
  assign(output,'cmlsc.out');
  rewrite(output);
  writeln(q[0]);
  for i:=q[0] downto 1 do
    write(q[i],' ');
  close(output);
end;

begin
  lire;
  for i:=1 to a[0] do
    for j:=1 to b[0] do
      if a[i]=b[j] then d[i,j]:=d[i-1,j-1]+1 else d[i,j]:=mm(d[i-1,j],d[i,j-1]);
  i:=a[0]; j:=b[0];
  while (i<>0) and (j<>0) do
    if a[i]=b[j] then begin q[0]:=q[0]+1; q[q[0]]:=a[i]; i:=i-1; j:=j-1; end
  else begin if d[i-1,j]>d[i,j-1] then i:=i-1 else j:=j-1; end;
  ecrire;
end.
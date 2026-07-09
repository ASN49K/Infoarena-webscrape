
var m,n,k:integer;
    a,b,sir:array[1..1024] of integer;
    d:array[0..1024,0..1024] of integer;
    
function maxim(a, b:integer):integer;
begin
  if a > b
  then maxim:=a
  else maxim:=b;
end;

procedure init;
var f:text; i:integer;
begin
  assign(f, 'cmlsc.in');
  reset(f);
  read(f,n,m);
  for i:=1 to n do read(f,a[i]);
  for i:=1 to m do read(f,b[i]);
  close(f);
end;

procedure calc;
var i,j:integer;
begin
  fillchar(d, sizeof(d), 0);
  for i:=1 to n do
    for j:=1 to m do
        if a[i]=b[j]
        then d[i,j]:=1+d[i-1,j-1]
        else d[i,j]:=maxim(d[i-1,j], d[i,j-1]);
  i:=n; j:=m; k:=0;
  while (i>0)and(j>0) do
  begin
    if a[i]=b[j]
    then begin inc(k); sir[k]:=a[i]; dec(i); dec(j); end
    else if d[i-1,j] < d[i,j-1]
         then dec(j)
         else dec(i);
  end;
end;

procedure rez;
var f:text; i:integer;
begin
  assign(f, 'cmlsc.out');
  rewrite(f);
  writeln(f,k);
  for i:=k downto 1 do write(f, sir[i],' ');
  close(f);
end;

begin
  init;
  calc;
  rez;
end.

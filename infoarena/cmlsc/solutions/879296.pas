var a:array[0..1024,0..1024]of longint;
    x,y,z:array[1..1024] of longint;
    n,m,k:longint;     
    
procedure init;
var i:longint; f:text;
begin
  assign(f, 'cmlsc.in');
  reset(f);
  readln(f,n,m);
  for i:=1 to n do read(f, x[i]);
  for i:=1 to m do read(f, y[i]);
  close(f);
end;


function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;

procedure solve;
var i,j,i1,j1:longint;
begin
  for i:=0 to n do
    for j:=0 to m do
      a[i,j]:=0;
      
  for i:=1 to n do
    for j:=1 to m do
      if x[i]=y[j]
      then a[i,j]:=a[i-1,j-1]+1
      else a[i,j]:=max(a[i-1,j], a[i,j-1]);
  k:= a[n,m];  i1:=n; j1:=m; 
  for i:=k downto 1 do
  begin
    while a[i1-1,j1]=a[i1,j1] do dec(i1);
    while a[i1,j1-1]=a[i1,j1] do dec(j1);
    z[i]:=x[i1];
    dec(i1); dec(j1);
  end;
  
  
end;


procedure finish;
var i:longint; f:text;
begin
  assign(f, 'cmlsc.out');
  rewrite(f);
  writeln(f,k);
  for i:=1 to k do write(f,z[i],' ');    
  close(f);
end;

    
begin
  init;
  solve;
  finish;
end.
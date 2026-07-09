var a:array [1..101] of boolean;
t:byte;

procedure lire;
var i:byte; j,n,x:longint;
b:array [1..10001] of longint;
begin
  assign(input,'nim.in');
  reset(input);
  read(t);
  for i:=1 to t do
  begin
    read(n);
    for j:=1 to n do
      read(b[j]);
    if (n=1) or (n=2) then a[i]:=true;
    if (n>2) then
    begin
      x:=b[1] xor b[2];
      for j:=3 to n do
        x:=x xor b[j];
      a[i]:=x<>0;
    end;
  end;
  close(input);
end;

procedure ecrire;
var i:longint;
begin
  assign(output,'nim.out');
  rewrite(output);
  for i:=1 to t do
    if a[i] then writeln('DA') else writeln('NU');
  close(output);
end;

begin
  lire;
  ecrire;
end.
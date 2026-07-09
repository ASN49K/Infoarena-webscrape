var a:array [1..101] of boolean;
t:byte;

procedure lire;
var i:byte; j,n,x,b:longint;
begin
  assign(input,'nim.in');
  reset(input);
  read(t);
  for i:=1 to t do
  begin
    read(n);
    a[i]:=n in [1,2];
    if (n>2) then
    begin
      x:=0;
      for j:=1 to n do
      begin
        Read(b);
        x:=x xor b;
      end;
      a[i]:=x<>0;
    end else
    for j:=1 to n do
      read(b);
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
var a:array [1..101] of boolean;
t:byte;

procedure lire;
var i:byte; j,n,x,b:longint; q:boolean;
begin
  assign(input,'nim.in');
  reset(input);
  read(t);
  for i:=1 to t do
  begin
    read(n);
    q:=true;
    if (n=2) or (n=1) then a[i]:=true else
    begin
      x:=0;
      q:=false;
      for j:=1 to n do
      begin
        Read(b);
        x:=x xor b;
      end;
      if x<>0 then a[i]:=true;
    end;
    if q then
    for j:=1 to n do
      read(b);
  end;
end;

procedure ecrire;
var i:longint;
begin
  assign(output,'nim.out');
  rewrite(output);
  for i:=1 to t do
    if a[i] then writeln('DA') else writeln('NU');
end;

begin
  lire;
  ecrire;
end.
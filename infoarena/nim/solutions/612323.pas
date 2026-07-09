program Nim;
var t,n,x,S:longint;
    i,j:longint;

begin
  assign(input,'nim.in');
  reset(input);
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    S:=0;
    for j:=1 to n do
    begin
      read(x);
      S:=S xor x;
    end;
    if S>0 then writeln('DA')
    else writeln('NU');
    readln;
  end;
  close(input);
end.
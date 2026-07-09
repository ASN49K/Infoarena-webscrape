program euclid;
var t,i:byte;
    a,b,d,j:longint;
    f,g:text;

begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);rewrite(g);
readln(f,t);
for i:=1 to t do
  begin
  readln(f,a,b);
  if a<b then
    begin
    d:=1;
    for j:=2 to a do
    if (a mod j=0)and(b mod j=0) then d:=j
    end
      else
    begin
    for j:=2 to b do
    if (a mod j=0)and(b mod j=0) then d:=j
    end;
  writeln(g,d);
  end;
close(f);close(g);
end.

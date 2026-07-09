program euclid;
var t,i:byte;
    x,y,d,j:longint;
    f,g:text;

begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);rewrite(g);
readln(f,t);
for i:=1 to t do
  begin
  readln(f,x,y);
  if x<y then
    begin
    d:=1;
    for j:=2 to x do
    if (x mod j=0)and(y mod j=0) then d:=j
    end
      else
    begin
    for j:=2 to y do
    if (x mod j=0)and(y mod j=0) then d:=j
    end;
  writeln(g,d);
  end;
close(f);close(g);
end.

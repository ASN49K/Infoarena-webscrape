var x,y,t:int64;
    f,fo:text;
    ta:longint;
    i:longint;
    gasit :boolean;

begin


assign(f,'euclid2.in');reset(f);
readln(f,t);
assign(fo,'euclid2.out');
rewrite(fo);

for i := 1 to t do
begin
readln(f,x,y);

if (x=0)or (y=0) then writeln(fo,'0')
else
begin

{if x <> y then
repeat
  if x<y then
    y := y -x
  else
    x := x - y;
until x=y ;
writeln(fo,x);}

  gasit := false;
  repeat
    if y mod x = 0 then gasit := true
    else
    begin
      y := y mod x;
      ta := x;
      x := y;
      y := ta;
    end;
  until gasit = true;

end;
end;



close(fo);close(f);


end.

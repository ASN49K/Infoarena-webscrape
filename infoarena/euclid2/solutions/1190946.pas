Program ex;
Var i,y,t,x:longint;
    f,g:text;
function cmmdc(x,y:integer):integer;
 begin
 while x<>y do
  if x>y then x:=x-y
   else y:=y-x;
 cmmdc:=x;
 end;
begin
assign (f,'euclid2.in');
reset(f);
assign (g,'euclid2.out');
rewrite(g);
readln(f,t);
for i:=1 to t do begin
 readln(f,x,y);
 writeln (g,cmmdc(x,y));
 end;
close(f);
close(g);
end.
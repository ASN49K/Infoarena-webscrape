program Euclid2; {CMMDC}

var a,b,t,c:longint;
    f,g:text;

function cmmdc(x,y:longint):longint;
begin
if y = 0 then cmmdc:=x
         else cmmdc:=cmmdc(y,x mod y);
end;

Begin
assign(f,'euclid2.in'); reset(f); readln(f,t);
assign(g,'euclid2.out'); rewrite(g);
 while not EOF(f) do
  begin
  readln(f,a,b);
  c:=cmmdc(a,b);
  writeln(g,c);
  end;
close(f); close(g);
end.

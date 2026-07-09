program Euclid2; {CMMDC}

var a,b,t,i:longint;
    f,g:text;

function cmmdc(x,y:longint):longint;
begin
if y = 0 then cmmdc:=x
         else cmmdc(y,x mod y);
end;

Begin
assign(f,'euclid2.in'); reset(f); readln(f,t);
assign(g,'euclid2.out'); rewrite(g);
 for i := 1 to t do
  begin
  readln(f,a,b);
  writeln(g,cmmdc(a,b));
  end;
close(f); close(g);
end.
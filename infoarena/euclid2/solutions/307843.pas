type big=0..2000000000;
     small=0..100000;
var f,g:text;
    x,y:big;
    t,i:small;


function cmmdc(a,b:big):big;
begin

if (b>0) then cmmdc:=cmmdc(b,a mod b)
         else cmmdc:=a;

end;

BEGIN
assign(f,'euclid2.in'); reset(f);
 readln(f,t);
 assign(g,'euclid2.out'); rewrite(g);
  for i:=1 to t do
      begin
      read(f,x); readln(f,y);
      writeln(g,cmmdc(x,y));
      end;
 close(g);
close(f);
END.

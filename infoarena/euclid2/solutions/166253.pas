{ http://infoarena.ro/problema/euclid2 }
var f,g:text;
    t,a,b,i:longint;
function cmmdc(a,b:longint):longint;
var r:longint;
begin
        repeat
           r:=a mod b;
           a:=b;
           b:=r;
        until r=0;
        cmmdc:=a;
end;
BEGIN
   assign(f,'euclid2.in'); reset(f);
   assign(g,'euclid2.out'); rewrite(g);
   readln(f,t);
   for i:=1 to t do
        begin
        read(f,a,b);
        writeln(g,cmmdc(a,b));
        end;
   close(f); close(g);
END.



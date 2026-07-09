var a,b,n,x:longint;
   i,o:text;
function cmmdc(a,b:longint):longint;
begin
 if a mod b = 0 then cmmdc:=a;
                else cmmdc:=cmmdc(b,a mod b);
end;

begin
 assign (i,'euclid2.in'); reset(i);
 assign (o,'euclid2.out'); rewrite(o);
 readln (i,x);
 for n:=1 to x do
  begin
   readln(i,a,b);
   writeln(o,cmmdc(a,b));
  end;
 close(i);
 close(o);
end.
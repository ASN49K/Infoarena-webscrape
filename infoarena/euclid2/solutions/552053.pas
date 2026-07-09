var t,i:integer; x,y:int64; f1,f2:text;


function cmmdc(a,b:int64):int64;
begin
 if b=0 then cmmdc:=a else
  cmmdc:=cmmdc(b,a mod b);
end;

begin
 assign(f1,'euclid2.in');
 reset(f1);
 assign(f2,'euclid2.out');
 rewrite(f2);
 readln(t);
 for i:=1 to t do
  begin
   readln(x,y);
   writeln(cmmdc(x,y));
  end;
 close(f2);
 close(f1);
end.
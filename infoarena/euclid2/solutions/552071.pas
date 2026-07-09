var t,i,x,y,c:longint; f1,f2:text;


function cmmdc(a,b:longint):longint;
begin
 if b=0 then cmmdc:=a else
  cmmdc:=cmmdc(b,a mod b);
end;

begin
 assign(f1,'euclid2.in');
 reset(f1);
 assign(f2,'euclid2.out');
 rewrite(f2);
 readln(f1,t);
 for i:=1 to t do
  begin
   readln(f1,x,y);
   c:=cmmdc(x,y);
   writeln(f2,c);
  end;
 close(f1);
 close(f2);
end.
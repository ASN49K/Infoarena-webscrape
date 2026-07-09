function cmmdc(a,b:longint):longint;
begin
 while a<>b do
  if a>b then
   a:=a-b
   else
    b:=b-a;
 cmmdc:=a;
end;

var a,b,t,i:longint;
    f1,f2:text;

begin
 assign(f1,'euclid2.in');
 assign(f2,'euclid2.out');
 reset(f1); rewrite(f2);
 readln(f1,t);
 for i:=1 to t do
  begin
   read(f1,a,b);
   writeln(f2,cmmdc(a,b));
   readln(f1);
  end;
 close(f1);
 close(f2);
end.

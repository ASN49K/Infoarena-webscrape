program p1;
var i,a,b,d,n:longint;
    f1,f2:text;

Function dvz(a,b:longint):integer;
 begin
  while d<>0 do
   begin
    d:=a mod b;
    a:=b;
    b:=d;
   end;
  dvz:=d;
 end;

Begin
 assign(f1,'euclid2.in'); reset(f1);
 assign(f2,'euclid2.out'); rewrite(f2);
 readln(f1,n);

 for i:=1 to n do
  begin
   readln(f1,a,b);
   writeln(f2,dvz(a,b));
  end;

 close(f1); close(f2);
End.

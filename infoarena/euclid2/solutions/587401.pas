program p1;
var a,b,d:longint;
    f1,f2:text;

Function dvz(a,b:longint):integer;
 begin
 if b=0 then dvz:=a
        else dvz:=dvz(b,a mod b);
 end;

Begin
 assign(f1,'euclid2.in'); reset(f1);
 assign(f2,'euclid2.out'); rewrite(f2);
 write('a='); readln(a);
 write('b='); readln(b);
 writeln(dvz(a,b));
 close(f1); close(f2);
End.

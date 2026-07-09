Program eculid2;

Var

  a,b,i,t,r:longint;
  f1,f2:text;

Begin

Assign (f1,'euclid2.in');
Reset  (f1);
Assign (f2,'euclid2.out');
Rewrite(f2);

Readln (f1,t);

For i:=1 to t do

 begin

 Readln (f1,a,b);
 r:=a mod b;

 While r <> 0 do

     begin

     a:=b;
     b:=r;
     r:=a mod b;

     end;

 Writeln (f2,b);

 end;

Close (f1);
Close (f2);

end.
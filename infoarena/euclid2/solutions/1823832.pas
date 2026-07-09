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

 While b <> 0 do
 begin
     r:=a mod b;
     a:=b;
     b:=r;

       end;

 Writeln (f2,a);
 end;
Close (f1);
Close (f2);

end.
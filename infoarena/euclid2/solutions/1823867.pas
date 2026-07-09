Program eculid2;

Var
  rr:longint;
  a,b,i,t:longint;
  f1,f2:text;
  procedure cmmdc(x,y:longint; var rez:longint);
   var r:longint  ;

   begin

  While y<>0 do

        Begin
        r:=x mod y;
        x:=y;
        y:=r;
         end;
  rez:=x
  end;

Begin

Assign (f1,'euclid2.in');
Reset  (f1);
Assign (f2,'euclid2.out');
Rewrite(f2);

Read (f1,t);

For i:=1 to t do

 begin

 Read (f1,a,b);
 cmmdc (a,b,rr);

 Writeln (f2,rr);
 end;

Close (f2);

end.
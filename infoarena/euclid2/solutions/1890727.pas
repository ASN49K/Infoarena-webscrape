VAR

   f,g : Text;
   i,n,a,b : LongInt;

Function Kozos_Oszto (a,b : LongInt) : LongInt;
Begin
     If b=0 then Kozos_Oszto := a
            else Kozos_Oszto := Kozos_Oszto(b, a mod b);
End;

BEGIN

     Assign(f,'euclid2.in'); reset(f);
     Assign(g,'euclid2.out'); rewrite(g);

     ReadLn(f,n);

     For i:=1 to n do
       begin
         Read(f,a);
         Read(f,b);
         WriteLn(g,Kozos_Oszto(a,b));
       end;

     Close(f);
     Close(g);

END.
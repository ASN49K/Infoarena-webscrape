program Euclid;
var
  fl1, fl2 : text;
  n : longint;
  a, b, i : longint;

function cmmdc(in1, in2:longint):longint;
var
   cm1, cm2, k : longint;
begin
  cm1 := in1;
  cm2 := in2;
  while cm2 > 0 do
     begin
        k := cm2;
        cm2 := cm1 mod cm2;
        cm1 := k;
     end;
   cmmdc := cm1;
end;
begin
   assign(fl1,'euclid2.in');
   assign(fl2,'euclid2.out');
   rewrite(fl2);
   reset(fl1);
   readln(fl1,n);
   for i := 1 to n do
      begin
         readln(fl1,a,b);
         writeln(fl2,cmmdc(a,b));
      end;
   close(fl1);
   close(fl2);

end.

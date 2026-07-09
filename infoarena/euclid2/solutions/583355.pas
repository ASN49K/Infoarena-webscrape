program euclid2;
 var m1,m2:longint; n,i:integer; f1,f2:text;

function euclid(n,m:longint):longint;
 begin
  if n=0 then euclid:=m else
  euclid:=euclid(m mod n,n)
 end;
begin
 assign(f1,'euclid2.in');
 reset(f1);
 readln(f1,n);
 assign(f2,'euclid2.out');
 rewrite(f2);
 for i:=1 to n do
  begin
   read(f1,m1); read(f1,m2);
   writeln(f2,euclid(m1,m2));
  end;
 close(f1);
 close(f2);
end.

program euclid2;
var n,a,b,i:longint;
    f1,f2:text;

function cmmdc(a,b:longint):longint;
    begin
     if a=0 then cmmdc:=b;
     if b=0 then cmmdc:=a;
     if (a<>0)and(b<>0) then
        if a=b then cmmdc:=a
        else
        cmmdc:=cmmdc(a mod b,b mod a);
    end;




begin
assign(f1,'euclid2.in'); reset(f1);
assign(f2,'euclid2.out'); rewrite(f2);
readln(f1,n);
for i:=1 to n do
   begin
   readln(f1,a,b);
   writeln(f2,cmmdc(a,b));
   end;
close(f2);
end.
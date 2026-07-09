const
        f1='euclid2.in';
        f2='euclid2.out';

function gcd(a,b:longint):longint;
var r:longint;
begin
 while b>0 do begin
  r:=a mod b;
  a:=b;
  b:=r;
 end;
gcd:=a;
end;

var t,i,a,b:longint;

begin
 assign(input,f1); reset(input);
 assign(output,f2); rewrite(output);
  readln(t);
   for i:=1 to t do begin
    readln(a,b);
    writeln(gcd(a,b));
   end;
 close(input);
 close(output);
end.

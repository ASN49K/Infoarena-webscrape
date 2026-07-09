const
        f1='euclid2.in';
        f2='euclid2.out';

function gcd(a,b:longint):longint;
begin
if b=0 then gcd:=a
       else gcd:=gcd(b,a mod b);
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

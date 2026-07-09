function euclid(a,b:longword):longword;
var r:longword;
begin
 repeat
   r:=a mod b;
   a:=b;
   b:=r;
 until r=0;
 euclid:=a;
end;

var be,ki:text;
 a,b,i,n:longword;
 
begin
 assign(be,'euclid.in');
 assign(ki,'euclid.out');
 reset(be);
 rewrite(ki);
 readln(be,n);
 for i:=1 to n do
  begin
   readln(be,a,b);
   writeln(ki,euclid(a,b));
  end;
 close(ki);
end.
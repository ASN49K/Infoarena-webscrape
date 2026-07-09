function euclid(a,b:longword):longword;inline;
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
 rbuf,wbuf:array[1..15000] of byte;
 
begin
 assign(be,'euclid2.in');
 assign(ki,'euclid2.out');
 settextbuf(be,rbuf);
 settextbuf(ki,wbuf);
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
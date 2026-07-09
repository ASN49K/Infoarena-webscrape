program cmmdc_infoarena;
var n,a,b,r:longint;
    bufin,bufout:array[1..100000] of byte;
    f,g:text;
begin
 assign(f,'euclid2.in'); reset(f);
 assign(g,'euclid2.out'); rewrite(g);
 SetTextBuf(f,bufin);
 SetTextBuf(f,bufout);
 readln(f,n);
 while n<>0 do
  begin
   readln(f,a,b);
   while b<>0 do
    begin
     r:=a mod b;
     a:=b;
     b:=r;
    end;
   writeln(g,a);
   n:=n-1;
  end;
 close(f);
 close(g);
end.

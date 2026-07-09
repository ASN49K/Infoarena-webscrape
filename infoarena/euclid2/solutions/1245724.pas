program cmmdc_infoarena;
var n,a,b,r:longint;
    f,g:text;

function dc(a,b:longint):integer;
begin
 if b=0 then
  dc:=a
 else
  dc:=dc(b,a mod b);
end;

begin
 assign(f,'euclid2.in'); reset(f);
 assign(g,'euclid2.out'); rewrite(g);
 readln(f,n);
 while n<>0 do
  begin
   readln(f,a,b);
   writeln(g,dc(a,b));
   n:=n-1;
  end;
 close(f);
 close(g);
end.
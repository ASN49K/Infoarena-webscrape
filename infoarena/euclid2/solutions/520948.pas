program arhiva000;
type tip1=2..2000000000;
     tip2=1..100000;
var a,b:tip1;
    t:tip2;
    f,g:text;

procedure euclid(a,b:tip1);
begin
 if b=0 then writeln(g,a)
                else euclid(b,(a mod b));
end;

begin
 assign(f,'euclid2.in'); assign(g,'euclid2.out');
 reset(f); rewrite(g);
 readln(f,t);
 while t<>0 do
  begin readln(f,a,b);
        if a>b then euclid(a,b)
               else euclid(b,a);
        t:=t-1;
  end;
 close(f);close(g);
end.

program arhiva000;
var a,b,t:longint;
    f,g:text;

procedure euclid(a,b:longint);
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

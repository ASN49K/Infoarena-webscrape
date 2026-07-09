program arhiva000;
var a,b,t,i:longint;
    f,g:text;

procedure euclid(a,b:longint);
begin
 if (a mod b)=0 then writeln(g,b)
                else euclid(b,(a mod b));
end;

begin
 assign(f,'euclid2.in'); assign(g,'euclid2.out');
 reset(f); rewrite(g);
 readln(f,t);
 for i:=1 to t do
  begin readln(f,a,b);
        if a>b then euclid(a,b)
               else euclid(b,a);
  end;
 close(f);close(g);
end.

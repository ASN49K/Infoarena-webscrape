program arhiva000;
type pereche=record
        a,b:integer;
        end;
var i,t,aux:integer;
    x:pereche;
    f,g:text;

procedure euclid;
begin

if x.a<x.b then
begin
 if (x.b mod x.a)=0 then writeln(g,x.a)
                    else
 begin
  x.b:=(x.b mod x.a);
  euclid;
 end;
end
           else
begin
 if (x.a mod x.b)=0 then writeln(g,x.b)
                    else
 begin
  x.a:=(x.a mod x.b);
  euclid;
 end;
end;

end;

begin
 assign(f,'euclid2.in'); assign(g,'euclid2.out');
 reset(f); rewrite(g);
 readln(f,t);
 for i:=1 to t do
    begin readln(f,x.a,x.b);
          euclid;
    end;
  close(f); close(g);
end.

program arhiva000;
type pereche=record
        a,b:integer;
        end;
var i,t,aux:integer;
    x:pereche;
    f,g:text;

procedure euclid(x:pereche);
begin
 if x.a<x.b then begin x.b:=x.b-x.a;
                       euclid(x);
                 end
    else if x.b<x.a then begin x.a:=x.a-x.b;
                               euclid(x);
                         end
                    else writeln(g,x.a);
end;

procedure euclid2(x:pereche);
begin
 if (x.a mod x.b)=0 then writeln(g,x.b)
                    else
 begin
  aux:=(x.a mod x.b);
  x.a:=x.b;
  x.b:=aux;
  euclid2(x);
 end;
end;

begin
 assign(f,'euclid2.in'); assign(g,'euclid2.out');
 reset(f); rewrite(g);
 readln(f,t);
 for i:=1 to t do
    begin readln(f,x.a,x.b);
          if x.a<x.b then begin aux:=x.a;
                                x.a:=x.b;
                                x.b:=aux;
                          end;
          euclid2(x);
    end;
 close(f); close(g);
end.

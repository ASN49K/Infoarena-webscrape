{ cel mai mare divizor comun }
program divizor;
var a,b,t:real;
    i:integer;
    f,g:text;

function cmmdc(a,b:real):real;
begin
   while (a>0)and(b>0) do
    if a>b then a:=a-b
       else b:=b-a;
   cmmdc:=a;
end;

begin

    assign(f,'euclid2.in');  reset(f);
    assign(g,'euclid2.out');   rewrite(g);
      readln(f,t);
        for i:=1 to t do begin
           readln(f,a,b);
           writeln(g,cmmdc(a,b));
                          end;
        close(f);
      close(g);
end.

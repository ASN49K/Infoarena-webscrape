program euclid;

var fin,fout:string;
    t,i:integer;
    a,b:longint;
    f,g:text;
procedure diviz(a,b:longint);
   begin
   if a=b then writeln(g,a)
          else
        if a>b then diviz(a-b,b)
               else diviz(a,b-a);
   end;

begin
fin:='euclid2.in';
fout:='euclid2.out';

assign(f,fin);
reset (f);
read(f,t);
assign(g,fout);
rewrite(g);
for i:=1 to t do
   begin
   read(f,a,b);
   diviz(a,b);
   end;
close(f);
close(g);
end.

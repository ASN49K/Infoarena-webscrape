uses crt;
var t,i,j,a,b,d,max:integer;
begin
clrscr;
        write('t= '); readln(t);
        for i:=1 to t do
                begin
                max:=-maxint;
                d:=1;
                        write('a= '); readln(a);
                        write('b= '); readln(b);
                        for j:=2 to max do
                                if (a mod j=0) and (b mod j=0) then d:=j;
                        writeln('Cel mai mare divizor comun= ',d);
                end;
readln;
end.

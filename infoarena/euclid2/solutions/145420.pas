program euclid2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var a,b,c:longint;
    fin,fout:text;
{/--------------*}
begin
        assign(fin,'euclid2.in'); reset(fin);
        assign(fout,'euclid2.out'); rewrite(fout);
        readln(fin,a,b);
{        while a <> b do
                if a > b then a:=a-b
                else b:=b-a;    }
        c:=a mod b;
        while c<>0 do
        begin
                a:=b;
                b:=c;
                c:=a mod b;
        end;
        writeln(fout,b);
        close(fin);
        close(fout);
end.
 
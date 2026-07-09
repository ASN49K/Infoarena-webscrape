program euclid2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var a,b:longint;
    fin,fout:text;
{/--------------*}
begin
        assign(fin,'euclid2.in'); reset(fin);
        assign(fout,'euclid2.out'); rewrite(fout);
        readln(fin,a,b);
        while a <> b do
                if a > b then a:=a-b
                else b:=b-a;
        writeln(fout,a);
        close(fin);
        close(fout);
end.
 
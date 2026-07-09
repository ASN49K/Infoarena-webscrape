var fin,fout:text;
    i,n,a,b,rest:longint;

begin
 assign(fin,'euclid2.in');
 assign(fout,'euclid2.out');
 reset(fin);
 rewrite(fout);
 read(fin,n);
 for i:=1 to n do
    begin
    read(fin,a,b);
       repeat
       rest:=a mod b;
       a:=b;
       b:=rest;
       until rest=0;
    writeln(fout,a);
    end;
 close(fin);
 close(fout);
end.
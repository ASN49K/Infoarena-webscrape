program euclidian;
var
 a,b,r,n,i:longint;
 fin,fout:text;
begin
 assign(fin,'euclid2.in');
 reset(fin);
 readln(fin,n);
 assign(fout,'euclid2.out');
 rewrite(fout);
 for i:=1 to n do
  begin
   readln(fin,a,b);
   while b<>0 do
    begin
     r:=a mod b;
     a:=b;
     b:=r;
    end;
   writeln(fout,a);
  end;
 close(fin);
 close(fout);
end.
program euclidian;
var
 t,a,b,i,c,min:longint;
 fin,fout:text;
begin
 assign(fin,'euclid2.in');
 reset(fin);
 readln(fin,t);
 assign(fout,'euclid2.out');
 rewrite(fout);
 for i:=1 to t do
  begin
   readln(fin,a,b);
   c:=a;
   min:=b;
   if b>a then
    begin
     min:=a;
     c:=b;
    end;
   while (a mod c<>0) or (b mod c<>0) do
    c:=c-min;
   writeln(fout,c);
  end;
 close(fin);
 close(fout);
end.
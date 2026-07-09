program euclid;
var a,b,t,i: integer;
    fin,fout: text;
function euclid(a: integer; b: integer) :integer;
begin
 while a <> b do
      if a>b then
        a:=a-b
      else
        b:=b-a;
 euclid:= a;
end;


begin
 assign(fin,'euclid2.in');
 assign(fout,'euclid2.out');
 reset(fin);
 rewrite(fout);
 readln(fin,t);
 for i:=1 to t do
   begin
     read(fin,a);
     readln(fin,b);
     writeln(fout,euclid(a,b));
   end;


 close(fin);
 close(fout);
end.
program euclid;
 var t:qword;
     f,g:text;
     a,b:int64;
function cmmdc(a,b:int64):int64;
 begin
  while b<>0 do if a>b then a:=a-b
                else b:=b-a;
  cmmdc:=b;
 end;
begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,t);
 for i:=1 to n do
  begin
   readln(f,a,b);
   writeln(f,cmmdc(a,b));
  end;
 close(f);
 close(g);
end.
program divizor;
var a,b,temp,i,n:integer;
in_f,out_f:text;
begin
  assign(in_f,'euclid2.in');
  assign(out_f,'euclid2.out');
  reset(in_f);
  rewrite(out_f);
  readln(n);
  for i := 1 to n  do
    begin
  readln(a,b);
  
  while b <> 0 do
  begin
     temp := b;
    b := a mod b;
    a := temp;
  end;
  
writeln(out_f,a);
end;
end.
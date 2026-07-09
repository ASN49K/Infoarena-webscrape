var a,b:int64;

begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);

readln(a);
readln(b);

while (a<>0) and (b<>0) do
      begin
      if a>b then a:=a mod b
             else b:=b mod a;
      end;

if a=0 then write(b)
       else write(a);

close(input);
close(output);

end.
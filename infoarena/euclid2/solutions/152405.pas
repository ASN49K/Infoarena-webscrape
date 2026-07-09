var a,b,min1,max1:longint;

begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);

readln(a);
readln(b);

while a<>b do
      begin
      if a>b then a:=a-b
             else b:=b-a;
      end;

if a=1 then write(0)
       else write(a);

close(input);
close(output);

end.
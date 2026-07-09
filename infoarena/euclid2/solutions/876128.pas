var a,b,t:int64; 
    r,i:longint;
    bufin,bufout:array[1..65000]of byte;
begin
assign(input,'euclid2.in');
reset(input);
assign(output,'euclid2.out');
rewrite(output);

settextbuf(input,bufin);
settextbuf(output,bufout);
readln(t);
for i:=1 to t do
begin
readln(a,b);
a:=a mod b;
while a<>0 do begin
              r:=b mod a;
              b:=a;
              a:=r;
              end;  
writeln(b);
end;
close(output);
close(input);
end.

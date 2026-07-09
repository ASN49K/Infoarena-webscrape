var f,fo:text;
      i,t:byte;
      j,n:word;
      s,x:longint;
begin
assign(f,'nim.in');
assign(fo,'nim.out');
reset(f);
rewrite(fo);
readln(f,t);
for i:=1 to t do
 begin 
  readln(f,n);s:=0;
  for j:=1 to n do
   begin
    read(f,x);
    s:=s xor x;
   end;
  if s=0 then writeln(fo,'NU')   
            else writeln(fo,'DA');	 	
  readln(f);
 end;
close(fo);
close(f);
end.
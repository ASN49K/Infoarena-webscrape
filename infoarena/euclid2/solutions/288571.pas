 var a,b,min,i,cmmdc,nr,j:integer;

 begin
 assign(input,'euclid2.in');
 assign(output,'euclid2.out');
 reset(input);
 rewrite(output);

 read(nr);
 for j:=1 to nr do begin

 readln(a,b);
 if a<b then min:=a else min:=b;

 for i:=1 to min do begin
  if (a mod i=0)and(b mod i=0) then cmmdc:=i;
  end;
  if cmmdc=1 then write('0') else writeln(cmmdc);
  end;
  close(input);
  close(output);
  end.

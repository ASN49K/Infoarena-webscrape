program finfo;
var t,i,d,a,b,max,l:integer;
    ok1,ok2:boolean;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out'); rewrite(output);
readln(t);
for i:=1 to t do begin
  readln(a,b);
  if a>b then max:=b
  else max:=a;
  for l:=max downto 1 do begin
    ok1:=false; ok2:=false;
    //if a>l then
       if a mod l=0 then ok1:=true;
    //else if l mod a=0 then ok1:=true;
    //if b>l then
       if b mod l=0 then ok2:=true;
    //else if l mod b=0 then ok2:=true;
    if (ok1)and(ok2) then break;
  end;
  writeln(l);
end;
close(output);
end.
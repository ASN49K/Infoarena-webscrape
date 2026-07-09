program euclid;

  var t,a,b,x,i:longint;


function cmmdc(a,b:longint):longint;

  begin
    if b=0 then cmmdc:=a
           else cmmdc:=cmmdc(b,a mod b);
  end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);

  readln(t);
  for i:=1 to t do
    begin
      readln(a,b);
      if a<b then
        begin
          x:=a;
          a:=b;
          b:=x;
        end;
      writeln(cmmdc(a,b));
    end;

  close(output);
end.
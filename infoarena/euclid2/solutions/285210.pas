program suma;
const fin = 'euclid2.in';
      fout = 'euclid2.out';
var r,a,b:integer;
begin
  {citire}
  assign(input,fin);
  assign(output,fout);
  reset(input);
  rewrite(output);
  readln(a);
  while not(eof()) do
  begin
    readln(a,b);
    while b>0 do
    begin
      r:=a mod b;
      a:=b;
      b:=r;
    end;
    writeln(a);
  end;

  {tipar}




  close(input);
  close(output);
end.

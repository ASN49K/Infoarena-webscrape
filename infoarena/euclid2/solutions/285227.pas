program suma;
const fin = 'euclid2.in';
      fout = 'euclid2.out';
var r,a,b:int64;
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
    if b<a then
    begin
      while b>0 do
      begin
        r:=a mod b;
        a:=b;
        b:=r;
      end;
      writeln(a);
    end
    else
    begin
      while a>0 do
      begin
        r:=b mod a;
        b:=a;
        a:=r;
      end;
      writeln(b);
    end;
  end;

  {tipar}




  close(input);
  close(output);
end.

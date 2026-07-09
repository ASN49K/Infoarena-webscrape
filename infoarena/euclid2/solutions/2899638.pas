program adunare;

{$MODE objfpc}{$H+}{$J-}
uses sysutils;

function Euclid2(a, b: longint): longint;
var
  temp: longint;
begin
  while b <> 0 do
  begin
    temp := b;
    b := a mod b;
    a := temp;
  end;
  result := a;
end;

const
  C_IN_FNAME = 'euclid2.in';
  C_OUT_FNAME = 'euclid2.out';
var
  fin, fout: text;
  n, a, b : longint;
begin
  AssignFile(fin, C_IN_FNAME);
  AssignFile(fout, C_OUT_FNAME);
  Reset(fin);
  Readln(fin, n);
  Rewrite(fout);
  while not Eof(fin) do
  begin
    Readln(fin, a, b);
    Writeln(fout, IntToStr(Euclid2(a, b)));
  end;
  CloseFile(fin);
  CloseFile(fout);
end.

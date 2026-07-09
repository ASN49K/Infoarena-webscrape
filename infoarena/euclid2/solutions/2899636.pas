program adunare;

{$MODE objfpc}{$H+}{$J-}
uses sysutils;

function Euclid2(a, b: longint): longint;
begin
  if b = 0 then
    Euclid2 := a
  else
    Euclid2 := Euclid2(b, a mod b);
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

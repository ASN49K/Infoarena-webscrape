{$M 64000000,0}
{$H-,I-,Q-,R-,S-}
{La Hoang
Ngay 3-3-2010}
const
   TFI  = 'euclid2.in';
   TFO  = 'euclid2.out';
var
   fi, fo: text;
   T, a, b: longint;
   (*-----------------------------------*)
   function Ucln(a, b: longint): longint;
   var
      i: longint;
   begin
      if b = 0 then exit(a);
      if a > b then exit(Ucln(b, a mod b)) else exit(Ucln(a, b mod a));
   end;
   (*-----------------------------------*)
begin
   Assign(fi, TFI); Reset(fi);
   Assign(Fo, TFO); Rewrite(fo);
   Readln(fi, T);
   While t > 0 do
      begin
         dec(t);
         Readln(fi, a, b);
         Writeln(fo, Ucln(a, b));
      end;
   Close(fo);
   Close(fi);
end.
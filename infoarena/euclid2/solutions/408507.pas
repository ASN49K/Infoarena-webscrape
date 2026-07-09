{$M 64000000,0}
{$H-,I-,Q-,R-,S-}
{La Hoang
Ngay 3-3-2010}
const
   TFI  = 'euclid2.in';
   TFO  = 'euclid2.out';
var
   fi, fo: text;
   T, a, b, R: longint;
   (*-----------------------------------*)
   procedure process;
   var
      i: longint;
   begin
      while b > 0 do
       begin
         i := a mod b;
         a := b;
         b := i;
       end;
      R := a;
   end;
begin
   Assign(fi, TFI); Reset(fi);
   Assign(Fo, TFO); Rewrite(fo);
   Readln(fi, T);
   While t > 0 do
      begin
         dec(t);
         Readln(fi, a, b);
         Process;
         Writeln(fo, r);
      end;
   Close(fo);
   Close(fi);
//   writeln(5 mod 7);
end.
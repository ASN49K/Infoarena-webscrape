{$M 64000000,0}
{$H-,I+,Q+,R+,S+}
{La Hoang
Ngay 3-3-2010}
const
   TFI  = 'euclid2.in';
   TFO  = 'euclid2.out';
var
   fi, fo: text;
   T, a, b, R: longint;
   (*-----------------------------------*)
   procedure Input;
   begin
      Readln(fi, a, b);
   end;
   (*-----------------------------------*)
   procedure process;
   var
      i: longint;
   begin
      repeat
         r := a mod b;
         a := b;
         b := r;
      until b = 0;
      R := a;
   end;
   (*-----------------------------------*)
   procedure Output;
   begin
      Writeln(fo, R);
   end;
   (*-----------------------------------*)
begin
   Assign(fi, TFI); Reset(fi);
   Assign(Fo, TFO); Rewrite(fo);
   Readln(fi, T);
   While t > 0 do
      begin
         dec(t);
         Input;
         Process;
         Output;
      end;
   Close(fo);
   Close(fi);
end.
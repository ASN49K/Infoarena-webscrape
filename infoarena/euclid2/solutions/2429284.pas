Program euclidalgoritm;

var a,b : integer;
    t, i : byte;
    inp, outp : text;

 function gcd(x,y : integer) : integer;

  var r : integer;

 begin

  while (y <> 0) do
   begin
   r := y;
   y := x mod y;
   x := r;
   end;
  gcd := x;
  end;

begin
 assign(inp, 'euclid2.in');
 assign(outp, 'euclid2.out');
 reset(inp);
 rewrite(outp);

 readln(inp, t);

  for i:= 1 to t do
   begin
    read(inp, a);
    readln (inp, b);
    writeln(outp, gcd(a,b));

   end;

 close(inp);
 close(outp);
 readln;

 end.





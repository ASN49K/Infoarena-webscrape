program algoritmul_lui_euclid;

const tmax=100000;

type mare=0..2000000000;

var f,g:text;
    t1,t:0..tmax;
    a,b,c:mare;

function cmmdc(a,b:mare) :mare;
   begin
      if (b=a)or(b=0) then cmmdc:=a
      else
         cmmdc:=cmmdc(b,a mod b);
   end;


begin
   assign(f,'euclid2.in'); reset(f);
   assign(g,'euclid2.out'); rewrite(g);
   read(f,t);

   for t1:=1 to t do
      begin

         read(f,a,b);
         if b>a then
            begin
               c:=a;
               a:=b;
               b:=c;
            end;
         writeln(g,cmmdc(a,b));

      end;
   close(f);
   close(g);
end.
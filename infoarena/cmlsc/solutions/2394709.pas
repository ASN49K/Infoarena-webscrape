program lcs;
uses crt;
var i,j,k,max,a,b,aux,s1,s2:integer;
    t:array[0..1001,0..1001] of integer;
    ts1,ts2,tsir:array[0..1001] of char;
    fisierintrare,fisieriesire:text;
BEGIN

clrscr;

assign(fisierintrare,'cmlsc.in');
reset(fisierintrare);

readln(fisierintrare,s1);
readln(fisierintrare,s2);

max:=0;

for i:=0 to s1+1 do
        for j:=0 to s2+1 do
                t[i,j]:=0;

for i:=1 to s1 do read(fisierintrare,ts1[i]);

for j:=1 to s2 do read(fisierintrare,ts2[j]);

close(fisierintrare);
for i:=1 to s1 do
        for j:=1 to s2 do
                begin

                if ts1[i]=ts2[j] then
                        t[i,j]:=t[i-1,j-1]+1 else
                                if j=1 then t[i,j]:=t[i-1,j];

                if ts1[i]<>ts2[j] then
                        begin
                        if ts1[i-1]=ts2[j-1] then t[i,j]:=t[i-1,j];
                        if ts1[i-1]>ts2[j-1] then t[i,j]:=t[i-1,j];
                        if ts1[i-1]<ts2[j-1] then t[i,j]:=t[i,j-1];
                        end;

                if t[i,j]>max then max:=t[i,j];
                end;
aux:=max;
for i:=1 to s1 do
        for j:=1 to s2 do
                if t[i,j]=aux then
                        begin

                        a:=i;
                        b:=j;

                        repeat
                        if ts1[a]=ts2[b] then
                                begin
                                tsir[aux]:=ts1[a];
                                aux:=aux-1;
                                a:=a-1;
                                b:=b-1;
                                end      else

                        if ts1[a]<>ts2[b] then
                                begin

                                if t[a-1,b]>t[a,b-1] then
                                        a:=a-1;

                                if t[a-1,b]<t[a,b-1] then
                                        b:=b-1;
                                end;
                        until aux=0;
                        end;

assign(fisieriesire,'cmlsc.out');
rewrite(fisieriesire);
writeln(fisieriesire,max);
for i:=1 to max do
        write(fisieriesire,tsir[i]);
close(fisieriesire);

END.
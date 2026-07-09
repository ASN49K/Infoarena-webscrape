const   fin = 'cmlsc.in'; fout = 'cmlsc.out';

type
        sir = array[1..1024] of word;
        matrice = array[0..1024,0..1024] of word;
var
        a, b : sir;
        n, m : word;
        sol : matrice;

function max(a ,b : word) : word;
begin
        if a > b then max := a else max := b;
end;

procedure solution();
var
        k ,h : word;
begin
        for k := 1 to n do
        for h := 1 to m do
        if (a[k] = b[h]) then sol[k][h] := 1 + sol[k - 1][h - 1] else
        sol[k][h] := max( sol[k - 1][h], sol[k][h - 1] );
end;

procedure makesolution( k, h : word);
begin
        if (sol[k][h] > 0) then
        if (a[k] = b[h]) then
        begin
                makesolution( k - 1, h - 1 );
                write( a[k] ,#32 );
        end else
        begin
                if sol[k][h] = sol[k - 1][h] then makesolution( k - 1, h ) else
                if sol[k][h] = sol[k][h - 1] then makesolution( k, h - 1 );
        end;
end;

procedure main();
var
        i : word;
begin
        assign( input, fin ); reset( input );
        assign( output, fout ); rewrite( output );

        readln( n, m );
        for i := 1 to n do read( a[i] );
        for i := 1 to m do read( b[i] );

        solution();

        write( sol[n][m] ,#10);

        makesolution( n, m );
end;

begin
        main();
end.
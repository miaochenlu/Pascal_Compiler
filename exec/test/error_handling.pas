tttt PROGRAM FIB;{error test}
VAR
    MESSAGE: STRING;
    a : INTEGER
    b : REAL; {error test}

FUNCTION F(n : INTEGER): INTEGER;
BEGIN
    IF n <= 1 THEN
    BEGIN
        F := 1;
    {END error test}
    ELSE IF n = 1 THEN
    BEGIN
        F := 1;
    END
    ELSE BEGIN
        F := F(n - 1) + F(n - 2);
    END;
END;
jfkdjska {error test}
BEGIN
    WRITELN('---Calculate Fibonacci ---');
    WRITELN('Please give a number: ');
    READ(a);
    WRITE('Result:');
    WRITELN(F(a));
END.
PROGRAM FIB;
VAR
    MESSAGE: STRING;
    a : INTEGER;

FUNCTION F(n : INTEGER): INTEGER;
BEGIN
    IF n <= 1 THEN
    BEGIN
        F := 1;
    END
    ELSE IF n = 1 THEN
    BEGIN
        F := 1;
    END
    ELSE BEGIN
        F := F(n - 1) + F(n - 2);
    END;
END;
BEGIN
    WRITELN('---Calculate Fibonacci ---');
    WRITELN('Please give a number: ');
    READ(a);
    WRITE('Result:');
    WRITELN(F(a));
END.
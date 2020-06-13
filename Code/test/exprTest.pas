PROGRAM ex;
VAR A : INTEGER;
    B : INTEGER;
    C : REAL;
    D : INTEGER;
    E : BOOLEAN;
BEGIN
    A := 100;
    A := A / 10; 
    A := A + 20;
    A := A * 4;
    A := -A;
    C := 10.0;
    C := A + 20.0;
    C := C / 10.0;
    B := A % 10;
    D := A OR B;
    D := A AND B;
    E := A = B;
    E := A > B;
    E := A >= B;
    E := A < B;
    E := A <= B;   
END.

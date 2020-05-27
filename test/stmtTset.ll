; ModuleID = 'Module'
source_filename = "Module"

@0 = private unnamed_addr constant [5 x i8] c"'A1'\00"
@1 = private unnamed_addr constant [5 x i8] c"'B2'\00"
@2 = private unnamed_addr constant [5 x i8] c"'C3'\00"
@3 = private unnamed_addr constant [5 x i8] c"'D4'\00"

define void @STMTTEST() {
STMTTEST:
  %B = alloca i32
  %C = alloca i32
  %D = alloca i32
  %STR = alloca [100 x i8]
  store i32 1, i32* %B
  store i32 0, i32* %C
  br label %"1"

"1":                                              ; preds = %CaseContinue, %STMTTEST
  br i1 true, label %ifThen, label %ifElse

ifThen:                                           ; preds = %"1"
  store i32 1, i32* %D

ifElse:                                           ; preds = %"1"
  store i32 0, i32* %D
  br label %ifContinue

ifContinue:                                       ; preds = %ifElse, %ForContinue
  %0 = load i32, i32* %D
  %1 = add i32 %0, 1

ForLoop:                                          ; preds = %repeatContinue
  %2 = load i32, i32* %C
  %3 = add i32 %2, 1
  store i32 %3, i32* %C

ForContinue:                                      ; preds = %repeatContinue
  br label %ifContinue

whileBegin:                                       ; preds = %WhileLoop
  %4 = load i32, i32* %C
  %5 = icmp sle i32 %4, 5
  br i1 %5, label %WhileLoop, label %WhileContinue

WhileLoop:                                        ; preds = %whileBegin
  store i32 0, i32* %D
  store i32 0, i32* %D
  br label %whileBegin

WhileContinue:                                    ; preds = %whileBegin

repeatLoop:                                       ; preds = %repeatLoop
  store i32 0, i32* %D
  %6 = load i32, i32* %C
  %7 = icmp sgt i32 %6, 5
  br i1 %7, label %repeatContinue, label %repeatLoop

repeatContinue:                                   ; preds = %repeatLoop
  %8 = add i32* %D, i32 1
  store i32* %8, i32* %D
  %9 = load i32, i32* %D
  %10 = icmp eq i32 %9, 10
  br i1 %10, label %ForContinue, label %ForLoop

CaseContinue:                                     ; preds = %Casecase5, %Casecond6, %Casecase3, %Casecase1, %Casecase
  br label %"1"

Casecase:                                         ; preds = %Casecond
  %11 = load [5 x i8], [5 x i8]* @0
  store [5 x i8] %11, [100 x i8]* %STR
  store i32 1, i32* %C
  br label %CaseContinue

Casecond:                                         ; No predecessors!
  %12 = icmp eq i32 %1, 0
  br i1 %12, label %Casecase, label %Casecond2

Casecase1:                                        ; preds = %Casecond2
  %13 = load [5 x i8], [5 x i8]* @1
  store [5 x i8] %13, [100 x i8]* %STR
  br label %CaseContinue

Casecond2:                                        ; preds = %Casecond
  %14 = icmp eq i32 %1, 1
  br i1 %14, label %Casecase1, label %Casecond4

Casecase3:                                        ; preds = %Casecond4
  %15 = load [5 x i8], [5 x i8]* @2
  store [5 x i8] %15, [100 x i8]* %STR
  br label %CaseContinue

Casecond4:                                        ; preds = %Casecond2
  %16 = icmp eq i32 %1, 2
  br i1 %16, label %Casecase3, label %Casecond6

Casecase5:                                        ; preds = %Casecond6
  %17 = load [5 x i8], [5 x i8]* @3
  store [5 x i8] %17, [100 x i8]* %STR
  br label %CaseContinue

Casecond6:                                        ; preds = %Casecond4
  %18 = icmp eq i32 %1, 3
  br i1 %18, label %Casecase5, label %CaseContinue
}

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
  %STR = alloca [255 x i8]
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

Casecond:                                         ; No predecessors!
  %11 = icmp eq i32 %1, 0
  br i1 %11, label %Casecase, label %Casecond1

Casecase:                                         ; preds = %Casecond
  %12 = load [5 x i8], [5 x i8]* @0
  store [5 x i8] %12, [255 x i8]* %STR
  store i32 1, i32* %C
  br label %CaseContinue

Casecond1:                                        ; preds = %Casecond
  %13 = icmp eq i32 %1, 1
  br i1 %13, label %Casecase2, label %Casecond3

Casecase2:                                        ; preds = %Casecond1
  %14 = load [5 x i8], [5 x i8]* @1
  store [5 x i8] %14, [255 x i8]* %STR
  br label %CaseContinue

Casecond3:                                        ; preds = %Casecond1
  %15 = icmp eq i32 %1, 2
  br i1 %15, label %Casecase4, label %Casecond5

Casecase4:                                        ; preds = %Casecond3
  %16 = load [5 x i8], [5 x i8]* @2
  store [5 x i8] %16, [255 x i8]* %STR
  br label %CaseContinue

Casecond5:                                        ; preds = %Casecond3
  %17 = icmp eq i32 %1, 3
  br i1 %17, label %Casecase6, label %CaseContinue

Casecase6:                                        ; preds = %Casecond5
  %18 = load [5 x i8], [5 x i8]* @3
  store [5 x i8] %18, [255 x i8]* %STR
  br label %CaseContinue

CaseContinue:                                     ; preds = %Casecase6, %Casecond5, %Casecase4, %Casecase2, %Casecase
  br label %"1"
}

; ModuleID = 'Module'
source_filename = "Module"

@0 = private unnamed_addr constant [255 x i8] c"'A1'                                                                                                                                                                                                                                                          \00"
@1 = private unnamed_addr constant [255 x i8] c"'B2'                                                                                                                                                                                                                                                          \00"
@2 = private unnamed_addr constant [255 x i8] c"'C3'                                                                                                                                                                                                                                                          \00"
@3 = private unnamed_addr constant [255 x i8] c"'D4'                                                                                                                                                                                                                                                          \00"
@printstring = private unnamed_addr constant [4 x i8] c"%d \00"
@printstring.1 = private unnamed_addr constant [5 x i8] c"%d \0A\00"

declare i32 @abs(i32)

declare i32 @printf(i8*, ...)

declare double @sqrt(double)

define void @main() {
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
  br label %ForLoop

ifElse:                                           ; preds = %"1"
  store i32 0, i32* %D
  br label %ifContinue

ifContinue:                                       ; preds = %ifElse, %ForContinue
  %0 = load i32, i32* %D
  %1 = add i32 %0, 1
  br label %Casecond

ForLoop:                                          ; preds = %repeatContinue, %ifThen
  %2 = load i32, i32* %C
  %3 = add i32 %2, 1
  store i32 %3, i32* %C
  br label %whileBegin

ForContinue:                                      ; preds = %repeatContinue
  br label %ifContinue

whileBegin:                                       ; preds = %WhileLoop, %ForLoop
  %4 = load i32, i32* %C
  %5 = icmp sle i32 %4, 5
  br i1 %5, label %WhileLoop, label %WhileContinue

WhileLoop:                                        ; preds = %whileBegin
  store i32 0, i32* %D
  store i32 0, i32* %D
  br label %whileBegin

WhileContinue:                                    ; preds = %whileBegin
  br label %repeatLoop

repeatLoop:                                       ; preds = %repeatLoop, %WhileContinue
  store i32 0, i32* %D
  %6 = load i32, i32* %C
  %7 = icmp sgt i32 %6, 5
  br i1 %7, label %repeatContinue, label %repeatLoop

repeatContinue:                                   ; preds = %repeatLoop
  %8 = load i32, i32* %D
  %9 = add i32 %8, 1
  store i32 %9, i32* %D
  %10 = load i32, i32* %D
  %11 = icmp eq i32 %10, 10
  br i1 %11, label %ForContinue, label %ForLoop

Casecond:                                         ; preds = %ifContinue
  %12 = icmp eq i32 %1, 0
  br i1 %12, label %Casecase, label %Casecond1

Casecase:                                         ; preds = %Casecond
  %13 = load [255 x i8], [255 x i8]* @0
  store [255 x i8] %13, [255 x i8]* %STR
  store i32 1, i32* %C
  br label %CaseContinue

Casecond1:                                        ; preds = %Casecond
  %14 = icmp eq i32 %1, 1
  br i1 %14, label %Casecase2, label %Casecond3

Casecase2:                                        ; preds = %Casecond1
  %15 = load [255 x i8], [255 x i8]* @1
  store [255 x i8] %15, [255 x i8]* %STR
  br label %CaseContinue

Casecond3:                                        ; preds = %Casecond1
  %16 = icmp eq i32 %1, 2
  br i1 %16, label %Casecase4, label %Casecond5

Casecase4:                                        ; preds = %Casecond3
  %17 = load [255 x i8], [255 x i8]* @2
  store [255 x i8] %17, [255 x i8]* %STR
  br label %CaseContinue

Casecond5:                                        ; preds = %Casecond3
  %18 = icmp eq i32 %1, 3
  br i1 %18, label %Casecase6, label %CaseContinue

Casecase6:                                        ; preds = %Casecond5
  %19 = load [255 x i8], [255 x i8]* @3
  store [255 x i8] %19, [255 x i8]* %STR
  br label %CaseContinue

CaseContinue:                                     ; preds = %Casecase6, %Casecond5, %Casecase4, %Casecase2, %Casecase
  br label %"1"

gotocontinue:                                     ; No predecessors!
  %20 = load i32, i32* %D
  %write = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @printstring, i32 0, i32 0), i32 %20)
  %21 = load i32, i32* %D
  %write7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @printstring.1, i32 0, i32 0), i32 %21)
  ret void
}

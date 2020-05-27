; ModuleID = 'Module'
source_filename = "Module"

define void @ex() {
ex:
  %A = alloca i32
  %B = alloca i32
  %C = alloca double
  %D = alloca i32
  %E = alloca i1
  store i32 100, i32* %A
  %0 = sdiv i32* %A, i32 3
  store i32* %0, i32* %A
  %1 = add i32* %A, i32 20
  store i32* %1, i32* %A
  %2 = mul i32* %A, i32 4
  store i32* %2, i32* %A
  %3 = sub i32* null, %A
  store i32* %3, i32* %A
  store double 1.000000e+01, double* %C
  %4 = fadd i32* %A, double 2.000000e+01
  store i32* %4, double* %C
  %5 = fdiv double* %C, double 1.000000e+01
  store double* %5, double* %C
  %6 = srem i32* %A, %B
  store i32* %6, i32* %B
  %7 = or i32* %A, %B
  store i32* %7, i32* %D
  %8 = and i32* %A, %B
  store i32* %8, i32* %D
  %9 = icmp eq i32* %A, %B
  store i1 %9, i1* %E
  %10 = icmp sgt i32* %A, %B
  store i1 %10, i1* %E
  %11 = icmp sge i32* %A, %B
  store i1 %11, i1* %E
  %12 = icmp slt i32* %A, %B
  store i1 %12, i1* %E
  %13 = icmp sle i32* %A, %B
  store i1 %13, i1* %E
}

package blasgo

//#include "cblas.h"
import "C"
import "unsafe"

//SGER performs rank one operation: A = alpha*x*yT + A
func SGER(order Order, M, N int, alpha float32, X []float32, incX int, Y []float32, incY int, A []float32, lda int) {
	C.cblas_sger(C.enum_CBLAS_ORDER(order), C.int(M), C.int(N),
		C.float(alpha),
		(*C.float)(&X[0]), C.int(incX),
		(*C.float)(&Y[0]), C.int(incY),
		(*C.float)(&A[0]), C.int(lda))
}

//DGER performs rank one operation: A = alpha*x*yT + A
func DGER(order Order, M, N int, alpha float64, X []float64, incX int, Y []float64, incY int, A []float64, lda int) {
	C.cblas_dger(C.enum_CBLAS_ORDER(order), C.int(M), C.int(N),
		C.double(alpha),
		(*C.double)(&X[0]), C.int(incX),
		(*C.double)(&Y[0]), C.int(incY),
		(*C.double)(&A[0]), C.int(lda))
}

//CGERU performs rank one operation: A = alpha*x*yT + A
func CGERU(order Order, M, N int, alpha complex64, X []complex64, incX int, Y []complex64, incY int, A []complex64, lda int) {
	C.cblas_cgeru(C.enum_CBLAS_ORDER(order), C.int(M), C.int(N),
		unsafe.Pointer(&alpha),
		unsafe.Pointer(&X[0]), C.int(incX),
		unsafe.Pointer(&Y[0]), C.int(incY),
		unsafe.Pointer(&A[0]), C.int(lda))
}

//CGERC performs rank one operation: A = alpha*x*yT + A
func CGERC(order Order, M, N int, alpha complex64, X []complex64, incX int, Y []complex64, incY int, A []complex64, lda int) {
	C.cblas_cgerc(C.enum_CBLAS_ORDER(order), C.int(M), C.int(N),
		unsafe.Pointer(&alpha),
		unsafe.Pointer(&X[0]), C.int(incX),
		unsafe.Pointer(&Y[0]), C.int(incY),
		unsafe.Pointer(&A[0]), C.int(lda))
}

//ZGERU performs rank one operation: A = alpha*x*yT + A
func ZGERU(order Order, M, N int, alpha complex128, X []complex128, incX int, Y []complex128, incY int, A []complex128, lda int) {
	C.cblas_zgeru(C.enum_CBLAS_ORDER(order), C.int(M), C.int(N),
		unsafe.Pointer(&alpha),
		unsafe.Pointer(&X[0]), C.int(incX),
		unsafe.Pointer(&Y[0]), C.int(incY),
		unsafe.Pointer(&A[0]), C.int(lda))
}

//ZGERC performs rank one operation: A = alpha*x*yT + A
func ZGERC(order Order, M, N int, alpha complex128, X []complex128, incX int, Y []complex128, incY int, A []complex128, lda int) {
	C.cblas_zgerc(C.enum_CBLAS_ORDER(order), C.int(M), C.int(N),
		unsafe.Pointer(&alpha),
		unsafe.Pointer(&X[0]), C.int(incX),
		unsafe.Pointer(&Y[0]), C.int(incY),
		unsafe.Pointer(&A[0]), C.int(lda))
}

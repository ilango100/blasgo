package blasgo

/*
#include "cblas.h"
*/
import "C"
import (
	"unsafe"
)

//Order indicates whether it is row major or column major.
type Order C.enum_CBLAS_ORDER

//Matrix directions. Note: When CblasColMajor is specified, result is also Column-wise.
const (
	RowMajor Order = C.CblasRowMajor
	ColMajor Order = C.CblasColMajor
)

//Transpose indicates what type of transpose to make.
type Transpose C.enum_CBLAS_TRANSPOSE

//Transpose Options.
const (
	NoTrans   Transpose = C.CblasNoTrans
	Trans     Transpose = C.CblasTrans
	ConjTrans Transpose = C.CblasConjTrans
)

//SGEMV multiplies matrix with vector.
func SGEMV(order Order, transA Transpose, m, n int, alpha float32, A []float32, lda int, X []float32, incX int, beta float32, Y []float32, incY int) {
	C.cblas_sgemv(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.int(m), C.int(n), C.float(alpha), (*C.float)(&A[0]), C.int(lda), (*C.float)(&X[0]), C.int(incX), C.float(beta), (*C.float)(&Y[0]), C.int(incY))
}

//DGEMV multiplies matrix with vector.
func DGEMV(order Order, transA Transpose, m, n int, alpha float64, A []float64, lda int, X []float64, incX int, beta float64, Y []float64, incY int) {
	C.cblas_dgemv(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.int(m), C.int(n), C.double(alpha), (*C.double)(&A[0]), C.int(lda), (*C.double)(&X[0]), C.int(incX), C.double(beta), (*C.double)(&Y[0]), C.int(incY))
}

//CGEMV multiplies matrix with vector.
func CGEMV(order Order, transA Transpose, m, n int, alpha complex64, A []complex64, lda int, X []complex64, incX int, beta complex64, Y []complex64, incY int) {
	C.cblas_cgemv(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.int(m), C.int(n), unsafe.Pointer(&alpha), unsafe.Pointer(&A[0]), C.int(lda), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&beta), unsafe.Pointer(&Y[0]), C.int(incY))
}

//ZGEMV multiplies matrix with vector.
func ZGEMV(order Order, transA Transpose, m, n int, alpha complex128, A []complex128, lda int, X []complex128, incX int, beta complex128, Y []complex128, incY int) {
	C.cblas_zgemv(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.int(m), C.int(n), unsafe.Pointer(&alpha), unsafe.Pointer(&A[0]), C.int(lda), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&beta), unsafe.Pointer(&Y[0]), C.int(incY))
}

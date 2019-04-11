package blasgo

//#include "cblas.h"
import "C"
import "unsafe"

//SGEMM performs general matrix multiplication. C = alpha*A*B + beta*C
func SGEMM(order Order, transA, transB Transpose, M, N, K int, alpha float32, A []float32, lda int, B []float32, ldb int, beta float32, C []float32, ldc int) {
	C.cblas_sgemm(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.enum_CBLAS_TRANSPOSE(transB),
		C.int(M), C.int(N), C.int(K),
		C.float(alpha),
		(*C.float)(&A[0]), C.int(lda),
		(*C.float)(&B[0]), C.int(ldb),
		C.float(beta),
		(*C.float)(&C[0]), C.int(ldc),
	)
}

//DGEMM performs general matrix multiplication. C = alpha*A*B + beta*C
func DGEMM(order Order, transA, transB Transpose, M, N, K int, alpha float64, A []float64, lda int, B []float64, ldb int, beta float64, C []float64, ldc int) {
	C.cblas_dgemm(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.enum_CBLAS_TRANSPOSE(transB),
		C.int(M), C.int(N), C.int(K),
		C.double(alpha),
		(*C.double)(&A[0]), C.int(lda),
		(*C.double)(&B[0]), C.int(ldb),
		C.double(beta),
		(*C.double)(&C[0]), C.int(ldc),
	)
}

//CGEMM performs general matrix multiplication. C = alpha*A*B + beta*C
func CGEMM(order Order, transA, transB Transpose, M, N, K int, alpha complex64, A []complex64, lda int, B []complex64, ldb int, beta complex64, C []complex64, ldc int) {
	C.cblas_cgemm(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.enum_CBLAS_TRANSPOSE(transB),
		C.int(M), C.int(N), C.int(K),
		unsafe.Pointer(&alpha),
		unsafe.Pointer(&A[0]), C.int(lda),
		unsafe.Pointer(&B[0]), C.int(ldb),
		unsafe.Pointer(&beta),
		unsafe.Pointer(&C[0]), C.int(ldc),
	)
}

//ZGEMM performs general matrix multiplication. C = alpha*A*B + beta*C
func ZGEMM(order Order, transA, transB Transpose, M, N, K int, alpha complex128, A []complex128, lda int, B []complex128, ldb int, beta complex128, C []complex128, ldc int) {
	C.cblas_zgemm(C.enum_CBLAS_ORDER(order), C.enum_CBLAS_TRANSPOSE(transA), C.enum_CBLAS_TRANSPOSE(transB),
		C.int(M), C.int(N), C.int(K),
		unsafe.Pointer(&alpha),
		unsafe.Pointer(&A[0]), C.int(lda),
		unsafe.Pointer(&B[0]), C.int(ldb),
		unsafe.Pointer(&beta),
		unsafe.Pointer(&C[0]), C.int(ldc),
	)
}

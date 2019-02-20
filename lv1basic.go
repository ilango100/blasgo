package blasgo

/*
#include "cblas.h"
*/
import "C"

import (
	"unsafe"
)

//Idx indicates index of vector or matrix.
type Idx C.CBLAS_INDEX

//SNRM2 calculates Euclidean norm of the vector.
func SNRM2(N int, X []float32, incX int) float32 {
	return float32(C.cblas_snrm2(C.int(N), (*C.float)(&X[0]), C.int(incX)))
}

//DNRM2 calculates Euclidean norm of the vector.
func DNRM2(N int, X []float64, incX int) float64 {
	return float64(C.cblas_dnrm2(C.int(N), (*C.double)(&X[0]), C.int(incX)))
}

//SCNRM2 calculates Euclidean norm of the vector.
func SCNRM2(N int, X []complex64, incX int) float32 {
	return float32(C.cblas_scnrm2(C.int(N), unsafe.Pointer(&X[0]), C.int(incX)))
}

//DZNRM2 calculates Euclidean norm of the vector.
func DZNRM2(N int, X []complex128, incX int) float64 {
	return float64(C.cblas_dznrm2(C.int(N), unsafe.Pointer(&X[0]), C.int(incX)))
}

//SSWAP swaps the Vectors.
func SSWAP(N int, X []float32, incX int, Y []float32, incY int) {
	C.cblas_sswap(C.int(N), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY))
}

//DSWAP swaps the Vectors.
func DSWAP(N int, X []float64, incX int, Y []float64, incY int) {
	C.cblas_dswap(C.int(N), (*C.double)(&X[0]), C.int(incX), (*C.double)(&Y[0]), C.int(incY))
}

//CSWAP swaps the Vectors.
func CSWAP(N int, X []complex64, incX int, Y []complex64, incY int) {
	C.cblas_cswap(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY))
}

//ZSWAP swaps the Vectors.
func ZSWAP(N int, X []complex128, incX int, Y []complex128, incY int) {
	C.cblas_zswap(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY))
}

//SCOPY copies the Vector X into Y.
func SCOPY(N int, X []float32, incX int, Y []float32, incY int) {
	C.cblas_scopy(C.int(N), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY))
}

//DCOPY copies the Vector X into Y.
func DCOPY(N int, X []float64, incX int, Y []float64, incY int) {
	C.cblas_dcopy(C.int(N), (*C.double)(&X[0]), C.int(incX), (*C.double)(&Y[0]), C.int(incY))
}

//CCOPY copies the Vector X into Y.
func CCOPY(N int, X []complex64, incX int, Y []complex64, incY int) {
	C.cblas_ccopy(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY))
}

//ZCOPY copies the Vector X into Y.
func ZCOPY(N int, X []complex128, incX int, Y []complex128, incY int) {
	C.cblas_ccopy(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY))
}
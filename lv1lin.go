package blasgo

/*
#include "cblas.h"
*/
import "C"

import (
	"unsafe"
)

//SSCAL scales the given vector by alpha.
func SSCAL(N int, alpha float32, X []float32, incX int) {
	C.cblas_sscal(C.int(N), C.float(alpha), (*C.float)(&X[0]), C.int(incX))
}

//DSCAL scales the given vector by alpha.
func DSCAL(N int, alpha float64, X []float64, incX int) {
	C.cblas_dscal(C.int(N), C.double(alpha), (*C.double)(&X[0]), C.int(incX))
}

//CSCAL scales the given vector by alpha.
func CSCAL(N int, alpha complex64, X []complex64, incX int) {
	C.cblas_cscal(C.int(N), unsafe.Pointer(&alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//ZSCAL scales the given vector by alpha.
func ZSCAL(N int, alpha complex128, X []complex128, incX int) {
	C.cblas_zscal(C.int(N), unsafe.Pointer(&alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//CSSCAL scales the given vector by alpha.
func CSSCAL(N int, alpha float32, X []complex64, incX int) {
	C.cblas_csscal(C.int(N), C.float(alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//ZDSCAL scales the given vector by alpha.
func ZDSCAL(N int, alpha float64, X []complex128, incX int) {
	C.cblas_zdscal(C.int(N), C.double(alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//SDOT performs dot product of X and Y.
func SDOT(N int, X []float32, incX int, Y []float32, incY int) float32 {
	return float32(C.cblas_sdot(C.int(N), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY)))
}

//DDOT performs dot product of X and Y.
func DDOT(N int, X []float64, incX int, Y []float64, incY int) float64 {
	return float64(C.cblas_ddot(C.int(N), (*C.double)(&X[0]), C.int(incX), (*C.double)(&Y[0]), C.int(incY)))
}

//DSDOT performs dot product of X and Y.
func DSDOT(N int, X []float32, incX int, Y []float32, incY int) float64 {
	return float64(C.cblas_dsdot(C.int(N), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY)))
}

//SDSDOT performs dot product of X and Y.
func SDSDOT(N int, alpha float32, X []float32, incX int, Y []float32, incY int) float32 {
	return float32(C.cblas_sdsdot(C.int(N), C.float(alpha), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY)))
}

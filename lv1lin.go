package blasgo

/*
#include "blasgo.h"
*/
import "C"

import (
	"unsafe"
)

//SSCAL scales the given vector by alpha.
func SSCAL(N int, alpha float32, X []float32, incX int) {
	C.blasgo_sscal(C.int(N), C.float(alpha), (*C.float)(&X[0]), C.int(incX))
}

//DSCAL scales the given vector by alpha.
func DSCAL(N int, alpha float64, X []float64, incX int) {
	C.blasgo_dscal(C.int(N), C.double(alpha), (*C.double)(&X[0]), C.int(incX))
}

//CSCAL scales the given vector by alpha.
func CSCAL(N int, alpha complex64, X []complex64, incX int) {
	C.blasgo_cscal(C.int(N), unsafe.Pointer(&alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//ZSCAL scales the given vector by alpha.
func ZSCAL(N int, alpha complex128, X []complex128, incX int) {
	C.blasgo_zscal(C.int(N), unsafe.Pointer(&alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//CSSCAL scales the given vector by alpha.
func CSSCAL(N int, alpha float32, X []complex64, incX int) {
	C.blasgo_csscal(C.int(N), C.float(alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//ZDSCAL scales the given vector by alpha.
func ZDSCAL(N int, alpha float64, X []complex128, incX int) {
	C.blasgo_zdscal(C.int(N), C.double(alpha), unsafe.Pointer(&X[0]), C.int(incX))
}

//SDOT performs dot product of X and Y.
func SDOT(N int, X []float32, incX int, Y []float32, incY int) float32 {
	return float32(C.blasgo_sdot(C.int(N), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY)))
}

//DDOT performs dot product of X and Y.
func DDOT(N int, X []float64, incX int, Y []float64, incY int) float64 {
	return float64(C.blasgo_ddot(C.int(N), (*C.double)(&X[0]), C.int(incX), (*C.double)(&Y[0]), C.int(incY)))
}

//DSDOT performs dot product of X and Y.
func DSDOT(N int, X []float32, incX int, Y []float32, incY int) float64 {
	return float64(C.blasgo_dsdot(C.int(N), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY)))
}

//SDSDOT performs dot product of X and Y.
func SDSDOT(N int, alpha float32, X []float32, incX int, Y []float32, incY int) float32 {
	return float32(C.blasgo_sdsdot(C.int(N), C.float(alpha), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY)))
}

//CDOTU performs dot product of X and Y.
func CDOTU(N int, X []complex64, incX int, Y []complex64, incY int) complex64 {
	return complex64(C.blasgo_cdotu(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY)))
}

//CDOTC performs dot product of X and congugate Y.
func CDOTC(N int, X []complex64, incX int, Y []complex64, incY int) complex64 {
	return complex64(C.blasgo_cdotc(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY)))
}

//ZDOTU performs dot product of X and Y.
func ZDOTU(N int, X []complex128, incX int, Y []complex128, incY int) complex128 {
	return complex128(C.blasgo_zdotu(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY)))
}

//ZDOTC performs dot product of X and Y.
func ZDOTC(N int, X []complex128, incX int, Y []complex128, incY int) complex128 {
	return complex128(C.blasgo_zdotc(C.int(N), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY)))
}

//SAXPY => Y = A*X + Y
func SAXPY(N int, alpha float32, X []float32, incX int, Y []float32, incY int) {
	C.blasgo_saxpy(C.int(N), C.float(alpha), (*C.float)(&X[0]), C.int(incX), (*C.float)(&Y[0]), C.int(incY))
}

//DAXPY => Y = A*X + Y
func DAXPY(N int, alpha float64, X []float64, incX int, Y []float64, incY int) {
	C.blasgo_daxpy(C.int(N), C.double(alpha), (*C.double)(&X[0]), C.int(incX), (*C.double)(&Y[0]), C.int(incY))
}

//CAXPY => Y = A*X + Y
func CAXPY(N int, alpha complex64, X []complex64, incX int, Y []complex64, incY int) {
	C.blasgo_caxpy(C.int(N), unsafe.Pointer(&alpha), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY))
}

//ZAXPY => Y = A*X + Y
func ZAXPY(N int, alpha complex128, X []complex128, incX int, Y []complex128, incY int) {
	C.blasgo_zaxpy(C.int(N), unsafe.Pointer(&alpha), unsafe.Pointer(&X[0]), C.int(incX), unsafe.Pointer(&Y[0]), C.int(incY))
}

package blasgo

/*
#include "cblas.h"
*/
import "C"

import (
	"unsafe"
)

//SNRM2 calculates Euclidean norm vector
func SNRM2(N int, X []float32, incX int) float32 {
	return float32(C.cblas_snrm2(C.int(N), (*C.float)(unsafe.Pointer(&X[0])), C.int(incX)))
}

//DNRM2 calculates Euclidean norm vector
func DNRM2(N int, X []float64, incX int) float64 {
	return float64(C.cblas_dnrm2(C.int(N), (*C.double)(unsafe.Pointer(&X[0])), C.int(incX)))
}

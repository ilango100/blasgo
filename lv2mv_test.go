package blasgo

import (
	"testing"
)

const (
	m = 5
)

var (
	amat  = []float32{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5}
	aamat = []float64{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5}

	cmat  = []complex64{complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10)}
	ccmat = []complex128{complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10)}
)

func TestSGEMV(t *testing.T) {
	alpha, beta := float32(1.2), float32(2.3)
	x, y, z := make([]float32, m), make([]float32, m), make([]float32, m)
	copy(x, a)
	copy(y, a)
	copy(z, a)
	SGEMV(RowMajor, NoTrans, m, m, alpha, amat, m, x, 1, beta, y, 1)
	SGEMV(ColMajor, Trans, m, m, alpha, amat, m, x, 1, beta, z, 1)

	res := []float32{68.3, 70.6, 72.9, 75.2, 77.5}
	if !compareSlices32(y, res) {
		t.Errorf("SGEMV expected %v, got %v", res, y)
	}
	if !compareSlices32(z, res) {
		t.Errorf("SGEMV, ColMajor, Transpose: expected %v, got %v", res, y)
	}
	t.Logf("SGEMV result: %v", y)
}

func TestDGEMV(t *testing.T) {
	alpha, beta := float64(1.2), float64(2.3)
	x, y, z := make([]float64, m), make([]float64, m), make([]float64, m)
	copy(x, aa)
	copy(y, aa)
	copy(z, aa)
	DGEMV(RowMajor, NoTrans, m, m, alpha, aamat, m, x, 1, beta, y, 1)
	DGEMV(ColMajor, Trans, m, m, alpha, aamat, m, x, 1, beta, z, 1)

	res := []float64{68.3, 70.6, 72.9, 75.2, 77.5}
	if !compareSlices64(y, res) {
		t.Errorf("DGEMV expected %v, got %v", res, y)
	}
	if !compareSlices64(z, res) {
		t.Errorf("DGEMV, ColMajor, Transpose: expected %v, got %v", res, y)
	}
	t.Logf("DGEMV result: %v", y)

}

func TestCGEMV(t *testing.T) {
	alpha, beta := complex64(complex(1.2, 1.2)), complex64(complex(2.3, 2.3))
	x, y, z := make([]complex64, m), make([]complex64, m), make([]complex64, m)
	copy(x, c)
	copy(y, c)
	copy(z, c)
	CGEMV(RowMajor, NoTrans, m, m, alpha, cmat, m, x, 1, beta, y, 1)
	CGEMV(ColMajor, Trans, m, m, alpha, cmat, m, x, 1, beta, z, 1)

	res := []complex64{complex(-524.3, 396.9), complex(-524.3, 406.1), complex(-524.3, 415.3), complex(-524.3, 424.5), complex(-524.3, 433.7)}
	if !compareSlicesC64(y, res) {
		t.Errorf("CGEMV expected %v, got %v", res, y)
	}
	if !compareSlicesC64(z, res) {
		t.Errorf("CGEMV, ColMajor, Transpose: expected %v, got %v", res, y)
	}
	t.Logf("CGEMV result: %v", y)

}

func TestZGEMV(t *testing.T) {
	alpha, beta := complex128(complex(1.2, 1.2)), complex128(complex(2.3, 2.3))
	x, y, z := make([]complex128, m), make([]complex128, m), make([]complex128, m)
	copy(x, cc)
	copy(y, cc)
	copy(z, cc)
	ZGEMV(RowMajor, NoTrans, m, m, alpha, ccmat, m, x, 1, beta, y, 1)
	ZGEMV(ColMajor, Trans, m, m, alpha, ccmat, m, x, 1, beta, z, 1)

	res := []complex128{complex(-524.3, 396.9), complex(-524.3, 406.1), complex(-524.3, 415.3), complex(-524.3, 424.5), complex(-524.3, 433.7)}
	if !compareSlicesC128(y, res) {
		t.Errorf("ZGEMV expected %v, got %v", res, y)
	}
	if !compareSlicesC128(z, res) {
		t.Errorf("ZGEMV, ColMajor, Transpose: expected %v, got %v", res, y)
	}
	t.Logf("ZGEMV result: %v", y)

}

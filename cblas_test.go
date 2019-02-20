package blasgo

import (
	"testing"
)

const n = 10

var a = []float32{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
var b = []float32{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
var aa = []float64{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
var bb = []float64{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

const anorm = 19.621416870348583468526003789181774326312834524158

func compareSlices32(a, b []float32) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func compareSlices64(a, b []float64) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func TestSNRM2(t *testing.T) {
	nrm := SNRM2(n, a, 1)
	t.Logf("Norm of %v is %f", a, nrm)
	if nrm != anorm {
		t.Errorf("Norm wanted %f, got: %f", anorm, nrm)
	}
}

func TestDNRM2(t *testing.T) {
	nrm := DNRM2(n, aa, 1)
	t.Logf("Norm of %v is %f", a, nrm)
	if nrm != anorm {
		t.Errorf("Norm wanted %.20f, got: %.20f", anorm, nrm)
	}
}

func TestSSWAP(t *testing.T) {
	aaa := make([]float32, n)
	copy(aaa, a)
	bbb := make([]float32, n)
	copy(bbb, b)
	SSWAP(n, aaa, 1, bbb, 1)
	if !compareSlices32(aaa, b) || !compareSlices32(bbb, a) {
		t.Errorf("Not swapped correctly, a: %v, b: %v", aaa, bbb)
	}
}

func TestDSWAP(t *testing.T) {
	aaa := make([]float64, n)
	copy(aaa, aa)
	bbb := make([]float64, n)
	copy(bbb, bb)
	DSWAP(n, aaa, 1, bbb, 1)
	if !compareSlices64(aaa, bb) || !compareSlices64(bbb, aa) {
		t.Errorf("Not swapped correctly, a: %v, b: %v", aaa, bbb)
	}
}

func TestSCOPY(t *testing.T) {
	aaa := make([]float32, n)
	SCOPY(n, a, 1, aaa, 1)
	if !compareSlices32(a, aaa) {
		t.Errorf("Copied slices not equal to original: %v != %v", aaa, a)
	}
}

func TestDCOPY(t *testing.T) {
	aaa := make([]float64, n)
	DCOPY(n, aa, 1, aaa, 1)
	if !compareSlices64(aa, aaa) {
		t.Errorf("Copied slice not equal to original: %v != %v", aaa, a)
	}
}

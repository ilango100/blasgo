package blasgo

import (
	"testing"
)

const (
	n    = 10
	cn   = 5
	norm = 19.621416870348583468526003789181774326312834524158
)

var (
	a  = []float32{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	b  = []float32{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	aa = []float64{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	bb = []float64{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

	c  = []complex64{complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10)}
	d  = []complex64{complex(9, 10), complex(7, 8), complex(5, 6), complex(3, 4), complex(1, 2)}
	cc = []complex128{complex(1, 2), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10)}
	dd = []complex128{complex(9, 10), complex(7, 8), complex(5, 6), complex(3, 4), complex(1, 2)}
)

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

func compareSlicesC64(a, b []complex64) bool {
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

func compareSlicesC128(a, b []complex128) bool {
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

func TestISAMAX(t *testing.T) {
	max := ISAMAX(n, a, 1)
	if max != len(a)-1 {
		t.Errorf("Expected max index of %v to be %d, got %d", a, len(a)-1, max)
	}
	t.Logf("Max index of %v is %d", a, max)
	max = ISAMAX(n, b, 1)
	if max != 0 {
		t.Errorf("Expected max index of %v to be %d, got %d", b, 0, max)
	}
	t.Logf("Max index of %v is %d", b, max)
}

func TestIDAMAX(t *testing.T) {
	max := IDAMAX(n, aa, 1)
	if max != len(a)-1 {
		t.Errorf("Expected max index of %v to be %d, got %d", aa, len(a)-1, max)
	}
	t.Logf("Max index of %v is %d", aa, max)
	max = IDAMAX(n, bb, 1)
	if max != 0 {
		t.Errorf("Expected max index of %v to be %d, got %d", bb, 0, max)
	}
	t.Logf("Max index of %v is %d", bb, max)
}

func TestICAMAX(t *testing.T) {
	max := ICAMAX(cn, c, 1)
	if max != len(c)-1 {
		t.Errorf("Expected max index of %v to be %d, got %d", c, len(c)-1, max)
	}
	t.Logf("Max index of %v is %d", c, max)
	max = ICAMAX(cn, d, 1)
	if max != 0 {
		t.Errorf("Expected max index of %v to be %d, got %d", d, 0, max)
	}
	t.Logf("Max index of %v is %d", d, max)
}

func TestIZAMAX(t *testing.T) {
	max := IZAMAX(cn, cc, 1)
	if max != len(cc)-1 {
		t.Errorf("Expected max index of %v to be %d, got %d", cc, len(cc)-1, max)
	}
	t.Logf("Max index of %v is %d", cc, max)
	max = IZAMAX(cn, dd, 1)
	if max != 0 {
		t.Errorf("Expected max index of %v to be %d, got %d", dd, 0, max)
	}
	t.Logf("Max index of %v is %d", dd, max)
}

func TestSNRM2(t *testing.T) {
	nrm := SNRM2(n, a, 1)
	t.Logf("Norm of %v is %f", a, nrm)
	if nrm != norm {
		t.Errorf("Norm wanted %.15f, got: %.15f", norm, nrm)
	}
}

func TestDNRM2(t *testing.T) {
	nrm := DNRM2(n, aa, 1)
	t.Logf("Norm of %v is %f", a, nrm)
	if nrm != norm {
		t.Errorf("Norm wanted %.20f, got: %.20f", norm, nrm)
	}
}

func TestSCNRM2(t *testing.T) {
	nrm := SCNRM2(cn, c, 1)
	t.Logf("Norm of %v is %f.", c, nrm)
	if nrm != norm {
		t.Errorf("Norm wanted %.15f, got: %.15f", norm, nrm)
	}
}
func TestDZNRM2(t *testing.T) {
	nrm := DZNRM2(cn, cc, 1)
	t.Logf("Norm of %v is %f.", cc, nrm)
	if nrm != norm {
		t.Errorf("Norm wanted %.20f, got: %.20f", norm, nrm)
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

func TestCSWAP(t *testing.T) {
	ccc := make([]complex64, cn)
	copy(ccc, c)
	ddd := make([]complex64, cn)
	copy(ddd, d)
	CSWAP(cn, ccc, 1, ddd, 1)
	if !compareSlicesC64(ccc, d) || !compareSlicesC64(ddd, c) {
		t.Errorf("Not swapped correctly, a: %v, b: %v", ccc, ddd)
	}
}

func TestZSWAP(t *testing.T) {
	ccc := make([]complex128, cn)
	copy(ccc, cc)
	ddd := make([]complex128, cn)
	copy(ddd, dd)
	ZSWAP(cn, ccc, 1, ddd, 1)
	if !compareSlicesC128(ccc, dd) || !compareSlicesC128(ddd, cc) {
		t.Errorf("Not swapped correctly, a: %v, b: %v", ccc, ddd)
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
		t.Errorf("Copied slice not equal to original: %v != %v", aaa, aa)
	}
}

func TestCCOPY(t *testing.T) {
	ccc := make([]complex64, cn)
	CCOPY(n, c, 1, ccc, 1)
	if !compareSlicesC64(ccc, c) {
		t.Errorf("Copied slice not equal to original: %v != %v", ccc, c)
	}
}

func TestZCOPY(t *testing.T) {
	ccc := make([]complex128, cn)
	ZCOPY(n, cc, 1, ccc, 1)
	if !compareSlicesC128(ccc, cc) {
		t.Errorf("Copied slice not equal to original: %v != %v", ccc, cc)
	}
}

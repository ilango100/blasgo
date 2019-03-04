package blasgo

import "testing"

func TestSSCAL(t *testing.T) {
	s := make([]float32, len(aa))
	copy(s, a)
	alpha := float32(2.5)
	sc := make([]float32, len(s))
	for i := range s {
		sc[i] = alpha * s[i]
	}

	SSCAL(n, alpha, s, 1)

	if !compareSlices32(s, sc) {
		t.Errorf("Scaling with %f, expected %v, got %v", alpha, sc, s)
	}
	t.Logf("Scaling with %f, got %v", alpha, s)
}

func TestDSCAL(t *testing.T) {
	s := make([]float64, len(aa))
	copy(s, aa)
	alpha := float64(2.5)
	sc := make([]float64, len(s))
	for i := range s {
		sc[i] = alpha * s[i]
	}

	DSCAL(n, alpha, s, 1)

	if !compareSlices64(s, sc) {
		t.Errorf("Scaling with %f, expected %v, got %v", alpha, sc, s)
	}
	t.Logf("Scaling with %f, got %v", alpha, s)
}

func TestCSCAL(t *testing.T) {
	s := make([]complex64, len(c))
	copy(s, c)
	alpha := complex64(complex(1.5, 2.5))
	sc := make([]complex64, len(c))
	for i := range sc {
		sc[i] = alpha * s[i]
	}

	CSCAL(cn, alpha, s, 1)

	if !compareSlicesC64(s, sc) {
		t.Errorf("Scaling with %v, expected %v, got %v", alpha, sc, s)
	}
	t.Logf("Scaling with %v, got %v", alpha, s)
}

func TestZSCAL(t *testing.T) {
	s := make([]complex128, len(cc))
	copy(s, cc)
	alpha := complex128(complex(1.5, 2.5))
	sc := make([]complex128, len(cc))
	for i := range sc {
		sc[i] = alpha * s[i]
	}

	ZSCAL(cn, alpha, s, 1)

	if !compareSlicesC128(s, sc) {
		t.Errorf("Scaling with %v, expected %v, got %v", alpha, sc, s)
	}
	t.Logf("Scaling with %v, got %v", alpha, s)
}

func TestCSSCAL(t *testing.T) {
	s := make([]complex64, len(c))
	copy(s, c)
	alpha := float32(2.5)
	sc := make([]complex64, len(c))
	for i := range sc {
		sc[i] = complex(alpha*real(s[i]), alpha*imag(s[i]))
	}

	CSSCAL(cn, alpha, s, 1)

	if !compareSlicesC64(s, sc) {
		t.Errorf("Scaling with %v, expected %v, got %v", alpha, sc, s)
	}
	t.Logf("Scaling with %v, got %v", alpha, s)
}

func TestZDSCAL(t *testing.T) {
	s := make([]complex128, len(cc))
	copy(s, cc)
	alpha := float64(2.5)
	sc := make([]complex128, len(cc))
	for i := range sc {
		sc[i] = complex(alpha*real(s[i]), alpha*imag(s[i]))
	}

	ZDSCAL(cn, alpha, s, 1)

	if !compareSlicesC128(s, sc) {
		t.Errorf("Scaling with %v, expected %v, got %v", alpha, sc, s)
	}
	t.Logf("Scaling with %v, got %v", alpha, s)
}

func TestSDOT(t *testing.T) {
	dt := SDOT(n, a, 1, b, 1)
	if dt != abdt {
		t.Errorf("Expected dot product %f, got %f", abdt, dt)
	}
	t.Logf("Dot product of %v and %v is %f", a, b, dt)
}

func TestDDOT(t *testing.T) {
	dt := DDOT(n, aa, 1, bb, 1)
	if dt != abdt {
		t.Errorf("Expected dot product %f, got %f", abdt, dt)
	}
	t.Logf("Dot product of %v and %v is %f", a, b, dt)
}

func TestDSDOT(t *testing.T) {
	dt := DSDOT(n, a, 1, b, 1)
	if dt != abdt {
		t.Errorf("Expected dot product %f, got %f", abdt, dt)
	}
	t.Logf("Dot product of %v and %v is %f", a, b, dt)
}

func TestSDSDOT(t *testing.T) {
	alpha := float32(5.0)
	dt := SDSDOT(n, alpha, a, 1, b, 1)
	if dt != abdt+alpha {
		t.Errorf("Expected dot product %f, got %f", abdt, dt)
	}
	t.Logf("Dot product of %v and %v + %f is %f", a, b, alpha, dt)
}
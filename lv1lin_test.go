package blasgo

import "testing"

func TestSSCAL(t *testing.T) {
	s := make([]float32, len(a))
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

func TestCDOTU(t *testing.T) {
	dt := CDOTU(cn, c, 1, d, 1)
	if dt != cddt {
		t.Errorf("")
	}
	t.Logf("Dot product of %v and %v is %v", c, d, dt)
}

func TestCDOTC(t *testing.T) {
	dt := CDOTC(cn, c, 1, d, 1)
	if dt != cddtc {
		t.Errorf("")
	}
	t.Logf("Dot product of %v and conj of %v is %v", c, d, dt)
}

func TestZDOTU(t *testing.T) {
	dt := ZDOTU(cn, cc, 1, dd, 1)
	if dt != cddt {
		t.Errorf("")
	}
	t.Logf("Dot product of %v and %v is %v", cc, dd, dt)
}

func TestZDOTC(t *testing.T) {
	dt := ZDOTC(cn, cc, 1, dd, 1)
	if dt != cddtc {
		t.Errorf("")
	}
	t.Logf("Dot product of %v and conj of %v is %v", cc, dd, dt)
}

func TestSAXPY(t *testing.T) {
	r := make([]float32, len(a))
	copy(r, a)
	s := make([]float32, len(a))
	copy(s, b)
	alpha := float32(2.5)

	sc := make([]float32, len(s))
	for i := range s {
		sc[i] = alpha*r[i] + s[i]
	}

	SAXPY(n, alpha, r, 1, s, 1)

	if !compareSlices32(s, sc) {
		t.Errorf("%f * %v + %v, expected %v, got %v", alpha, a, b, sc, s)
	}
	t.Logf("%f * %v + %v, got %v", alpha, a, b, s)
}

func TestDAXPY(t *testing.T) {
	r := make([]float64, len(aa))
	copy(r, aa)
	s := make([]float64, len(aa))
	copy(s, bb)
	alpha := float64(2.5)

	sc := make([]float64, len(s))
	for i := range s {
		sc[i] = alpha*r[i] + s[i]
	}

	DAXPY(n, alpha, r, 1, s, 1)

	if !compareSlices64(s, sc) {
		t.Errorf("%f * %v + %v, expected %v, got %v", alpha, a, b, sc, s)
	}
	t.Logf("%f * %v + %v, got %v", alpha, a, b, s)
}

func TestCAXPY(t *testing.T) {
	r := make([]complex64, len(c))
	copy(r, c)
	s := make([]complex64, len(d))
	copy(s, d)
	alpha := complex64(complex(2.5, 1.5))

	sc := make([]complex64, len(s))
	for i := range s {
		sc[i] = alpha*r[i] + s[i]
	}

	CAXPY(cn, alpha, r, 1, s, 1)

	if !compareSlicesC64(s, sc) {
		t.Errorf("%f * %v + %v, expected %v, got %v", alpha, c, d, sc, s)
	}
	t.Logf("%f * %v + %v, got %v", alpha, c, d, s)
}

func TestZAXPY(t *testing.T) {
	r := make([]complex128, len(cc))
	copy(r, cc)
	s := make([]complex128, len(dd))
	copy(s, dd)
	alpha := complex128(complex(2.5, 1.5))

	sc := make([]complex128, len(s))
	for i := range s {
		sc[i] = alpha*r[i] + s[i]
	}

	ZAXPY(cn, alpha, r, 1, s, 1)

	if !compareSlicesC128(s, sc) {
		t.Errorf("%f * %v + %v, expected %v, got %v", alpha, cc, dd, sc, s)
	}
	t.Logf("%f * %v + %v, got %v", alpha, cc, dd, s)
}

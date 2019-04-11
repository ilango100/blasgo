package blasgo

import (
	"math"
)

const (
	errprecision = 0.001
)

func compareSlices32(a, b []float32) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if math.Abs(float64(a[i]-b[i])) > errprecision {
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
		if math.Abs(a[i]-b[i]) > errprecision {
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
		if math.Abs(float64(real(a[i])-real(b[i]))) > errprecision || math.Abs(float64(imag(a[i])-imag(b[i]))) > errprecision {
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
		if math.Abs(real(a[i])-real(b[i])) > errprecision || math.Abs(imag(a[i])-imag(b[i])) > errprecision {
			return false
		}
	}
	return true
}

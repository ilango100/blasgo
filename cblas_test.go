package blasgo

import "testing"

var a = []float32{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
var aa = []float64{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

const anorm = 19.621416870348583468526003789181774326312834524158

func TestSNRM2(t *testing.T) {
	nrm := SNRM2(len(a), a, 1)
	t.Logf("Norm of %v is %f", a, nrm)
	if nrm != anorm {
		t.Errorf("Norm wanted %f, got: %f", anorm, nrm)
	}
}

func TestDNRM2(t *testing.T) {
	nrm := DNRM2(len(aa), aa, 1)
	t.Logf("Norm of %v is %f", a, nrm)
	if nrm != anorm {
		t.Errorf("Norm wanted %.20f, got: %.20f", anorm, nrm)
	}
}

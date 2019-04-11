package blasgo

import "testing"

const (
	k = 3
)

var (
	bmat  = []float32{15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	bbmat = []float64{15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

	dmat  = []complex64{complex(30, 29), complex(28, 27), complex(26, 25), complex(24, 23), complex(22, 21), complex(20, 19), complex(18, 17), complex(16, 15), complex(14, 13), complex(12, 11), complex(10, 9), complex(8, 7), complex(6, 5), complex(4, 3), complex(2, 1)}
	ddmat = []complex128{complex(30, 29), complex(28, 27), complex(26, 25), complex(24, 23), complex(22, 21), complex(20, 19), complex(18, 17), complex(16, 15), complex(14, 13), complex(12, 11), complex(10, 9), complex(8, 7), complex(6, 5), complex(4, 3), complex(2, 1)}
)

func TestSGEMM(t *testing.T) {
	alpha, beta := float32(1.2), float32(2.3)
	x, y := make([]float32, len(bmat)), make([]float32, len(bmat))
	copy(x, bmat)
	copy(y, bmat)

	//Transpose y
	inn := 0
	for i := 0; i < 3; i++ {
		for j := i; j < 15; j += 3 {
			y[inn] = bmat[j]
			inn++
		}
	}

	res := []float32{160.5, 140.2, 119.9, 153.6, 133.3, 113., 146.7, 126.4, 106.1, 139.8, 119.5, 99.2, 132.9, 112.6, 92.3}
	SGEMM(RowMajor, NoTrans, NoTrans, m, k, m, alpha, amat, m, bmat, k, beta, x, k)
	if !compareSlices32(res, x) {
		t.Errorf("SGEMM: Expected %v, got %v", res, x)
	}
	SGEMM(ColMajor, Trans, Trans, m, k, m, alpha, amat, m, bmat, k, beta, y, m)
	resT := []float32{160.5, 153.6, 146.7, 139.8, 132.9, 140.2, 133.3, 126.4, 119.5, 112.6, 119.9, 113., 106.1, 99.2, 92.3}
	if !compareSlices32(resT, y) {
		t.Errorf("SGEMM, ColMajor, Transposed: Expected %v, got %v", res, y)
	}
	t.Logf("SGEMM Result: %v", x)
	t.Logf("SGEMM Result (Trasposed): %v", y)

}

func TestDGEMM(t *testing.T) {
	alpha, beta := 1.2, 2.3
	x, y := make([]float64, len(bmat)), make([]float64, len(bmat))
	copy(x, bbmat)
	copy(y, bbmat)

	//Transpose y
	inn := 0
	for i := 0; i < 3; i++ {
		for j := i; j < 15; j += 3 {
			y[inn] = bbmat[j]
			inn++
		}
	}

	res := []float64{160.5, 140.2, 119.9, 153.6, 133.3, 113., 146.7, 126.4, 106.1, 139.8, 119.5, 99.2, 132.9, 112.6, 92.3}
	DGEMM(RowMajor, NoTrans, NoTrans, m, k, m, alpha, aamat, m, bbmat, k, beta, x, k)
	if !compareSlices64(res, x) {
		t.Errorf("DGEMM: Expected %v, got %v", res, x)
	}
	DGEMM(ColMajor, Trans, Trans, m, k, m, alpha, aamat, m, bbmat, k, beta, y, m)
	resT := []float64{160.5, 153.6, 146.7, 139.8, 132.9, 140.2, 133.3, 126.4, 119.5, 112.6, 119.9, 113., 106.1, 99.2, 92.3}
	if !compareSlices64(resT, y) {
		t.Errorf("DGEMM, ColMajor, Transposed: Expected %v, got %v", res, y)
	}
	t.Logf("DGEMM Result: %v", x)
	t.Logf("DGEMM Result (Trasposed): %v", y)

}

func TestCGEMM(t *testing.T) {
	alpha, beta := complex64(complex(1.2, 2.3)), complex64(complex(3.4, 4.5))
	x, y := make([]complex64, len(dmat)), make([]complex64, len(dmat))
	copy(x, dmat)
	copy(y, dmat)

	//Transpose y
	inn := 0
	for i := 0; i < 3; i++ {
		for j := i; j < 15; j += 3 {
			y[inn] = dmat[j]
			inn++
		}
	}

	res := []complex64{complex(-1768.0, 965.6), complex(-1500.8, 840.8), complex(-1233.6, 716.0), complex(-1761.4, 918.2), complex(-1494.2, 793.4), complex(-1227.0, 668.6), complex(-1754.8, 870.8), complex(-1487.6, 746.0), complex(-1220.4, 621.2), complex(-1748.2, 823.4), complex(-1481.0, 698.6), complex(-1213.8, 573.8), complex(-1741.6, 776.0), complex(-1474.4, 651.2), complex(-1207.2, 526.4)}

	CGEMM(RowMajor, NoTrans, NoTrans, m, k, m, alpha, cmat, m, dmat, k, beta, x, k)
	if !compareSlicesC64(res, x) {
		t.Errorf("CGEMM: Expected\n%v\n, got\n%v", res, x)
	}
	CGEMM(ColMajor, Trans, Trans, m, k, m, alpha, cmat, m, dmat, k, beta, y, m)
	resT := []complex64{complex(-1768.0, 965.6), complex(-1761.4, 918.2), complex(-1754.8, 870.8), complex(-1748.2, 823.4), complex(-1741.6, 776.0), complex(-1500.8, 840.8), complex(-1494.2, 793.4), complex(-1487.6, 746.0), complex(-1481.0, 698.6), complex(-1474.4, 651.2), complex(-1233.6, 716.0), complex(-1227.0, 668.6), complex(-1220.4, 621.2), complex(-1213.8, 573.8), complex(-1207.2, 526.4)}
	if !compareSlicesC64(resT, y) {
		t.Errorf("CGEMM, ColMajor, Transposed: Expected %v, got %v", res, y)
	}
	t.Logf("CGEMM Result: %v", x)
	t.Logf("CGEMM Result (Trasposed): %v", y)

}

func TestZGEMM(t *testing.T) {
	alpha, beta := complex128(complex(1.2, 2.3)), complex128(complex(3.4, 4.5))
	x, y := make([]complex128, len(dmat)), make([]complex128, len(dmat))
	copy(x, ddmat)
	copy(y, ddmat)

	//Transpose y
	inn := 0
	for i := 0; i < 3; i++ {
		for j := i; j < 15; j += 3 {
			y[inn] = ddmat[j]
			inn++
		}
	}

	res := []complex128{complex(-1768.0, 965.6), complex(-1500.8, 840.8), complex(-1233.6, 716.0), complex(-1761.4, 918.2), complex(-1494.2, 793.4), complex(-1227.0, 668.6), complex(-1754.8, 870.8), complex(-1487.6, 746.0), complex(-1220.4, 621.2), complex(-1748.2, 823.4), complex(-1481.0, 698.6), complex(-1213.8, 573.8), complex(-1741.6, 776.0), complex(-1474.4, 651.2), complex(-1207.2, 526.4)}

	ZGEMM(RowMajor, NoTrans, NoTrans, m, k, m, alpha, ccmat, m, ddmat, k, beta, x, k)
	if !compareSlicesC128(res, x) {
		t.Errorf("CGEMM: Expected\n%v\n, got\n%v", res, x)
	}
	ZGEMM(ColMajor, Trans, Trans, m, k, m, alpha, ccmat, m, ddmat, k, beta, y, m)
	resT := []complex128{complex(-1768.0, 965.6), complex(-1761.4, 918.2), complex(-1754.8, 870.8), complex(-1748.2, 823.4), complex(-1741.6, 776.0), complex(-1500.8, 840.8), complex(-1494.2, 793.4), complex(-1487.6, 746.0), complex(-1481.0, 698.6), complex(-1474.4, 651.2), complex(-1233.6, 716.0), complex(-1227.0, 668.6), complex(-1220.4, 621.2), complex(-1213.8, 573.8), complex(-1207.2, 526.4)}
	if !compareSlicesC128(resT, y) {
		t.Errorf("CGEMM, ColMajor, Transposed: Expected %v, got %v", res, y)
	}
	t.Logf("CGEMM Result: %v", x)
	t.Logf("CGEMM Result (Trasposed): %v", y)

}

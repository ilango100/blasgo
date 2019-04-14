# BLASGo

[![GoDoc](https://godoc.org/github.com/ilango100/blasgo?status.svg)](https://godoc.org/github.com/ilango100/blasgo)
[![Build Status](https://travis-ci.org/ilango100/blasgo.svg?branch=master)](https://travis-ci.org/ilango100/blasgo)

BlasGo is a wrapper library providing [BLAS](http://www.netlib.org/blas/#_blas_routines) routines in Go. 

BlasGo tries to bring BLAS functions to "pure" Go, using BLAS implementation libraries (Intel MKL, NVIDIA CUDA etc). BlasGo needs a CBLAS/BLAS implementation library (Eg: OpenBLAS, ATLAS, etc.) to link against.

This is **not a pure Go implementation of BLAS**. Rather, this package bridges CBLAS/BLAS implementations with Go. The advantage is that it may be faster than pure Go implementation of BLAS functions, when used with accelereted library for running hardware.

This is a **Work in Progress**.

## BLAS libraries

This package should be able to link against any [CBLAS](http://www.netlib.org/blas/#_cblas)/[BLAS](http://www.netlib.org/blas/#_blas_routines) implementation. The cgo build flags has to be set accordingly. View [Linking instructions](https://github.com/ilango100/blasgo/blob/master/Linking.md) for more details.

Currently, the following libraries are tested:

|Library|Linux|Windows|
|-|-|-|
|BLAS Reference| &#9745; | &#9745; |
|OpenBLAS | &#9745; | &#9745; |
|Intel MKL | &#9745; | &#9745; |
|NVIDIA NVBLAS* | &#9745; | &#9745; |

\* - Needs BLAS flag while linking. See [Linking instructions](https://github.com/ilango100/blasgo/blob/master/Linking.md) for more details.

List of implementations: [Wiki](https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms#Implementations)

## Contributions

Any contributions in the form of issues or pull requests are always welcome. Feel free to contribute!

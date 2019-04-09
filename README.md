# BLASGo

[![GoDoc](https://godoc.org/github.com/ilango100/blasgo?status.svg)](https://godoc.org/github.com/ilango100/blasgo)
[![Build Status](https://travis-ci.org/ilango100/blasgo.svg?branch=master)](https://travis-ci.org/ilango100/blasgo)

BlasGo is a wrapper library providing [BLAS](http://www.netlib.org/blas/#_blas_routines) routines in Go. 

BlasGo tries to bring BLAS functions to "pure" Go, providing link options to accelerated libraries (Intel MKL, NVIDIA CUDA etc), where possible. BlasGo needs a "BLAS" C implementation library (Eg: OpenBLAS, ATLAS, etc.) to link against.

This is **not a pure Go implementation of BLAS**. Rather, this package bridges CBLAS implementations with Go, which are otherwise only available in C.

This is a **Work in Progress**.

## CBLAS libraries

This package should be able to link against any [CBLAS](http://www.netlib.org/blas/#_cblas) implementation. The cgo build flags has to be set accordingly. View [Linking instructions](https://github.com/ilango100/blasgo/blob/master/Linking.md) for more details.

Currently, the following libraries are tested:

|Library|Linux|Windows|
|-|-|-|
|BLAS Reference| &#9745; | &#9745; |
|OpenBLAS | &#9745; | &#9745; |
|Intel MKL | &#9745; | &#9745; |
|NVIDIA cuBLAS | &#9744; | &#9744; |

List of implementations: [Wiki](https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms#Implementations)

## Contributions

Any contributions in the form of issues or pull requests are always welcome. Feel free to contribute!

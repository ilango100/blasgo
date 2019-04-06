# Linking blasgo

As mentioned in the README, blasgo has to be linked to a valid CBLAS implementation to be able to work. The rationale for this is that there are multiple performance libraries for respective hardwares, which can accelerate the performance of BLAS calculations. **Eg**: Intel MKL, NVIDIA cuBLAS etc.

Environment variable CGO_LDFLAGS is required to be set to link with corresponding libraries. The -L flag should denote the directory in which the library is located and -l should be used to link with the respective library.

When using dynamic builds, make sure that the library, is in standard path or present in LD_LIBRARY_PATH to avoid errors like `error while loading shared libraries`.

## Windows
For windows, make sure these are followed:
- Use Mingw compilers. It's better to use Mingw-w64 compilers. Add the location of gcc to the PATH.
- For -L flag, use absolute path (D:\openblas\ etc)
- For static build use -static flag
- For dynamic build, add the directory containing .dll file to the PATH environment variable.


## CBLAS implementations

### [Reference implementation](http://www.netlib.org/blas/)
To link against reference implementation, both BLAS and CBLAS libraries are required.

`export CGO_LDFLAGS="-L../CBLAS/lib -L../BLAS-3.8.0 -l:cblas_LINUX.a -l:blas_LINUX.a"`

### [OpenBLAS](https://github.com/xianyi/OpenBLAS)
`export CGO_LDFLAGS="-L/opt/OpenBLAS/lib -lopenblas [-static]"`

### [Intel MKL](https://software.intel.com/en-us/mkl)
#### Linux
`export CGO_LDFLAGS="-L $HOME/intel/mkl/lib/intel64 -lmkl_rt"  #Dynamic  linking`

#### Windows (PowerShell)
```
$env:CGO_LDFLAGS="-L C:\path\to\mkl -lmkl_rt"
$env:Path="C:\path\to\mkl\compiler_and_libraries\windows\redist\intel64\mkl;C:\path\to\mkl\compiler_and_libraries\windows\redist\intel64\compiler;$env:Path" 
```
**Note**: The -L flag should specify the path where .lib files are located. Not where .dll files are located. Currently, static builds cannot be done in Windows due to lib files being import libraries. [Learn more](https://stackoverflow.com/a/43347809/3055011)

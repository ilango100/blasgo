# Linking blasgo

As mentioned in the README, blasgo has to be linked to a valid CBLAS/BLAS implementation to be able to work. The rationale for this is that there are multiple performance libraries for respective hardwares, which can accelerate the performance of BLAS calculations. **Eg**: Intel MKL, NVIDIA cuBLAS etc.

Environment variable CGO_LDFLAGS is required to be set to link with corresponding libraries. The -L flag should denote the directory in which the library is located and -l should be used to link with the respective library.

When using dynamic builds, make sure that the library, is in standard path or present in LD_LIBRARY_PATH to avoid errors like `error while loading shared libraries`.

## CBLAS or BLAS?

When only -L and -l flags are defined in CGO_LDFLAGS, the build searches for CBLAS routines like cblas_sdot etc. When you want to use BLAS routines instead, use `export CGO_CFLAGS="-DBLAS"` as additional environment variable. When using MKL with BLAS, you need to specify additional flag `-DMKL` due to differences.

## Windows
For windows, make sure these are followed:
- Use Mingw compilers. Don't forget to add the location of gcc to the PATH.
- For -L flag, use absolute path (D:\openblas\ etc)
- For static build use -static flag
- For dynamic build, add the directory containing .dll file to the PATH environment variable.


## Implementation wise instructions

### [Reference implementation](http://www.netlib.org/blas/)
To link against reference implementation, both BLAS and CBLAS libraries are required.

#### CBLAS build
`export CGO_LDFLAGS="-L../CBLAS/lib -L../BLAS-3.8.0 -l:cblas_LINUX.a -l:blas_LINUX.a"`
#### BLAS build
```
export CGO_CFLAGS="-DBLAS"
export CGO_LDFLAGS="-L../BLAS-3.8.0 -l:cblas_LINUX.a"
```

### [OpenBLAS](https://github.com/xianyi/OpenBLAS)
`export CGO_LDFLAGS="-L/opt/OpenBLAS/lib -lopenblas [-static]"`

For BLAS build, additionally: `export CGO_CFLAGS="-DBLAS"`

### [Intel MKL](https://software.intel.com/en-us/mkl)
#### Linux
`export CGO_LDFLAGS="-L $HOME/intel/mkl/lib/intel64 -lmkl_rt"  #Dynamic  linking`

For BLAS build, additionally: `export CGO_CFLAGS="-DBLAS -DMKL"`

#### Windows (PowerShell)
```
$env:CGO_LDFLAGS="-L C:\path\to\mkl -lmkl_rt"
$env:Path="C:\path\to\mkl\compiler_and_libraries\windows\redist\intel64\mkl;C:\path\to\mkl\compiler_and_libraries\windows\redist\intel64\compiler;$env:Path" 
```
**Note**: The -L flag should specify the path where .lib files are located. Not where .dll files are located. Currently, static builds cannot be done in Windows due to lib files being import libraries. [Learn more](https://stackoverflow.com/a/43347809/3055011)

### [NVDIA NVBLAS](https://docs.nvidia.com/cuda/nvblas/index.html)
When using NVBLAS, only Level 3 Matrix Matrix functions are accelerated. Hence another BLAS implementation is required. Further NVBLAS only provied BLAS functions and not CBLAS bindings. Hence the other library should also be linked with BLAS flag.

While using NVBLAS, a configuration file should be provided. Please read [NVBLAS documentation](https://docs.nvidia.com/cuda/nvblas/index.html) while using NVBLAS.

#### NVBLAS+MKL:
##### Linux
```
export CGO_LDFLAGS="-L /path/to/nvidia_libraries -lnvblas -L $HOME/intel/mkl/lib/intel64 -lmkl_rt"
export CGO_CFLAGS="-DBLAS -DMKL"
export NVBLAS_CONFIG_FILE="$HOME/nvblas.conf"
```
##### Windows (Powershell)
```
$env:CGO_LDFLAGS="-L C:\path\to\cuda_libraries -lnvblas -L C:\path\to\IntelMKL\compilers_and_libraries_2019\windows\mkl\lib\intel64 -lmkl_rt"
$env:CGO_CFLAGS="-DBLAS -DMKL"
$env:Path="C:\path\to\IntelMKL\compilers_and_libraries\windows\redist\intel64\mkl;C:\path\to\IntelMKL\compilers_and_libraries\windows\redist\intel64\compiler;$env:Path"
$env:NVBLAS_CONFIG_FILE="C:\nvblas.conf"
```
#### NVBLAS+OpenBLAS:
##### Linux
```
export CGO_LDFLAGS="-L /path/to/nvidia_libraries -lnvblas -L $/opt/OpenBLAS/lib -lopenblas"
export CGO_CFLAGS="-DBLAS"
export NVBLAS_CONFIG_FILE="$HOME/nvblas.conf"
```
##### Windows (Powershell)
```
$env:CGO_LDFLAGS="-L C:\path\to\cuda_libraries -lnvblas -L C:\path\to\OpenBLAS -lopenblas"
$env:CGO_CFLAGS="-DBLAS"
$env:Path="C:\path\to\OpenBLAS;$env:Path"
$env:NVBLAS_CONFIG_FILE="D:\MathLib\nvblas.conf"
```

In case of any Linking errors, difficulties, feel free to open an issue.

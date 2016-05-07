# ccVector
ccVector is a quaternion and matrix math library.

Functions for `2`, `3` and `4` dimensional vectors are defined. Functions for `2x2`, `3x3` and `4x4` sized matrices are defined. Quaternions are available and interchangeable with 4 dimensional vectors.

If more types are needed, `CCV_DEFINE_VEC(n)` can be used to define `n` dimensional vectors and `CCV_DEFINE_MAT(n)` can be used to define `nxn` sized matrices.

The typedef `ccvType` is `float` by default, but can be any floating point type. All vector and matrix elements will be of the type `ccvType`. Functions for sine, cosine, tangent and square root can also be changed. By default, functions from `math.h` are used.

Function and type names can be changed if preferred. By default, a 3 dimensional vector type is defined as `vec3`, and the function to normalize it is defined as `vec3 vec3Normalize(vec3 v)`. This can be changed to `v3 v3_normalize(v3 v)` for example by altering macro definitions at the beginning of the file.

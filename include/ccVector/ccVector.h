//__________________________________________________________________________________//
//                                                                                  //
//                           __      __       _                                     //
//                           \ \    / /      | |                                    //
//                      ___ __\ \  / /__  ___| |_ ___  _ __                         //
//                     / __/ __\ \/ / _ \/ __| __/ _ \| '__|                        //
//                    | (_| (__ \  /  __/ (__| || (_) | |                           //
//                     \___\___| \/ \___|\___|\__\___/|_| v1.0                      //
//                                                                                  //
//                 Copyright (C) 2015 \ Job Talle (job@ccore.org)                   //
//__________________________________________________________________________________//
//                                                                                  //
//      This program is free software: you can redistribute it and/or modify        //
//      it under the terms of the 3-clause BSD license.                             //
//                                                                                  //
//      You should have received a copy of the 3-clause BSD License along with      //
//      this program. If not, see <http://opensource.org/licenses/>.                //
//__________________________________________________________________________________//

// Vector functions
//
// CCV_DEFINE_VEC(n)                    Defines n-dimensional vector ccvVec<n> and its functions
//
// ccvVec<n>Zero(v)                     Sets all elements in vector v to 0
// ccvVec<n>Add(v, a, b)                Add vectors a and b and stores the result in vector v
// ccvVec<n>Subtract(v, a, b)           Subtracts vector b from vector a and stores the result in vector v
// ccvVec<n>Copy(dest, source)          Copies vector source to vector dest
// ccvVec<n>Crossproduct(v, a, b)       Takes the cross product from vectors a and b and stores it in vector v
// ccvVec<n>Multiply(v, n)              Multiplies vector v with scalar n
// ccvVec<n>DotProduct(a, b)            Returns the dot product from vectors a and b
// ccvVec<n>Length(v)                   Returns the length of vector v
// ccvVec<n>Normalize(v)                Scales vector v to have a length of 1
// ccvVec<n>Reflect(v, n, r)            Reflects vector r by normal n and stores the result in vector v

// Matrix functions
//
// CCV_DEFINE_MAT(n)                    Defines n x n matrix ccvMat<n>x<n> and its functions
//
// ccvMat<n>x<n>Zero(m)                 Sets all elements in matrix m to 0
// ccvMat<n>x<n>Add(m, a, b)            Adds matrices a and b and stores the result in matrix m
// ccvMat<n>x<n>Subtract(m, a, b)       Subtracts matrix b from matrix a and stores the result in matrix m
// ccvMat<n>x<n>Copy(dest, source)      Copies matrix source to matrix dest
// ccvMat<n>x<n>Identity(m)             Sets matrix m to the identity matrix
// ccvMat<n>x<n>MultiplyScalar(m, n)    Multiplies matrix m by scalar n
// ccvMat<n>x<n>MultiplyVector(v, a, b) Multiplies matrix a by vector b and stores the result in vector v
// ccvMat<n>x<n>MultiplyMatrix(m, a, b) Multiplies matrix a by matrix b and stores the result in matrix m

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <math.h>
#include <string.h>

#ifdef _MSC_VER
#ifndef inline
#define inline __inline
#endif
#endif

// Type

#define _CCV_TYPE float

// Prefixes

#define _CCV_VEC_TYPENAME(dim) ccVec##dim

#define _CCV_MAT_TYPENAME(dim) ccMat##dim##x##dim

// Type definitions

#define _CCV_DEFINE_VEC_TYPE(dim) \
	typedef _CCV_TYPE _CCV_VEC_TYPENAME(dim)[dim];

#define _CCV_DEFINE_MAT_TYPE(dim) \
	typedef _CCV_TYPE _CCV_MAT_TYPENAME(dim)[dim][dim];

// Vector operations

#define _CCV_DEFINE_VEC_ZERO(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Zero(_CCV_VEC_TYPENAME(dim) v) { \
		memset(v, 0, sizeof(_CCV_TYPE)* dim); \
	}

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Add(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] = a[i] + b[i]; \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Subtract(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] = a[i] - b[i]; \
	}

#define _CCV_DEFINE_VEC_COPY(dim) \
	static inline _CCV_VEC_TYPENAME(dim)##Copy(_CCV_VEC_TYPENAME(dim) dest, const _CCV_VEC_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(_CCV_TYPE) * dim); \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Multiply(_CCV_VEC_TYPENAME(dim) v, const _CCV_TYPE n) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] *= n; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline _CCV_TYPE _CCV_VEC_TYPENAME(dim)##DotProduct(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		_CCV_TYPE result = 0; \
		for(i = 0; i < dim; i++) \
			result += a[i] * b[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline _CCV_TYPE _CCV_VEC_TYPENAME(dim)##Length(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		_CCV_TYPE squaredResult = 0; \
		for(i = 0; i < dim; i++) \
			squaredResult += v[i] * v[i]; \
		return (_CCV_TYPE)sqrt(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim)##Normalize(_CCV_VEC_TYPENAME(dim) v) { \
		_CCV_VEC_TYPENAME(dim)##Multiply(v, 1 / _CCV_VEC_TYPENAME(dim)##Length(v)); \
	}

#define _CCV_DEFINE_VEC_REFLECT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Reflect(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) n, const _CCV_VEC_TYPENAME(dim) r) { \
		_CCV_VEC_TYPENAME(dim) _v; \
		_CCV_VEC_TYPENAME(dim)##Copy(_v, n); \
		_CCV_VEC_TYPENAME(dim)##Multiply(_v, 2 * _CCV_VEC_TYPENAME(dim)##DotProduct(n, r)); \
		_CCV_VEC_TYPENAME(dim)##Subtract(v, r, _v); \
	}

// Matrix operations

#define _CCV_DEFINE_MAT_ZERO(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Zero(_CCV_MAT_TYPENAME(dim) m) { \
		memset(m, 0, sizeof(_CCV_TYPE)* dim * dim); \
	}

#define _CCV_DEFINE_MAT_ADD(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Add(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(row = 0; row < dim; row++) \
			for(col = 0; col < dim; col++) \
				m[row][col] = a[row][col] + b[row][col]; \
	}

#define _CCV_DEFINE_MAT_SUBTRACT(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Subtract(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(row = 0; row < dim; row++) \
			for(col = 0; col < dim; col++) \
				m[row][col] = a[row][col] - b[row][col]; \
	}

#define _CCV_DEFINE_MAT_COPY(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Copy(_CCV_MAT_TYPENAME(dim) dest, const _CCV_MAT_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(_CCV_TYPE) * dim * dim); \
	}

#define _CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Identity(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int i; \
		_CCV_MAT_TYPENAME(dim)##Zero(m); \
		for(i = 0; i < dim; i++) \
			m[i][i] = 1; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyScalar(_CCV_MAT_TYPENAME(dim) m, const _CCV_TYPE n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; col++) \
			for(row = 0; row < dim; row++) m[row][col] *= n; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyVector(_CCV_VEC_TYPENAME(dim) v, const _CCV_MAT_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i, j; \
		for(i = 0; i < dim; i++) { \
			v[i] = a[0][i] * b[0]; \
			for(j = 1; j < dim; j++) \
				v[i] += a[j][i] * b[j]; \
		} \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyMatrix(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j, k; \
		for(i = 0; i < dim; i++) \
			for(j = 0; j < dim; j++) { \
				m[i][j] = a[i][0] * b[0][j]; \
				for(k = 1; k < dim; k++) \
					m[i][j] += a[i][k] * b[k][j]; \
			} \
	}

// Definition calls

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ZERO(dim) \
	_CCV_DEFINE_VEC_ADD(dim) \
	_CCV_DEFINE_VEC_SUBTRACT(dim) \
	_CCV_DEFINE_VEC_COPY(dim) \
	_CCV_DEFINE_VEC_MULTIPLY(dim) \
	_CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	_CCV_DEFINE_VEC_LENGTH(dim) \
	_CCV_DEFINE_VEC_NORMALIZE(dim) \
	_CCV_DEFINE_VEC_REFLECT(dim)

#define CCV_DEFINE_MAT(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_MAT_TYPE(dim) \
	_CCV_DEFINE_MAT_ZERO(dim) \
	_CCV_DEFINE_MAT_ADD(dim) \
	_CCV_DEFINE_MAT_SUBTRACT(dim) \
	_CCV_DEFINE_MAT_COPY(dim) \
	_CCV_DEFINE_MAT_IDENTITY(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim)

// Define 2d, 3d and 4d vectors and matrices

CCV_DEFINE_VEC(2)
CCV_DEFINE_VEC(3)
CCV_DEFINE_VEC(4)

CCV_DEFINE_MAT(2)
CCV_DEFINE_MAT(3)
CCV_DEFINE_MAT(4)

// Shorthand transformation multiplier

#define CCV_APPLY_MATRIX(type, operation) { \
	type buffer, multiply; \
	operation##; \
	type##Copy(buffer, m); \
	type##MultiplyMatrix(m, buffer, multiply); \
}

// Define normals & cross products

static inline void ccVec2Orthogonal(ccVec2 v, const ccVec2 a)
{
	v[0] = -a[1];
	v[1] = a[0];
}

#define _CCV_SET_CROSS_PRODUCT() \
	v[0] = a[1] * b[2] - a[2] * b[1]; \
	v[1] = a[2] * b[0] - a[0] * b[2]; \
	v[2] = a[0] * b[1] - a[1] * b[0]

static inline void ccVec3CrossProduct(ccVec3 v, const ccVec3 a, const ccVec3 b)
{
	_CCV_SET_CROSS_PRODUCT();
}

static inline void ccVec4CrossProduct(ccVec4 v, const ccVec4 a, const ccVec4 b)
{
	_CCV_SET_CROSS_PRODUCT();
	v[3] = 1;
}

// Define rotation methods

#define _CCV_SET_ROTATION_2D() \
	m[0][0] = (_CCV_TYPE)cos(r); \
	m[0][1] = (_CCV_TYPE)sin(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]

static inline void ccMat2x2SetRotation(ccMat2x2 m, const _CCV_TYPE r)
{
	_CCV_SET_ROTATION_2D();
}

static inline void ccMat2x2Rotate(ccMat2x2 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat2x2, ccMat2x2SetRotation(multiply, r));

static inline void ccMat3x3SetRotation2D(ccMat3x3 m, const _CCV_TYPE r)
{
	ccMat3x3Zero(m);

	_CCV_SET_ROTATION_2D();
	m[2][2] = 1;
}

static inline void ccMat3x3Rotate2D(ccMat3x3 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotation2D(multiply, r));

#define _CCV_SET_ROTATION_3D_X() \
	m[0][0] = 1; \
	m[1][1] = (_CCV_TYPE)cos(r); \
	m[1][2] = (_CCV_TYPE)sin(r); \
	m[2][1] = -m[1][2]; \
	m[2][2] = m[1][1]

#define _CCV_SET_ROTATION_3D_Y() \
	m[0][0] = (_CCV_TYPE)cos(r); \
	m[2][0] = (_CCV_TYPE)sin(r); \
	m[1][1] = 1; \
	m[0][2] = -m[2][0]; \
	m[2][2] = m[0][0]

#define _CCV_SET_ROTATION_3D_Z() \
	m[0][0] = (_CCV_TYPE)cos(r); \
	m[0][1] = (_CCV_TYPE)sin(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]; \
	m[2][2] = 1

static inline void ccMat3x3SetRotationX(ccMat3x3 m, const _CCV_TYPE r)
{
	_CCV_SET_ROTATION_3D_X();
}

static inline void ccMat3x3SetRotationY(ccMat3x3 m, const _CCV_TYPE r)
{
	_CCV_SET_ROTATION_3D_Y();
}

static inline void ccMat3x3SetRotationZ(ccMat3x3 m, const _CCV_TYPE r)
{
	_CCV_SET_ROTATION_3D_Z();
}

static inline void ccMat3x3RotateX(ccMat3x3 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotationX(multiply, r))

static inline void ccMat3x3RotateY(ccMat3x3 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotationY(multiply, r))

static inline void ccMat3x3RotateZ(ccMat3x3 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotationZ(multiply, r))

static inline void ccMat4x4SetRotationX(ccMat4x4 m, const _CCV_TYPE r)
{
	ccMat4x4Zero(m);

	_CCV_SET_ROTATION_3D_X();
	m[3][3] = 1;
}

static inline void ccMat4x4SetRotationY(ccMat4x4 m, const _CCV_TYPE r)
{
	ccMat4x4Zero(m);

	_CCV_SET_ROTATION_3D_Y();
	m[3][3] = 1;
}

static inline void ccMat4x4SetRotationZ(ccMat4x4 m, const _CCV_TYPE r)
{
	ccMat4x4Zero(m);

	_CCV_SET_ROTATION_3D_Z();
	m[3][3] = 1;
}

static inline void ccMat4x4RotateX(ccMat4x4 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetRotationX(multiply, r))

static inline void ccMat4x4RotateY(ccMat4x4 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetRotationY(multiply, r))

static inline void ccMat4x4RotateZ(ccMat4x4 m, const _CCV_TYPE r) CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetRotationZ(multiply, r))

// Define translation methods

static inline void ccMat3x3SetTranslation(ccMat3x3 m, const ccVec2 v)
{
	ccMat3x3Identity(m);

	m[2][0] = v[0];
	m[2][1] = v[1];
}

static inline void ccMat3x3Translate(ccMat3x3 m, const ccVec2 v) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetTranslation(multiply, v))

static inline void ccMat4x4SetTranslation(ccMat4x4 m, const ccVec3 v)
{
	ccMat4x4Identity(m);

	m[3][0] = v[0];
	m[3][1] = v[1];
	m[3][2] = v[2];
}

static inline void ccMat4x4Translate(ccMat4x4 m, const ccVec3 v) CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetTranslation(multiply, v))

// Define scaling methods

static inline void ccMat2x2SetScale(ccMat2x2 m, const _CCV_TYPE scale)
{
	m[0][0] = m[1][1] = scale;
	m[1][0] = m[0][1] = 0;
}

static inline void ccMat2x2Scale(ccMat2x2 m, const _CCV_TYPE scale) CCV_APPLY_MATRIX(ccMat2x2, ccMat2x2SetScale(multiply, scale))

static inline void ccMat3x3SetScale2D(ccMat3x3 m, const _CCV_TYPE scale)
{
	ccMat3x3Zero(m);

	m[2][2] = 1;
	m[0][0] = m[1][1] = scale;
}

static inline void ccMat3x3Scale2D(ccMat3x3 m, const _CCV_TYPE scale) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetScale2D(multiply, scale))

static inline void ccMat3x3SetScale(ccMat3x3 m, const _CCV_TYPE scale)
{
	ccMat3x3Zero(m);
	
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void ccMat3x3Scale(ccMat3x3 m, const _CCV_TYPE scale) CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetScale(multiply, scale))

static inline void ccMat4x4SetScale(ccMat4x4 m, const _CCV_TYPE scale)
{
	ccMat4x4Zero(m);
	
	m[3][3] = 1;
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void ccMat4x4Scale(ccMat4x4 m, const _CCV_TYPE scale) CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetScale(multiply, scale))

#ifdef __cplusplus
}
#endif
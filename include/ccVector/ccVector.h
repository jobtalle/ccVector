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

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <math.h>
#include <string.h>

#ifdef _MSC_VER
#define inline __inline
#endif

// Type

typedef float ccvType;

// Prefixes

#define _CCV_VEC_TYPENAME(dim) ccVec##dim

#define _CCV_MAT_TYPENAME(dim) ccMat##dim##x##dim

// Type definitions

#define _CCV_DEFINE_VEC_TYPE(dim)

#define _CCV_DEFINE_MAT_TYPE(dim) \
	typedef ccvType _CCV_MAT_TYPENAME(dim)[dim][dim];

// Vector operations

#define _CCV_DEFINE_VEC_ZERO(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_VEC_TYPENAME(dim)##Zero(void) { \
		_CCV_VEC_TYPENAME(dim) v; \
		memset(&v, 0, sizeof(_CCV_VEC_TYPENAME(dim))); \
		return v; \
	}

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_VEC_TYPENAME(dim)##Add(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v.v[i] = a.v[i] + b.v[i]; \
		return v; \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_VEC_TYPENAME(dim)##Subtract(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v.v[i] = a.v[i] - b.v[i]; \
		return v; \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_VEC_TYPENAME(dim)##Multiply(_CCV_VEC_TYPENAME(dim) v, const ccvType n) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v.v[i] *= n; \
		return v; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline ccvType _CCV_VEC_TYPENAME(dim)##DotProduct(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		ccvType result = 0; \
		for(i = 0; i < dim; i++) \
			result += a.v[i] * b.v[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline ccvType _CCV_VEC_TYPENAME(dim)##Length(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		ccvType squaredResult = 0; \
		for(i = 0; i < dim; i++) \
			squaredResult += v.v[i] * v.v[i]; \
		return (ccvType)sqrt(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_VEC_TYPENAME(dim)##Normalize(_CCV_VEC_TYPENAME(dim) v) { \
		return _CCV_VEC_TYPENAME(dim)##Multiply(v, 1 / _CCV_VEC_TYPENAME(dim)##Length(v)); \
	}

#define _CCV_DEFINE_VEC_REFLECT(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_VEC_TYPENAME(dim)##Reflect(const _CCV_VEC_TYPENAME(dim) n, const _CCV_VEC_TYPENAME(dim) r) { \
		return _CCV_VEC_TYPENAME(dim)##Subtract(r, _CCV_VEC_TYPENAME(dim)##Multiply(n, 2 * _CCV_VEC_TYPENAME(dim)##DotProduct(n, r))); \
	}

// Matrix operations

#define _CCV_DEFINE_MAT_ZERO(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##Zero(_CCV_MAT_TYPENAME(dim) m) { \
		memset(m, 0, sizeof(ccvType)* dim * dim); \
	}

#define _CCV_DEFINE_MAT_ADD(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##Add(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(row = 0; row < dim; row++) \
			for(col = 0; col < dim; col++) \
				m[row][col] = a[row][col] + b[row][col]; \
	}

#define _CCV_DEFINE_MAT_SUBTRACT(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##Subtract(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(row = 0; row < dim; row++) \
			for(col = 0; col < dim; col++) \
				m[row][col] = a[row][col] - b[row][col]; \
	}

#define _CCV_DEFINE_MAT_COPY(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##Copy(_CCV_MAT_TYPENAME(dim) dest, const _CCV_MAT_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(ccvType) * dim * dim); \
	}

#define _CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##Identity(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int i; \
		_CCV_MAT_TYPENAME(dim)##Zero(m); \
		for(i = 0; i < dim; i++) \
			m[i][i] = 1; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##MultiplyScalar(_CCV_MAT_TYPENAME(dim) m, const ccvType n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; col++) \
			for(row = 0; row < dim; row++) m[row][col] *= n; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_MAT_TYPENAME(dim)##MultiplyVector(const _CCV_MAT_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i, j; \
		for(i = 0; i < dim; i++) { \
			v.v[i] = a[0][i] * b.v[0]; \
			for(j = 1; j < dim; j++) \
				v.v[i] += a[j][i] * b.v[j]; \
		} \
		return v; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	static inline void _CCV_MAT_TYPENAME(dim)##MultiplyMatrix(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j, k; \
		for(i = 0; i < dim; i++) \
			for(j = 0; j < dim; j++) { \
				m[i][j] = a[i][0] * b[0][j]; \
				for(k = 1; k < dim; k++) \
					m[i][j] += a[i][k] * b[k][j]; \
			} \
	}

#define _CCV_DEFINE_MAT_GET_ROW(dim) \
	static inline _CCV_VEC_TYPENAME(dim)  _CCV_MAT_TYPENAME(dim)##GetRow(_CCV_MAT_TYPENAME(dim) m, const int n) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v.v[i] = m[i][n]; \
		return v; \
	}

#define _CCV_DEFINE_MAT_GET_COL(dim) \
	static inline _CCV_VEC_TYPENAME(dim)  _CCV_MAT_TYPENAME(dim)##GetCol(_CCV_MAT_TYPENAME(dim) m, const int n) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v.v[i] = m[n][i]; \
		return v; \
	}

// Definition calls

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ZERO(dim) \
	_CCV_DEFINE_VEC_ADD(dim) \
	_CCV_DEFINE_VEC_SUBTRACT(dim) \
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
	_CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	_CCV_DEFINE_MAT_GET_ROW(dim) \
	_CCV_DEFINE_MAT_GET_COL(dim)

// Vector type override

typedef union {
	ccvType v[2];
	struct { ccvType x, y; };
} _CCV_VEC_TYPENAME(2);

typedef union {
	ccvType v[3];
	union {
		struct {
			union {
				struct { ccvType x, y; };
				union {
					ccVec2 xy;
					ccVec2 vec2;
				};
			};
			union {
				ccvType z;
				ccvType w;
			};
		};
		struct {
			ccvType _x;
			ccVec2 yz;
		};
	};
} _CCV_VEC_TYPENAME(3);

typedef union {
	ccvType v[4];
	union {
		struct {
			union {
				struct {
					union {
						struct { ccvType x, y; };
						ccVec2 xy;
					};
					ccvType z, w;
				};
				struct {
					ccvType _x;
					union {
						struct { ccvType _y, _z; };
						ccVec2 yz;
					};
					ccvType _w;
				};
			};
		};
		struct {
			ccVec3 vec3;
			ccvType __w;
		};
	};
} _CCV_VEC_TYPENAME(4);

// Define 2d, 3d and 4d vectors and matrices

CCV_DEFINE_VEC(2)
CCV_DEFINE_VEC(3)
CCV_DEFINE_VEC(4)

CCV_DEFINE_MAT(2)
CCV_DEFINE_MAT(3)
CCV_DEFINE_MAT(4)

// General vector type

#undef _CCV_DEFINE_VEC_TYPE
#define _CCV_DEFINE_VEC_TYPE(dim) \
	typedef struct { \
		ccvType v[dim]; \
	} _CCV_VEC_TYPENAME(dim);

// Shorthand transformation multiplier

#define _CCV_APPLY_MATRIX(type, operation) { \
	type buffer, multiply; \
	operation##; \
	type##Copy(buffer, m); \
	type##MultiplyMatrix(m, buffer, multiply); \
}

// Define vector utilities

static inline ccVec2 ccVec2Orthogonal(const ccVec2 a)
{
	ccVec2 v;

	v.x = -a.y;
	v.y = a.x;

	return v;
}

static inline ccVec3 ccVec3CrossProduct(const ccVec3 a, const ccVec3 b)
{
	ccVec3 v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;

	return v;
}

// Define rotation methods

#define _CCV_SET_ROTATION_2D() \
	m[0][0] = (ccvType)cos(r); \
	m[0][1] = (ccvType)sin(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]

static inline void ccMat2x2SetRotation(ccMat2x2 m, const ccvType r)
{
	_CCV_SET_ROTATION_2D();
}

static inline void ccMat2x2Rotate(ccMat2x2 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat2x2, ccMat2x2SetRotation(multiply, r));

static inline void ccMat3x3SetRotation2D(ccMat3x3 m, const ccvType r)
{
	ccMat3x3Zero(m);

	_CCV_SET_ROTATION_2D();
	m[2][2] = 1;
}

static inline void ccMat3x3Rotate2D(ccMat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotation2D(multiply, r));

#define _CCV_SET_ROTATION_3D_X() \
	m[0][0] = 1; \
	m[1][1] = (ccvType)cos(r); \
	m[1][2] = (ccvType)sin(r); \
	m[2][1] = -m[1][2]; \
	m[2][2] = m[1][1]

#define _CCV_SET_ROTATION_3D_Y() \
	m[0][0] = (ccvType)cos(r); \
	m[2][0] = (ccvType)sin(r); \
	m[1][1] = 1; \
	m[0][2] = -m[2][0]; \
	m[2][2] = m[0][0]

#define _CCV_SET_ROTATION_3D_Z() \
	m[0][0] = (ccvType)cos(r); \
	m[0][1] = (ccvType)sin(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]; \
	m[2][2] = 1

static inline void ccMat3x3SetRotationX(ccMat3x3 m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_X();
}

static inline void ccMat3x3SetRotationY(ccMat3x3 m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_Y();
}

static inline void ccMat3x3SetRotationZ(ccMat3x3 m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_Z();
}

static inline void ccMat3x3RotateX(ccMat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotationX(multiply, r))

static inline void ccMat3x3RotateY(ccMat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotationY(multiply, r))

static inline void ccMat3x3RotateZ(ccMat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetRotationZ(multiply, r))

static inline void ccMat4x4SetRotationX(ccMat4x4 m, const ccvType r)
{
	ccMat4x4Zero(m);

	_CCV_SET_ROTATION_3D_X();
	m[3][3] = 1;
}

static inline void ccMat4x4SetRotationY(ccMat4x4 m, const ccvType r)
{
	ccMat4x4Zero(m);

	_CCV_SET_ROTATION_3D_Y();
	m[3][3] = 1;
}

static inline void ccMat4x4SetRotationZ(ccMat4x4 m, const ccvType r)
{
	ccMat4x4Zero(m);

	_CCV_SET_ROTATION_3D_Z();
	m[3][3] = 1;
}

static inline void ccMat4x4RotateX(ccMat4x4 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetRotationX(multiply, r))

static inline void ccMat4x4RotateY(ccMat4x4 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetRotationY(multiply, r))

static inline void ccMat4x4RotateZ(ccMat4x4 m, const ccvType r) _CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetRotationZ(multiply, r))

// Define translation methods

static inline void ccMat3x3SetTranslation(ccMat3x3 m, const ccVec2 v)
{
	ccMat3x3Identity(m);

	m[2][0] = v.x;
	m[2][1] = v.y;
}

static inline void ccMat3x3Translate(ccMat3x3 m, const ccVec2 v) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetTranslation(multiply, v))

static inline void ccMat4x4SetTranslation(ccMat4x4 m, const ccVec3 v)
{
	ccMat4x4Identity(m);

	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
}

static inline void ccMat4x4Translate(ccMat4x4 m, const ccVec3 v) _CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetTranslation(multiply, v))

// Define scaling methods

static inline void ccMat2x2SetScale(ccMat2x2 m, const ccvType scale)
{
	m[0][0] = m[1][1] = scale;
	m[1][0] = m[0][1] = 0;
}

static inline void ccMat2x2Scale(ccMat2x2 m, const ccvType scale) _CCV_APPLY_MATRIX(ccMat2x2, ccMat2x2SetScale(multiply, scale))

static inline void ccMat3x3SetScale2D(ccMat3x3 m, const ccvType scale)
{
	ccMat3x3Zero(m);

	m[2][2] = 1;
	m[0][0] = m[1][1] = scale;
}

static inline void ccMat3x3Scale2D(ccMat3x3 m, const ccvType scale) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetScale2D(multiply, scale))

static inline void ccMat3x3SetScale(ccMat3x3 m, const ccvType scale)
{
	ccMat3x3Zero(m);
	
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void ccMat3x3Scale(ccMat3x3 m, const ccvType scale) _CCV_APPLY_MATRIX(ccMat3x3, ccMat3x3SetScale(multiply, scale))

static inline void ccMat4x4SetScale(ccMat4x4 m, const ccvType scale)
{
	ccMat4x4Zero(m);
	
	m[3][3] = 1;
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void ccMat4x4Scale(ccMat4x4 m, const ccvType scale) _CCV_APPLY_MATRIX(ccMat4x4, ccMat4x4SetScale(multiply, scale))

#ifdef __cplusplus
}
#endif
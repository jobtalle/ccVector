//__________________________________________________________________________________//
//                           __      __       _                                     //
//                           \ \    / /      | |                                    //
//                      ___ __\ \  / /__  ___| |_ ___  _ __                         //
//                     / __/ __\ \/ / _ \/ __| __/ _ \| '__|                        //
//                    | (_| (__ \  /  __/ (__| || (_) | |                           //
//                     \___\___| \/ \___|\___|\__\___/|_| v1.1                      //
//                                                                                  //
//           Copyright (C) 2015 - 2016 \ Job Talle (jobtalle@hotmail.com)           //
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

#ifndef inline
#ifdef _MSC_VER
#define inline __inline
#endif
#endif

// Concatenation utility

#define _CAT2(a, b) a##b
#define CAT2(a, b) _CAT2(a, b)

// Number type

typedef float ccvType;

// Math functions

#define _CCV_COS  cosf
#define _CCV_SIN  sinf
#define _CCV_TAN  tanf
#define _CCV_SQRT sqrtf

// Type names

#define _CCV_VEC_TYPENAME(dim) vec##dim
#define _CCV_QUAT_TYPENAME     quat
#define _CCV_MAT_TYPENAME(dim) mat##dim##x##dim

// Function names

#define _CCV_FUNC_VEC_ZERO(dim)            CAT2(_CCV_VEC_TYPENAME(dim), Zero)
#define _CCV_FUNC_VEC_NEGATE(dim)          CAT2(_CCV_VEC_TYPENAME(dim), Negate)
#define _CCV_FUNC_VEC_ISZERO(dim)          CAT2(_CCV_VEC_TYPENAME(dim), IsZero)
#define _CCV_FUNC_VEC_ADD(dim)             CAT2(_CCV_VEC_TYPENAME(dim), Add)
#define _CCV_FUNC_VEC_SUBTRACT(dim)        CAT2(_CCV_VEC_TYPENAME(dim), Subtract)
#define _CCV_FUNC_VEC_MULTIPLY(dim)        CAT2(_CCV_VEC_TYPENAME(dim), Multiply)
#define _CCV_FUNC_VEC_DOTPRODUCT(dim)      CAT2(_CCV_VEC_TYPENAME(dim), DotProduct)
#define _CCV_FUNC_VEC_LENGTH(dim)          CAT2(_CCV_VEC_TYPENAME(dim), Length)
#define _CCV_FUNC_VEC_NORMALIZE(dim)       CAT2(_CCV_VEC_TYPENAME(dim), Normalize)
#define _CCV_FUNC_VEC_REFLECT(dim)         CAT2(_CCV_VEC_TYPENAME(dim), Reflect)
#define _CCV_FUNC_VEC_ORTHOGONAL(dim)      CAT2(_CCV_VEC_TYPENAME(dim), Orthogonal)
#define _CCV_FUNC_VEC_CROSS_PRODUCT(dim)   CAT2(_CCV_VEC_TYPENAME(dim), CrossProduct)

#define _CCV_FUNC_QUAT_IDENTITY            CAT2(_CCV_QUAT_TYPENAME, Identity)
#define _CCV_FUNC_QUAT_ROTATE              CAT2(_CCV_QUAT_TYPENAME, Rotate)
#define _CCV_FUNC_QUAT_MULTIPLY            CAT2(_CCV_QUAT_TYPENAME, Multiply)
#define _CCV_FUNC_QUAT_ADD_ROTATION        CAT2(_CCV_QUAT_TYPENAME, AddRotation)
#define _CCV_FUNC_QUAT_MULTIPLY_VECTOR     CAT2(_CCV_QUAT_TYPENAME, MultiplyVector)
#define _CCV_FUNC_QUAT_ADD                 CAT2(_CCV_QUAT_TYPENAME, Add)
#define _CCV_FUNC_QUAT_SUBTRACT            CAT2(_CCV_QUAT_TYPENAME, Subtract)
#define _CCV_FUNC_QUAT_SCALE               CAT2(_CCV_QUAT_TYPENAME, Scale)

#define _CCV_FUNC_MAT_ZERO(dim)            CAT2(_CCV_MAT_TYPENAME(dim), Zero)
#define _CCV_FUNC_MAT_ISZERO(dim)          CAT2(_CCV_MAT_TYPENAME(dim), IsZero)
#define _CCV_FUNC_MAT_ADD(dim)             CAT2(_CCV_MAT_TYPENAME(dim), Add)
#define _CCV_FUNC_MAT_SUBTRACT(dim)        CAT2(_CCV_MAT_TYPENAME(dim), Subtract)
#define _CCV_FUNC_MAT_COPY(dim)            CAT2(_CCV_MAT_TYPENAME(dim), Copy)
#define _CCV_FUNC_MAT_IDENTITY(dim)        CAT2(_CCV_MAT_TYPENAME(dim), Identity)
#define _CCV_FUNC_MAT_MULTIPLY_SCALAR(dim) CAT2(_CCV_MAT_TYPENAME(dim), MultiplyScalar)
#define _CCV_FUNC_MAT_MULTIPLY_VECTOR(dim) CAT2(_CCV_MAT_TYPENAME(dim), MultiplyVector)
#define _CCV_FUNC_MAT_MULTIPLY_MATRIX(dim) CAT2(_CCV_MAT_TYPENAME(dim), MultiplyMatrix)
#define _CCV_FUNC_MAT_GET_ROW(dim)         CAT2(_CCV_MAT_TYPENAME(dim), GetRow)
#define _CCV_FUNC_MAT_GET_COL(dim)         CAT2(_CCV_MAT_TYPENAME(dim), GetCol)
#define _CCV_FUNC_MAT_DEMOTE(dim)          CAT2(_CCV_MAT_TYPENAME(dim), Demote)
#define _CCV_FUNC_MAT_SET_ROTATION(dim)    CAT2(_CCV_MAT_TYPENAME(dim), SetRotation)
#define _CCV_FUNC_MAT_ROTATE(dim)          CAT2(_CCV_MAT_TYPENAME(dim), Rotate)
#define _CCV_FUNC_MAT_SET_ROTATION_2D(dim) CAT2(_CCV_MAT_TYPENAME(dim), SetRotation2D)
#define _CCV_FUNC_MAT_ROTATE_2D(dim)       CAT2(_CCV_MAT_TYPENAME(dim), Rotate2D)
#define _CCV_FUNC_MAT_SET_ROTATION_X(dim)  CAT2(_CCV_MAT_TYPENAME(dim), SetRotationX)
#define _CCV_FUNC_MAT_SET_ROTATION_Y(dim)  CAT2(_CCV_MAT_TYPENAME(dim), SetRotationY)
#define _CCV_FUNC_MAT_SET_ROTATION_Z(dim)  CAT2(_CCV_MAT_TYPENAME(dim), SetRotationZ)
#define _CCV_FUNC_MAT_ROTATE_X(dim)        CAT2(_CCV_MAT_TYPENAME(dim), RotateX)
#define _CCV_FUNC_MAT_ROTATE_Y(dim)        CAT2(_CCV_MAT_TYPENAME(dim), RotateY)
#define _CCV_FUNC_MAT_ROTATE_Z(dim)        CAT2(_CCV_MAT_TYPENAME(dim), RotateZ)
#define _CCV_FUNC_MAT_SET_TRANSLATION(dim) CAT2(_CCV_MAT_TYPENAME(dim), SetTranslation)
#define _CCV_FUNC_MAT_TRANSLATE(dim)       CAT2(_CCV_MAT_TYPENAME(dim), Translate)
#define _CCV_FUNC_MAT_SET_SCALE(dim)       CAT2(_CCV_MAT_TYPENAME(dim), SetScale)
#define _CCV_FUNC_MAT_SCALE(dim)           CAT2(_CCV_MAT_TYPENAME(dim), Scale)
#define _CCV_FUNC_MAT_SET_SCALE_2D(dim)    CAT2(_CCV_MAT_TYPENAME(dim), SetScale2D)
#define _CCV_FUNC_MAT_SCALE_2D(dim)        CAT2(_CCV_MAT_TYPENAME(dim), Scale2D)
#define _CCV_FUNC_MAT_INVERSE(dim)         CAT2(_CCV_MAT_TYPENAME(dim), Inverse)
#define _CCV_FUNC_MAT_PERSPECTIVE(dim)     CAT2(_CCV_MAT_TYPENAME(dim), Perspective)
#define _CCV_FUNC_MAT_LOOK_AT(dim)         CAT2(_CCV_MAT_TYPENAME(dim), LookAt)

// Type definitions

#define _CCV_DEFINE_VEC_TYPE(dim)

#define _CCV_DEFINE_MAT_TYPE(dim) \
	typedef ccvType _CCV_MAT_TYPENAME(dim)[dim][dim];

// Vector operations

#define _CCV_DEFINE_VEC_ZERO(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_ZERO(dim)(void) { \
		_CCV_VEC_TYPENAME(dim) v; \
		memset(&v, 0, sizeof(_CCV_VEC_TYPENAME(dim))); \
		return v; \
	}

#define _CCV_DEFINE_VEC_NEGATE(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_NEGATE(dim)(const _CCV_VEC_TYPENAME(dim) v) { \
		_CCV_VEC_TYPENAME(dim) r; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			r.v[i] = -v.v[i]; \
		return r; \
	}

#define _CCV_DEFINE_VEC_ISZERO(dim) \
	static inline int _CCV_FUNC_VEC_ISZERO(dim)(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			if(v.v[i] != 0) return 0; \
		return 1; \
	}

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_ADD(dim)(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = a.v[i] + b.v[i]; \
		return v; \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_SUBTRACT(dim)(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = a.v[i] - b.v[i]; \
		return v; \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_MULTIPLY(dim)(_CCV_VEC_TYPENAME(dim) v, const ccvType n) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] *= n; \
		return v; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline ccvType _CCV_FUNC_VEC_DOTPRODUCT(dim)(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		ccvType result = 0; \
		for(i = 0; i < dim; ++i) \
			result += a.v[i] * b.v[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline ccvType _CCV_FUNC_VEC_LENGTH(dim)(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		ccvType squaredResult = 0; \
		for(i = 0; i < dim; ++i) \
			squaredResult += v.v[i] * v.v[i]; \
		return (ccvType)_CCV_SQRT(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_NORMALIZE(dim)(_CCV_VEC_TYPENAME(dim) v) { \
		return _CCV_FUNC_VEC_MULTIPLY(dim)(v, 1 / _CCV_FUNC_VEC_LENGTH(dim)(v)); \
	}

#define _CCV_DEFINE_VEC_REFLECT(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_VEC_REFLECT(dim)(const _CCV_VEC_TYPENAME(dim) n, const _CCV_VEC_TYPENAME(dim) r) { \
		return _CCV_FUNC_VEC_SUBTRACT(dim)(r, _CCV_FUNC_VEC_MULTIPLY(dim)(n, 2 * _CCV_FUNC_VEC_DOTPRODUCT(dim)(n, r))); \
	}

// Matrix operations

#define _CCV_DEFINE_MAT_ZERO(dim) \
	static inline void _CCV_FUNC_MAT_ZERO(dim)(_CCV_MAT_TYPENAME(dim) m) { \
		memset(m, 0, sizeof(ccvType)* dim * dim); \
	}

#define _CCV_DEFINE_MAT_ISZERO(dim) \
	static inline int _CCV_FUNC_MAT_ISZERO(dim)(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				if(m[row][col] != 0) return 0; \
		return 1; \
	}

#define _CCV_DEFINE_MAT_ADD(dim) \
	static inline void _CCV_FUNC_MAT_ADD(dim)(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				m[row][col] = a[row][col] + b[row][col]; \
	}

#define _CCV_DEFINE_MAT_SUBTRACT(dim) \
	static inline void _CCV_FUNC_MAT_SUBTRACT(dim)(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				m[row][col] = a[row][col] - b[row][col]; \
	}

#define _CCV_DEFINE_MAT_COPY(dim) \
	static inline void _CCV_FUNC_MAT_COPY(dim)(_CCV_MAT_TYPENAME(dim) dest, const _CCV_MAT_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(ccvType) * dim * dim); \
	}

#define _CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline void _CCV_FUNC_MAT_IDENTITY(dim)(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int i; \
		_CCV_FUNC_MAT_ZERO(dim)(m); \
		for(i = 0; i < dim; ++i) \
			m[i][i] = 1; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline void _CCV_FUNC_MAT_MULTIPLY_SCALAR(dim)(_CCV_MAT_TYPENAME(dim) m, const ccvType n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) m[row][col] *= n; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_MAT_MULTIPLY_VECTOR(dim)(const _CCV_MAT_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i, j; \
		for(i = 0; i < dim; ++i) { \
			v.v[i] = a[0][i] * b.v[0]; \
			for(j = 1; j < dim; ++j) \
				v.v[i] += a[j][i] * b.v[j]; \
		} \
		return v; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	static inline void _CCV_FUNC_MAT_MULTIPLY_MATRIX(dim)(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j, k; \
		for(j = 0; j < dim; ++j) \
			for(i = 0; i < dim; ++i) { \
				m[i][j] = a[i][0] * b[0][j]; \
				for(k = 1; k < dim; ++k) \
					m[i][j] += a[i][k] * b[k][j]; \
			} \
	}

#define _CCV_DEFINE_MAT_GET_ROW(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_MAT_GET_ROW(dim)(_CCV_MAT_TYPENAME(dim) m, const int n) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = m[i][n]; \
		return v; \
	}

#define _CCV_DEFINE_MAT_GET_COL(dim) \
	static inline _CCV_VEC_TYPENAME(dim) _CCV_FUNC_MAT_GET_COL(dim)(_CCV_MAT_TYPENAME(dim) m, const int n) { \
		_CCV_VEC_TYPENAME(dim) v; \
		memcpy(v.v, m[n], sizeof(ccvType)* dim); \
		return v; \
	}

#define _CCV_DEFINE_MAT_DEMOTE(dim) \
	static inline void _CCV_FUNC_MAT_DEMOTE(dim)(_CCV_MAT_TYPENAME(dim) m, ccvType *matrix, const int n) { \
		int i, j; \
		for(j = 0; j < dim; ++j) { \
			for(i = 0; i < dim; ++i) { \
				m[i][j] = matrix[j * n + i]; \
			} \
		} \
	}

// Definition calls

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ZERO(dim) \
	_CCV_DEFINE_VEC_NEGATE(dim) \
	_CCV_DEFINE_VEC_ISZERO(dim) \
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
	_CCV_DEFINE_MAT_ISZERO(dim) \
	_CCV_DEFINE_MAT_ADD(dim) \
	_CCV_DEFINE_MAT_SUBTRACT(dim) \
	_CCV_DEFINE_MAT_COPY(dim) \
	_CCV_DEFINE_MAT_IDENTITY(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	_CCV_DEFINE_MAT_GET_ROW(dim) \
	_CCV_DEFINE_MAT_GET_COL(dim) \
	_CCV_DEFINE_MAT_DEMOTE(dim)

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
					_CCV_VEC_TYPENAME(2) xy;
					_CCV_VEC_TYPENAME(2) _CCV_VEC_TYPENAME(2);
				};
			};
			ccvType z;
		};
		struct {
			ccvType _x;
			_CCV_VEC_TYPENAME(2) yz;
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
						_CCV_VEC_TYPENAME(2) xy;
						_CCV_VEC_TYPENAME(2) _CCV_VEC_TYPENAME(2);
					};
					union {
						struct { ccvType z, w; };
						_CCV_VEC_TYPENAME(2) zw;
					};
				};
				struct {
					ccvType _x;
					_CCV_VEC_TYPENAME(2) yz;
					ccvType _w;
				};
			};
		};
		struct {
			union {
				struct {
					union {
						_CCV_VEC_TYPENAME(3) _CCV_VEC_TYPENAME(3);
						_CCV_VEC_TYPENAME(3) xyz;
					};
					ccvType __w;
				};
				struct {
					ccvType __x;
					_CCV_VEC_TYPENAME(3) yzw;
				};
			};
		};
	};
} _CCV_VEC_TYPENAME(4);

typedef _CCV_VEC_TYPENAME(4) _CCV_QUAT_TYPENAME;

// Define 2d, 3d and 4d vectors and matrices

CCV_DEFINE_VEC(2)
CCV_DEFINE_VEC(3)
CCV_DEFINE_VEC(4)

CCV_DEFINE_MAT(2)
CCV_DEFINE_MAT(3)
CCV_DEFINE_MAT(4)

// Define n-dimensional vector type

#undef _CCV_DEFINE_VEC_TYPE
#define _CCV_DEFINE_VEC_TYPE(dim) \
	typedef struct { \
		ccvType v[dim]; \
	} _CCV_VEC_TYPENAME(dim);

// Shorthand transformation multiplier

#define _CCV_APPLY_MATRIX(dim, operation) { \
	_CCV_MAT_TYPENAME(dim) buffer, multiply; \
	operation; \
	_CCV_FUNC_MAT_COPY(dim)(buffer, m); \
	_CCV_FUNC_MAT_MULTIPLY_MATRIX(dim)(m, buffer, multiply); \
	}
	
// Define vector utilities

static inline _CCV_VEC_TYPENAME(2) _CCV_FUNC_VEC_ORTHOGONAL(2)(const _CCV_VEC_TYPENAME(2) a)
{
	_CCV_VEC_TYPENAME(2) v;

	v.x = -a.y;
	v.y = a.x;

	return v;
}

static inline _CCV_VEC_TYPENAME(3) _CCV_FUNC_VEC_CROSS_PRODUCT(3)(const _CCV_VEC_TYPENAME(3) a, const _CCV_VEC_TYPENAME(3) b)
{
	_CCV_VEC_TYPENAME(3) v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;

	return v;
}

// Define quaternion operations

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_IDENTITY()
{
	return (_CCV_QUAT_TYPENAME){ 0, 0, 0, 1 };
}

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_ROTATE(_CCV_VEC_TYPENAME(3) axis, ccvType radians)
{
	_CCV_QUAT_TYPENAME q;
	ccvType s = _CCV_SIN(radians * (ccvType)0.5);

	q.xyz = _CCV_FUNC_VEC_MULTIPLY(3)(axis, s);
	q.w = _CCV_COS(radians * (ccvType)0.5);

	return q;
}

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_MULTIPLY(const _CCV_QUAT_TYPENAME a, const _CCV_QUAT_TYPENAME b)
{
	_CCV_QUAT_TYPENAME r;
	_CCV_VEC_TYPENAME(3) w;

	r.xyz = _CCV_FUNC_VEC_CROSS_PRODUCT(3)(a.xyz, b.xyz);
	w = _CCV_FUNC_VEC_MULTIPLY(3)(a.xyz, b.w);
	r.xyz = _CCV_FUNC_VEC_ADD(3)(r.xyz, w);
	w = _CCV_FUNC_VEC_MULTIPLY(3)(b.xyz, a.w);
	r.xyz = _CCV_FUNC_VEC_ADD(3)(r.xyz, w);

	r.w = a.w * b.w - _CCV_FUNC_VEC_DOTPRODUCT(3)(a.xyz, b.xyz);

	return r;
}

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_ADD_ROTATION(_CCV_QUAT_TYPENAME q, _CCV_VEC_TYPENAME(3) axis, ccvType radians)
{
	return _CCV_FUNC_QUAT_MULTIPLY(q, _CCV_FUNC_QUAT_ROTATE(axis, radians));
}

static inline _CCV_VEC_TYPENAME(3) _CCV_FUNC_QUAT_MULTIPLY_VECTOR(const _CCV_QUAT_TYPENAME q, const _CCV_VEC_TYPENAME(3) p)
{
	_CCV_VEC_TYPENAME(3) t = _CCV_FUNC_VEC_MULTIPLY(3)(_CCV_FUNC_VEC_CROSS_PRODUCT(3)(q.xyz, p), 2);
	
	return _CCV_FUNC_VEC_ADD(3)(_CCV_FUNC_VEC_ADD(3)(p, _CCV_FUNC_VEC_MULTIPLY(3)(t, q.w)), _CCV_FUNC_VEC_CROSS_PRODUCT(3)(q.xyz, t));
}

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_ADD(const _CCV_QUAT_TYPENAME a, const _CCV_QUAT_TYPENAME b)
{
	return _CCV_FUNC_VEC_ADD(4)(a, b);
}

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_SUBTRACT(const _CCV_QUAT_TYPENAME a, const _CCV_QUAT_TYPENAME b)
{
	return _CCV_FUNC_VEC_SUBTRACT(4)(a, b);
}

static inline _CCV_QUAT_TYPENAME _CCV_FUNC_QUAT_SCALE(const _CCV_QUAT_TYPENAME q, const ccvType n)
{
	return _CCV_FUNC_VEC_MULTIPLY(4)(q, n);
}

// Define rotation methods

#define _CCV_SET_ROTATION_2D() \
	m[0][0] = (ccvType)_CCV_COS(r); \
	m[0][1] = (ccvType)_CCV_SIN(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]

static inline void _CCV_FUNC_MAT_SET_ROTATION(2)(_CCV_MAT_TYPENAME(2) m, const ccvType r)
{
	_CCV_SET_ROTATION_2D();
}

static inline void _CCV_FUNC_MAT_ROTATE(2)(_CCV_MAT_TYPENAME(2) m, const ccvType r) _CCV_APPLY_MATRIX(2, _CCV_FUNC_MAT_SET_ROTATION(2)(multiply, r));

static inline void _CCV_FUNC_MAT_SET_ROTATION_2D(2)(_CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	_CCV_FUNC_MAT_ZERO(3)(m);

	_CCV_SET_ROTATION_2D();
	m[2][2] = 1;
}

static inline void _CCV_FUNC_MAT_ROTATE_2D(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_ROTATION_2D(2)(multiply, r));

#define _CCV_SET_ROTATION_3D_X() \
	m[0][0] = 1; \
	m[0][1] = 0; \
	m[0][2] = 0; \
	m[1][0] = 0; \
	m[1][1] = (ccvType)_CCV_COS(r); \
	m[1][2] = (ccvType)_CCV_SIN(r); \
	m[2][0] = 0; \
	m[2][1] = -m[1][2]; \
	m[2][2] = m[1][1]

#define _CCV_SET_ROTATION_3D_Y() \
	m[0][0] = (ccvType)_CCV_COS(r); \
	m[0][1] = 0; \
	m[1][0] = 0; \
	m[1][1] = 1; \
	m[1][2] = 0; \
	m[2][0] = (ccvType)_CCV_SIN(r); \
	m[0][2] = -m[2][0]; \
	m[2][1] = 0; \
	m[2][2] = m[0][0]

#define _CCV_SET_ROTATION_3D_Z() \
	m[0][0] = (ccvType)_CCV_COS(r); \
	m[0][1] = (ccvType)_CCV_SIN(r); \
	m[0][2] = 0; \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]; \
	m[1][2] = 0; \
	m[2][0] = 0; \
	m[2][1] = 0; \
	m[2][2] = 1

static inline void _CCV_FUNC_MAT_SET_ROTATION_X(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_X();
}

static inline void _CCV_FUNC_MAT_SET_ROTATION_Y(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_Y();
}

static inline void _CCV_FUNC_MAT_SET_ROTATION_Z(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_Z();
}

static inline void _CCV_FUNC_MAT_ROTATE_X(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_ROTATION_X(3)(multiply, r))

static inline void _CCV_FUNC_MAT_ROTATE_Y(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_ROTATION_Y(3)(multiply, r))

static inline void _CCV_FUNC_MAT_ROTATE_Z(3)(_CCV_MAT_TYPENAME(3) m, const ccvType r) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_ROTATION_Z(3)(multiply, r))

static inline void _CCV_FUNC_MAT_SET_ROTATION_X(4)(_CCV_MAT_TYPENAME(4) m, const ccvType r)
{
	_CCV_FUNC_MAT_ZERO(4)(m);

	_CCV_SET_ROTATION_3D_X();
	m[3][3] = 1;
}

static inline void _CCV_FUNC_MAT_SET_ROTATION_Y(4)(_CCV_MAT_TYPENAME(4) m, const ccvType r)
{
	_CCV_FUNC_MAT_ZERO(4)(m);

	_CCV_SET_ROTATION_3D_Y();
	m[3][3] = 1;
}

static inline void _CCV_FUNC_MAT_SET_ROTATION_Z(4)(_CCV_MAT_TYPENAME(4) m, const ccvType r)
{
	_CCV_FUNC_MAT_ZERO(4)(m);

	_CCV_SET_ROTATION_3D_Z();
	m[3][3] = 1;
}

static inline void _CCV_FUNC_MAT_ROTATE_X(4)(_CCV_MAT_TYPENAME(4) m, const ccvType r) _CCV_APPLY_MATRIX(4, _CCV_FUNC_MAT_SET_ROTATION_X(4)(multiply, r))

static inline void _CCV_FUNC_MAT_ROTATE_Y(4)(_CCV_MAT_TYPENAME(4) m, const ccvType r) _CCV_APPLY_MATRIX(4, _CCV_FUNC_MAT_SET_ROTATION_Y(4)(multiply, r))

static inline void _CCV_FUNC_MAT_ROTATE_Z(4)(_CCV_MAT_TYPENAME(4) m, const ccvType r) _CCV_APPLY_MATRIX(4, _CCV_FUNC_MAT_SET_ROTATION_Z(4)(multiply, r))

// Define translation methods

static inline void _CCV_FUNC_MAT_SET_TRANSLATION(3)(_CCV_MAT_TYPENAME(3) m, const _CCV_VEC_TYPENAME(2) v)
{
	_CCV_FUNC_MAT_IDENTITY(3)(m);

	m[2][0] = v.x;
	m[2][1] = v.y;
}

static inline void _CCV_FUNC_MAT_TRANSLATE(3)(_CCV_MAT_TYPENAME(3) m, const _CCV_VEC_TYPENAME(2) v) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_TRANSLATION(3)(multiply, v))

static inline void _CCV_FUNC_MAT_SET_TRANSLATION(4)(_CCV_MAT_TYPENAME(4) m, const _CCV_VEC_TYPENAME(3) v)
{
	_CCV_FUNC_MAT_IDENTITY(4)(m);

	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
}

static inline void _CCV_FUNC_MAT_TRANSLATE(4)(_CCV_MAT_TYPENAME(4) m, const _CCV_VEC_TYPENAME(3) v) _CCV_APPLY_MATRIX(4, _CCV_FUNC_MAT_SET_TRANSLATION(4)(multiply, v))

// Define scaling methods

static inline void _CCV_FUNC_MAT_SET_SCALE(2)(_CCV_MAT_TYPENAME(2) m, const ccvType scale)
{
	m[0][0] = m[1][1] = scale;
	m[1][0] = m[0][1] = 0;
}

static inline void _CCV_FUNC_MAT_SCALE(2)(_CCV_MAT_TYPENAME(2) m, const ccvType scale) _CCV_APPLY_MATRIX(2, _CCV_FUNC_MAT_SET_SCALE(2)(multiply, scale))

static inline void _CCV_FUNC_MAT_SET_SCALE_2D(3)(_CCV_MAT_TYPENAME(3) m, const ccvType scale)
{
	_CCV_FUNC_MAT_ZERO(3)(m);

	m[2][2] = 1;
	m[0][0] = m[1][1] = scale;
}

static inline void _CCV_FUNC_MAT_SCALE_2D(3)(_CCV_MAT_TYPENAME(3) m, const ccvType scale) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_SCALE_2D(3)(multiply, scale))

static inline void _CCV_FUNC_MAT_SET_SCALE(3)(_CCV_MAT_TYPENAME(3) m, const ccvType scale)
{
	_CCV_FUNC_MAT_ZERO(3)(m);
	
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void _CCV_FUNC_MAT_SCALE(3)(_CCV_MAT_TYPENAME(3) m, const ccvType scale) _CCV_APPLY_MATRIX(3, _CCV_FUNC_MAT_SET_SCALE(3)(multiply, scale))

static inline void _CCV_FUNC_MAT_SET_SCALE(4)(_CCV_MAT_TYPENAME(4) m, const ccvType scale)
{
	_CCV_FUNC_MAT_ZERO(4)(m);
	
	m[3][3] = 1;
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void _CCV_FUNC_MAT_SCALE(4)(_CCV_MAT_TYPENAME(4) m, const ccvType scale) _CCV_APPLY_MATRIX(4, _CCV_FUNC_MAT_SET_SCALE(4)(multiply, scale))

// Inverse matrix

static inline void _CCV_FUNC_MAT_INVERSE(3)(_CCV_MAT_TYPENAME(3) t, _CCV_MAT_TYPENAME(3) m)
{
	ccvType s[3][3];

	s[0][0] = m[1][1] * m[2][2] - m[2][1] * m[1][2];
	s[1][0] = - m[0][1] * m[2][2] + m[2][1] * m[0][2];
	s[2][0] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
	s[0][1] = - m[1][0] * m[2][2] + m[1][2] * m[2][0];
	s[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
	s[2][1] = - m[0][0] * m[1][2] + m[0][2] * m[1][0];
	s[0][2] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	s[1][2] = - m[0][0] * m[2][1] + m[0][1] * m[2][0];
	s[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	ccvType idet = 1.0f / (m[0][0] * s[0][0] + m[1][0] * s[1][0] + m[2][0] * s[2][0]);

	t[0][0] = s[0][0] * idet;
	t[1][0] = s[0][1] * idet;
	t[2][0] = s[0][2] * idet;
	t[0][1] = s[1][0] * idet;
	t[1][1] = s[1][1] * idet;
	t[2][1] = s[1][2] * idet;
	t[0][2] = s[2][0] * idet;
	t[1][2] = s[2][1] * idet;
	t[2][2] = s[2][2] * idet;
}

static inline void _CCV_FUNC_MAT_INVERSE(4)(_CCV_MAT_TYPENAME(4) t, _CCV_MAT_TYPENAME(4) m)
{
	ccvType s[6];
	ccvType c[6];

	s[0] = m[0][0] * m[1][1] - m[1][0] * m[0][1];
	s[1] = m[0][0] * m[1][2] - m[1][0] * m[0][2];
	s[2] = m[0][0] * m[1][3] - m[1][0] * m[0][3];
	s[3] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
	s[4] = m[0][1] * m[1][3] - m[1][1] * m[0][3];
	s[5] = m[0][2] * m[1][3] - m[1][2] * m[0][3];

	c[0] = m[2][0] * m[3][1] - m[3][0] * m[2][1];
	c[1] = m[2][0] * m[3][2] - m[3][0] * m[2][2];
	c[2] = m[2][0] * m[3][3] - m[3][0] * m[2][3];
	c[3] = m[2][1] * m[3][2] - m[3][1] * m[2][2];
	c[4] = m[2][1] * m[3][3] - m[3][1] * m[2][3];
	c[5] = m[2][2] * m[3][3] - m[3][2] * m[2][3];

	ccvType idet = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

	t[0][0] = (m[1][1] * c[5] - m[1][2] * c[4] + m[1][3] * c[3])  * idet;
	t[0][1] = (-m[0][1] * c[5] + m[0][2] * c[4] - m[0][3] * c[3]) * idet;
	t[0][2] = (m[3][1] * s[5] - m[3][2] * s[4] + m[3][3] * s[3])  * idet;
	t[0][3] = (-m[2][1] * s[5] + m[2][2] * s[4] - m[2][3] * s[3]) * idet;

	t[1][0] = (-m[1][0] * c[5] + m[1][2] * c[2] - m[1][3] * c[1]) * idet;
	t[1][1] = (m[0][0] * c[5] - m[0][2] * c[2] + m[0][3] * c[1])  * idet;
	t[1][2] = (-m[3][0] * s[5] + m[3][2] * s[2] - m[3][3] * s[1]) * idet;
	t[1][3] = (m[2][0] * s[5] - m[2][2] * s[2] + m[2][3] * s[1])  * idet;

	t[2][0] = (m[1][0] * c[4] - m[1][1] * c[2] + m[1][3] * c[0])  * idet;
	t[2][1] = (-m[0][0] * c[4] + m[0][1] * c[2] - m[0][3] * c[0]) * idet;
	t[2][2] = (m[3][0] * s[4] - m[3][1] * s[2] + m[3][3] * s[0])  * idet;
	t[2][3] = (-m[2][0] * s[4] + m[2][1] * s[2] - m[2][3] * s[0]) * idet;

	t[3][0] = (-m[1][0] * c[3] + m[1][1] * c[1] - m[1][2] * c[0]) * idet;
	t[3][1] = (m[0][0] * c[3] - m[0][1] * c[1] + m[0][2] * c[0])  * idet;
	t[3][2] = (-m[3][0] * s[3] + m[3][1] * s[1] - m[3][2] * s[0]) * idet;
	t[3][3] = (m[2][0] * s[3] - m[2][1] * s[1] + m[2][2] * s[0])  * idet;
}

// Projection matrix

static inline void _CCV_FUNC_MAT_PERSPECTIVE(4)(_CCV_MAT_TYPENAME(4) m, ccvType angle, ccvType aspect, ccvType zNear, ccvType zFar)
{
	ccvType a = 1 / _CCV_TAN(angle * (ccvType)0.5);

	m[0][0] = a / aspect;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;

	m[1][0] = 0;
	m[1][1] = a;
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = -((zFar + zNear) / (zFar - zNear));
	m[2][3] = -1;

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = -((2 * zFar * zNear) / (zFar - zNear));
	m[3][3] = 0;
}

// Modelview matrix

static inline void _CCV_FUNC_MAT_LOOK_AT(4)(_CCV_MAT_TYPENAME(4) m, _CCV_VEC_TYPENAME(3) from, _CCV_VEC_TYPENAME(3) to, _CCV_VEC_TYPENAME(3) up)
{
	unsigned int i;
	_CCV_VEC_TYPENAME(3) f = _CCV_FUNC_VEC_NORMALIZE(3)(_CCV_FUNC_VEC_SUBTRACT(3)(to, from));
	_CCV_VEC_TYPENAME(3) s = _CCV_FUNC_VEC_NORMALIZE(3)(_CCV_FUNC_VEC_CROSS_PRODUCT(3)(f, up));
	_CCV_VEC_TYPENAME(3) t = _CCV_FUNC_VEC_CROSS_PRODUCT(3)(s, f);

	m[0][0] = s.x;
	m[0][1] = t.x;
	m[0][2] = -f.x;
	m[0][3] = 0;

	m[1][0] = s.y;
	m[1][1] = t.y;
	m[1][2] = -f.y;
	m[1][3] = 0;

	m[2][0] = s.z;
	m[2][1] = t.z;
	m[2][2] = -f.z;
	m[2][3] = 0;

	for(i = 0; i < 3; ++i) {
		_CCV_VEC_TYPENAME(3) r = _CCV_FUNC_MAT_GET_ROW(4)(m, i)._CCV_VEC_TYPENAME(3);
		m[3][i] = -_CCV_FUNC_VEC_DOTPRODUCT(3)(r, from);
	}

	m[3][3] = 1;
}

#ifdef __cplusplus
}
#endif
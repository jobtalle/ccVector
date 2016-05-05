//__________________________________________________________________________________//
//                           __      __       _                                     //
//                           \ \    / /      | |                                    //
//                      ___ __\ \  / /__  ___| |_ ___  _ __                         //
//                     / __/ __\ \/ / _ \/ __| __/ _ \| '__|                        //
//                    | (_| (__ \  /  __/ (__| || (_) | |                           //
//                     \___\___| \/ \___|\___|\__\___/|_| v1.1                      //
//                                                                                  //
//            Copyright (C) 2015 - 2016 \ Job Talle (jobtalle@hotmail.com)          //
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

// Concatenation utilities

#define _CAT2(a, b) a##b
#define CAT2(a, b) _CAT2(a, b)

// Type

typedef float ccvType;

// Math functions

#define _CCV_COS  cosf
#define _CCV_SIN  sinf
#define _CCV_TAN  tanf
#define _CCV_SQRT sqrtf

// Prefixes

#define _CCV_VEC_TYPENAME(dim) vec##dim

#define _CCV_MAT_TYPENAME(dim) mat##dim##x##dim

// Type definitions

#define _CCV_DEFINE_VEC_TYPE(dim)

#define _CCV_DEFINE_MAT_TYPE(dim) \
	typedef ccvType _CCV_MAT_TYPENAME(dim)[dim][dim];

// Vector operations

#define _CCV_DEFINE_VEC_ZERO(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Zero)(void) { \
		_CCV_VEC_TYPENAME(dim) v; \
		memset(&v, 0, sizeof(_CCV_VEC_TYPENAME(dim))); \
		return v; \
	}

#define _CCV_DEFINE_VEC_NEGATE(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Negate)(const _CCV_VEC_TYPENAME(dim) v) { \
		_CCV_VEC_TYPENAME(dim) r; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			r.v[i] = -v.v[i]; \
		return r; \
	}

#define _CCV_DEFINE_VEC_ISZERO(dim) \
	static inline int CAT2(_CCV_VEC_TYPENAME(dim), IsZero)(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			if(v.v[i] != 0) return 0; \
		return 1; \
	}

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Add)(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = a.v[i] + b.v[i]; \
		return v; \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Subtract)(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = a.v[i] - b.v[i]; \
		return v; \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Multiply)(_CCV_VEC_TYPENAME(dim) v, const ccvType n) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] *= n; \
		return v; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline ccvType CAT2(_CCV_VEC_TYPENAME(dim), DotProduct)(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		ccvType result = 0; \
		for(i = 0; i < dim; ++i) \
			result += a.v[i] * b.v[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline ccvType CAT2(_CCV_VEC_TYPENAME(dim), Length)(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		ccvType squaredResult = 0; \
		for(i = 0; i < dim; ++i) \
			squaredResult += v.v[i] * v.v[i]; \
		return (ccvType)_CCV_SQRT(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Normalize)(_CCV_VEC_TYPENAME(dim) v) { \
		return CAT2(_CCV_VEC_TYPENAME(dim), Multiply)(v, 1 / CAT2(_CCV_VEC_TYPENAME(dim), Length(v))); \
	}

#define _CCV_DEFINE_VEC_REFLECT(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_VEC_TYPENAME(dim), Reflect)(const _CCV_VEC_TYPENAME(dim) n, const _CCV_VEC_TYPENAME(dim) r) { \
		return CAT2(_CCV_VEC_TYPENAME(dim), Subtract)(r, CAT2(_CCV_VEC_TYPENAME(dim), Multiply)(n, 2 * CAT2(_CCV_VEC_TYPENAME(dim), DotProduct)(n, r))); \
	}

// Matrix operations

#define _CCV_DEFINE_MAT_ZERO(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), Zero)(_CCV_MAT_TYPENAME(dim) m) { \
		memset(m, 0, sizeof(ccvType)* dim * dim); \
	}

#define _CCV_DEFINE_MAT_ISZERO(dim) \
	static inline int CAT2(_CCV_MAT_TYPENAME(dim), IsZero)(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				if(m[row][col] != 0) return 0; \
		return 1; \
	}

#define _CCV_DEFINE_MAT_ADD(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), Add)(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				m[row][col] = a[row][col] + b[row][col]; \
	}

#define _CCV_DEFINE_MAT_SUBTRACT(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), Subtract)(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				m[row][col] = a[row][col] - b[row][col]; \
	}

#define _CCV_DEFINE_MAT_COPY(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), Copy)(_CCV_MAT_TYPENAME(dim) dest, const _CCV_MAT_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(ccvType) * dim * dim); \
	}

#define _CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), Identity)(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int i; \
		CAT2(_CCV_MAT_TYPENAME(dim), Zero)(m); \
		for(i = 0; i < dim; ++i) \
			m[i][i] = 1; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), MultiplyScalar)(_CCV_MAT_TYPENAME(dim) m, const ccvType n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) m[row][col] *= n; \
	}

#define _CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_MAT_TYPENAME(dim), MultiplyVector)(const _CCV_MAT_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
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
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), MultiplyMatrix)(_CCV_MAT_TYPENAME(dim) m, const _CCV_MAT_TYPENAME(dim) a, const _CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j, k; \
		for(j = 0; j < dim; ++j) \
			for(i = 0; i < dim; ++i) { \
				m[i][j] = a[i][0] * b[0][j]; \
				for(k = 1; k < dim; ++k) \
					m[i][j] += a[i][k] * b[k][j]; \
			} \
	}

#define _CCV_DEFINE_MAT_GET_ROW(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_MAT_TYPENAME(dim), GetRow)(_CCV_MAT_TYPENAME(dim) m, const int n) { \
		_CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = m[i][n]; \
		return v; \
	}

#define _CCV_DEFINE_MAT_GET_COL(dim) \
	static inline _CCV_VEC_TYPENAME(dim) CAT2(_CCV_MAT_TYPENAME(dim), GetCol)(_CCV_MAT_TYPENAME(dim) m, const int n) { \
		_CCV_VEC_TYPENAME(dim) v; \
		memcpy(v.v, m[n], sizeof(ccvType)* dim); \
		return v; \
	}

#define _CCV_DEFINE_MAT_DEMOTE(dim) \
	static inline void CAT2(_CCV_MAT_TYPENAME(dim), Demote)(_CCV_MAT_TYPENAME(dim) m, ccvType *matrix, const int n) { \
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
					vec2 xy;
					vec2 vec2;
				};
			};
			ccvType z;
		};
		struct {
			ccvType _x;
			vec2 yz;
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
						vec2 xy;
						vec2 vec2;
					};
					union {
						struct { ccvType z, w; };
						vec2 zw;
					};
				};
				struct {
					ccvType _x;
					vec2 yz;
					ccvType _w;
				};
			};
		};
		struct {
			union {
				vec3 vec3;
				vec3 xyz;
			};
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
	operation; \
	CAT2(type, Copy)(buffer, m); \
	CAT2(type, MultiplyMatrix)(m, buffer, multiply); \
	}
	
// Define vector utilities

static inline vec2 vec2Orthogonal(const vec2 a)
{
	vec2 v;

	v.x = -a.y;
	v.y = a.x;

	return v;
}

static inline vec3 vec3CrossProduct(const vec3 a, const vec3 b)
{
	vec3 v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;

	return v;
}

// Define quaternion operations

static inline vec4 ccQuatIdentity()
{
	return (vec4){ 0, 0, 0, 1 };
}

static inline vec4 ccQuatRotate(vec3 axis, ccvType radians)
{
	vec4 q;
	float s = _CCV_SIN(radians * (ccvType)0.5);

	q.xyz = vec3Multiply(axis, s);
	q.w = _CCV_COS(radians * (ccvType)0.5);

	return q;
}

static inline vec4 ccQuatMultiply(const vec4 a, const vec4 b)
{
	vec4 r;
	vec3 w;

	r.xyz = vec3CrossProduct(a.xyz, b.xyz);
	w = vec3Multiply(a.xyz, b.w);
	r.xyz = vec3Add(r.xyz, w);
	w = vec3Multiply(b.xyz, a.w);
	r.xyz = vec3Add(r.xyz, w);

	r.w = a.w * b.w - vec3DotProduct(a.xyz, b.xyz);

	return r;
}

static inline vec4 ccQuatAddRotation(vec4 q, vec3 axis, ccvType radians)
{
	return ccQuatMultiply(q, ccQuatRotate(axis, radians));
}

static inline vec3 ccQuatMultiplyVector(const vec4 q, const vec3 p)
{
	vec3 t = vec3Multiply(vec3CrossProduct(q.xyz, p), 2);
	
	return vec3Add(vec3Add(p, vec3Multiply(t, q.w)), vec3CrossProduct(q.xyz, t));
}

#define ccQuatAdd(a, b) vec4Add(a, b)
#define ccQuadSubtract(a, b) vec4Subtract(a, b)
#define ccQuatScale(q, s) vec4Multiply(q, s)

// Define rotation methods

#define _CCV_SET_ROTATION_2D() \
	m[0][0] = (ccvType)_CCV_COS(r); \
	m[0][1] = (ccvType)_CCV_SIN(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]

static inline void mat2x2SetRotation(mat2x2 m, const ccvType r)
{
	_CCV_SET_ROTATION_2D();
}

static inline void mat2x2Rotate(mat2x2 m, const ccvType r) _CCV_APPLY_MATRIX(mat2x2, mat2x2SetRotation(multiply, r));

static inline void mat3x3SetRotation2D(mat3x3 m, const ccvType r)
{
	mat3x3Zero(m);

	_CCV_SET_ROTATION_2D();
	m[2][2] = 1;
}

static inline void mat3x3Rotate2D(mat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetRotation2D(multiply, r));

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

static inline void mat3x3SetRotationX(mat3x3 m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_X();
}

static inline void mat3x3SetRotationY(mat3x3 m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_Y();
}

static inline void mat3x3SetRotationZ(mat3x3 m, const ccvType r)
{
	_CCV_SET_ROTATION_3D_Z();
}

static inline void mat3x3RotateX(mat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetRotationX(multiply, r))

static inline void mat3x3RotateY(mat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetRotationY(multiply, r))

static inline void mat3x3RotateZ(mat3x3 m, const ccvType r) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetRotationZ(multiply, r))

static inline void mat4x4SetRotationX(mat4x4 m, const ccvType r)
{
	mat4x4Zero(m);

	_CCV_SET_ROTATION_3D_X();
	m[3][3] = 1;
}

static inline void mat4x4SetRotationY(mat4x4 m, const ccvType r)
{
	mat4x4Zero(m);

	_CCV_SET_ROTATION_3D_Y();
	m[3][3] = 1;
}

static inline void mat4x4SetRotationZ(mat4x4 m, const ccvType r)
{
	mat4x4Zero(m);

	_CCV_SET_ROTATION_3D_Z();
	m[3][3] = 1;
}

static inline void mat4x4RotateX(mat4x4 m, const ccvType r) _CCV_APPLY_MATRIX(mat4x4, mat4x4SetRotationX(multiply, r))

static inline void mat4x4RotateY(mat4x4 m, const ccvType r) _CCV_APPLY_MATRIX(mat4x4, mat4x4SetRotationY(multiply, r))

static inline void mat4x4RotateZ(mat4x4 m, const ccvType r) _CCV_APPLY_MATRIX(mat4x4, mat4x4SetRotationZ(multiply, r))

// Define translation methods

static inline void mat3x3SetTranslation(mat3x3 m, const vec2 v)
{
	mat3x3Identity(m);

	m[2][0] = v.x;
	m[2][1] = v.y;
}

static inline void mat3x3Translate(mat3x3 m, const vec2 v) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetTranslation(multiply, v))

static inline void mat4x4SetTranslation(mat4x4 m, const vec3 v)
{
	mat4x4Identity(m);

	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
}

static inline void mat4x4Translate(mat4x4 m, const vec3 v) _CCV_APPLY_MATRIX(mat4x4, mat4x4SetTranslation(multiply, v))

// Define scaling methods

static inline void mat2x2SetScale(mat2x2 m, const ccvType scale)
{
	m[0][0] = m[1][1] = scale;
	m[1][0] = m[0][1] = 0;
}

static inline void mat2x2Scale(mat2x2 m, const ccvType scale) _CCV_APPLY_MATRIX(mat2x2, mat2x2SetScale(multiply, scale))

static inline void mat3x3SetScale2D(mat3x3 m, const ccvType scale)
{
	mat3x3Zero(m);

	m[2][2] = 1;
	m[0][0] = m[1][1] = scale;
}

static inline void mat3x3Scale2D(mat3x3 m, const ccvType scale) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetScale2D(multiply, scale))

static inline void mat3x3SetScale(mat3x3 m, const ccvType scale)
{
	mat3x3Zero(m);
	
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void mat3x3Scale(mat3x3 m, const ccvType scale) _CCV_APPLY_MATRIX(mat3x3, mat3x3SetScale(multiply, scale))

static inline void mat4x4SetScale(mat4x4 m, const ccvType scale)
{
	mat4x4Zero(m);
	
	m[3][3] = 1;
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void mat4x4Scale(mat4x4 m, const ccvType scale) _CCV_APPLY_MATRIX(mat4x4, mat4x4SetScale(multiply, scale))

// Inverse matrix

static inline void mat3x3Inverse(mat3x3 t, mat3x3 m)
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

static inline void mat4x4Inverse(mat4x4 t, mat4x4 m)
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

static inline void mat4x4Perspective(mat4x4 m, ccvType angle, ccvType aspect, ccvType zNear, ccvType zFar)
{
	ccvType a = 1.0f / _CCV_TAN(angle * .5f);

	m[0][0] = a / aspect;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = a;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = -((zFar + zNear) / (zFar - zNear));
	m[2][3] = -1.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = -((2.0f * zFar * zNear) / (zFar - zNear));
	m[3][3] = 0.0f;
}

// Modelview matrix

static inline void mat4x4LookAt(mat4x4 m, vec3 from, vec3 to, vec3 up)
{
	unsigned int i;
	vec3 f = vec3Normalize(vec3Subtract(to, from));
	vec3 s = vec3Normalize(vec3CrossProduct(f, up));
	vec3 t = vec3CrossProduct(s, f);

	m[0][0] = s.x;
	m[0][1] = t.x;
	m[0][2] = -f.x;
	m[0][3] = 0.0f;

	m[1][0] = s.y;
	m[1][1] = t.y;
	m[1][2] = -f.y;
	m[1][3] = 0.0f;

	m[2][0] = s.z;
	m[2][1] = t.z;
	m[2][2] = -f.z;
	m[2][3] = 0.0f;

	for(i = 0; i < 3; ++i) {
		vec3 r = mat4x4GetRow(m, i).vec3;
		m[3][i] = -vec3DotProduct(r, from);
	}

	m[3][3] = 1.0f;
}

#ifdef __cplusplus
}
#endif
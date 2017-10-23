//__________________________________________________________________________________//
//                           __      __       _                                     //
//                           \ \    / /      | |                                    //
//                      ___ __\ \  / /__  ___| |_ ___  _ __                         //
//                     / __/ __\ \/ / _ \/ __| __/ _ \| '__|                        //
//                    | (_| (__ \  /  __/ (__| || (_) | |                           //
//                     \___\___| \/ \___|\___|\__\___/|_| v1.1                      //
//                                                                                  //
//                  2015 - 2017 \ Job Talle (jobtalle@hotmail.com)                  //
//__________________________________________________________________________________//
//                                                                                  //
//               ccVector has been dedicated to the public domain.                  //
//                                                                                  //
// Anyone is free to copy, modify, publish, use, compile, sell, or distribute this  //
// software, either in source code form or as a compiled binary, for any purpose,   //
//               commercial or non - commercial, and by any means.                  //
//__________________________________________________________________________________//

#ifndef CC_VECTOR
#define CC_VECTOR

#ifdef __cplusplus
extern "C"
{
#endif

#include <math.h>
#include <string.h>

#ifdef _DEBUG
#include <assert.h>
#endif

#ifndef inline
#ifdef _MSC_VER
#define inline __inline
#endif
#endif

// Concatenation utility

#define CAT2_(a, b) a##b
#define CAT2(a, b) CAT2_(a, b)

// Number type

typedef float ccvType;

// Used math functions

#define CCV_COS     cosf
#define CCV_SIN     sinf
#define CCV_TAN     tanf
#define CCV_ACOS    acosf
#define CCV_SQRT    sqrtf
#define CCV_ABS     fabsf
#define CCV_EPSILON ((ccvType)0.0001)

// Type names

#define CCV_VEC_TYPENAME(dim) vec##dim
#define CCV_QUAT_TYPENAME     quat
#define CCV_MAT_TYPENAME(dim) mat##dim##x##dim

// Function names

#define CCV_FUNC_VEC_ZERO(dim)            CAT2(CCV_VEC_TYPENAME(dim), Zero)
#define CCV_FUNC_VEC_NEGATE(dim)          CAT2(CCV_VEC_TYPENAME(dim), Negate)
#define CCV_FUNC_VEC_ISZERO(dim)          CAT2(CCV_VEC_TYPENAME(dim), IsZero)
#define CCV_FUNC_VEC_ADD(dim)             CAT2(CCV_VEC_TYPENAME(dim), Add)
#define CCV_FUNC_VEC_SUBTRACT(dim)        CAT2(CCV_VEC_TYPENAME(dim), Subtract)
#define CCV_FUNC_VEC_MULTIPLY(dim)        CAT2(CCV_VEC_TYPENAME(dim), Multiply)
#define CCV_FUNC_VEC_DOTPRODUCT(dim)      CAT2(CCV_VEC_TYPENAME(dim), DotProduct)
#define CCV_FUNC_VEC_LENGTH(dim)          CAT2(CCV_VEC_TYPENAME(dim), Length)
#define CCV_FUNC_VEC_NORMALIZE(dim)       CAT2(CCV_VEC_TYPENAME(dim), Normalize)
#define CCV_FUNC_VEC_REFLECT(dim)         CAT2(CCV_VEC_TYPENAME(dim), Reflect)
#define CCV_FUNC_VEC_ORTHOGONAL(dim)      CAT2(CCV_VEC_TYPENAME(dim), Orthogonal)
#define CCV_FUNC_VEC_CROSS_PRODUCT(dim)   CAT2(CCV_VEC_TYPENAME(dim), CrossProduct)
#define CCV_FUNC_VEC_MIX(dim)             CAT2(CCV_VEC_TYPENAME(dim), Mix)
#define CCV_FUNC_VEC_NEW(dim)             CAT2(CCV_VEC_TYPENAME(dim), New)
#define CCV_FUNC_VEC_EQUAL(dim)           CAT2(CCV_VEC_TYPENAME(dim), Equal)

#define CCV_FUNC_QUAT_IDENTITY            CAT2(CCV_QUAT_TYPENAME, Identity)
#define CCV_FUNC_QUAT_ROTATE              CAT2(CCV_QUAT_TYPENAME, Rotate)
#define CCV_FUNC_QUAT_MULTIPLY            CAT2(CCV_QUAT_TYPENAME, Multiply)
#define CCV_FUNC_QUAT_ADD_ROTATION        CAT2(CCV_QUAT_TYPENAME, AddRotation)
#define CCV_FUNC_QUAT_MULTIPLY_VECTOR     CAT2(CCV_QUAT_TYPENAME, MultiplyVector)
#define CCV_FUNC_QUAT_ADD                 CAT2(CCV_QUAT_TYPENAME, Add)
#define CCV_FUNC_QUAT_SUBTRACT            CAT2(CCV_QUAT_TYPENAME, Subtract)
#define CCV_FUNC_QUAT_SCALE               CAT2(CCV_QUAT_TYPENAME, Scale)
#define CCV_FUNC_QUAT_MIX                 CAT2(CCV_QUAT_TYPENAME, Mix)

#define CCV_FUNC_MAT_ZERO(dim)            CAT2(CCV_MAT_TYPENAME(dim), Zero)
#define CCV_FUNC_MAT_ISZERO(dim)          CAT2(CCV_MAT_TYPENAME(dim), IsZero)
#define CCV_FUNC_MAT_ADD(dim)             CAT2(CCV_MAT_TYPENAME(dim), Add)
#define CCV_FUNC_MAT_SUBTRACT(dim)        CAT2(CCV_MAT_TYPENAME(dim), Subtract)
#define CCV_FUNC_MAT_COPY(dim)            CAT2(CCV_MAT_TYPENAME(dim), Copy)
#define CCV_FUNC_MAT_IDENTITY(dim)        CAT2(CCV_MAT_TYPENAME(dim), Identity)
#define CCV_FUNC_MAT_MULTIPLY_SCALAR(dim) CAT2(CCV_MAT_TYPENAME(dim), MultiplyScalar)
#define CCV_FUNC_MAT_MULTIPLY_VECTOR(dim) CAT2(CCV_MAT_TYPENAME(dim), MultiplyVector)
#define CCV_FUNC_MAT_MULTIPLY_MATRIX(dim) CAT2(CCV_MAT_TYPENAME(dim), MultiplyMatrix)
#define CCV_FUNC_MAT_GET_ROW(dim)         CAT2(CCV_MAT_TYPENAME(dim), GetRow)
#define CCV_FUNC_MAT_GET_COL(dim)         CAT2(CCV_MAT_TYPENAME(dim), GetCol)
#define CCV_FUNC_MAT_DEMOTE(dim)          CAT2(CCV_MAT_TYPENAME(dim), Demote)
#define CCV_FUNC_MAT_TRANSPOSE(dim)       CAT2(CCV_MAT_TYPENAME(dim), Transpose)
#define CCV_FUNC_MAT_SET_ROTATION(dim)    CAT2(CCV_MAT_TYPENAME(dim), SetRotation)
#define CCV_FUNC_MAT_ROTATE(dim)          CAT2(CCV_MAT_TYPENAME(dim), Rotate)
#define CCV_FUNC_MAT_SET_ROTATION_2D(dim) CAT2(CCV_MAT_TYPENAME(dim), SetRotation2D)
#define CCV_FUNC_MAT_ROTATE_2D(dim)       CAT2(CCV_MAT_TYPENAME(dim), Rotate2D)
#define CCV_FUNC_MAT_SET_ROTATION_X(dim)  CAT2(CCV_MAT_TYPENAME(dim), SetRotationX)
#define CCV_FUNC_MAT_SET_ROTATION_Y(dim)  CAT2(CCV_MAT_TYPENAME(dim), SetRotationY)
#define CCV_FUNC_MAT_SET_ROTATION_Z(dim)  CAT2(CCV_MAT_TYPENAME(dim), SetRotationZ)
#define CCV_FUNC_MAT_ROTATE_X(dim)        CAT2(CCV_MAT_TYPENAME(dim), RotateX)
#define CCV_FUNC_MAT_ROTATE_Y(dim)        CAT2(CCV_MAT_TYPENAME(dim), RotateY)
#define CCV_FUNC_MAT_ROTATE_Z(dim)        CAT2(CCV_MAT_TYPENAME(dim), RotateZ)
#define CCV_FUNC_MAT_SET_TRANSLATION(dim) CAT2(CCV_MAT_TYPENAME(dim), SetTranslation)
#define CCV_FUNC_MAT_TRANSLATE(dim)       CAT2(CCV_MAT_TYPENAME(dim), Translate)
#define CCV_FUNC_MAT_SET_SCALE(dim)       CAT2(CCV_MAT_TYPENAME(dim), SetScale)
#define CCV_FUNC_MAT_SCALE(dim)           CAT2(CCV_MAT_TYPENAME(dim), Scale)
#define CCV_FUNC_MAT_SET_SCALE_2D(dim)    CAT2(CCV_MAT_TYPENAME(dim), SetScale2D)
#define CCV_FUNC_MAT_SCALE_2D(dim)        CAT2(CCV_MAT_TYPENAME(dim), Scale2D)
#define CCV_FUNC_MAT_INVERSE(dim)         CAT2(CCV_MAT_TYPENAME(dim), Inverse)
#define CCV_FUNC_MAT_PERSPECTIVE(dim)     CAT2(CCV_MAT_TYPENAME(dim), Perspective)
#define CCV_FUNC_MAT_LOOK_AT(dim)         CAT2(CCV_MAT_TYPENAME(dim), LookAt)
#define CCV_FUNC_MAT_EQUAL(dim)           CAT2(CCV_MAT_TYPENAME(dim), Equal)

// Type definitions

#define CCV_DEFINE_VEC_TYPE(dim)

#define CCV_DEFINE_MAT_TYPE(dim) \
	typedef ccvType CCV_MAT_TYPENAME(dim)[dim][dim];

// Vector operations

#define CCV_DEFINE_VEC_ZERO(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_ZERO(dim)(void) { \
		CCV_VEC_TYPENAME(dim) v; \
		memset(&v, 0, sizeof(CCV_VEC_TYPENAME(dim))); \
		return v; \
	}

#define CCV_DEFINE_VEC_NEGATE(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_NEGATE(dim)(const CCV_VEC_TYPENAME(dim) v) { \
		CCV_VEC_TYPENAME(dim) r; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			r.v[i] = -v.v[i]; \
		return r; \
	}

#define CCV_DEFINE_VEC_ISZERO(dim) \
	static inline int CCV_FUNC_VEC_ISZERO(dim)(const CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			if(v.v[i] != 0) return 0; \
		return 1; \
	}

#define CCV_DEFINE_VEC_ADD(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_ADD(dim)(const CCV_VEC_TYPENAME(dim) a, const CCV_VEC_TYPENAME(dim) b) { \
		CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = a.v[i] + b.v[i]; \
		return v; \
	}

#define CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_SUBTRACT(dim)(const CCV_VEC_TYPENAME(dim) a, const CCV_VEC_TYPENAME(dim) b) { \
		CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = a.v[i] - b.v[i]; \
		return v; \
	}

#define CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_MULTIPLY(dim)(CCV_VEC_TYPENAME(dim) v, const ccvType n) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] *= n; \
		return v; \
	}

#define CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline ccvType CCV_FUNC_VEC_DOTPRODUCT(dim)(const CCV_VEC_TYPENAME(dim) a, const CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		ccvType result = 0; \
		for(i = 0; i < dim; ++i) \
			result += a.v[i] * b.v[i]; \
		return result; \
	}

#define CCV_DEFINE_VEC_LENGTH(dim) \
	static inline ccvType CCV_FUNC_VEC_LENGTH(dim)(const CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		ccvType squaredResult = 0; \
		for(i = 0; i < dim; ++i) \
			squaredResult += v.v[i] * v.v[i]; \
		return (ccvType)CCV_SQRT(squaredResult); \
	}

#define CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_NORMALIZE(dim)(CCV_VEC_TYPENAME(dim) v) { \
		return CCV_FUNC_VEC_MULTIPLY(dim)(v, 1 / CCV_FUNC_VEC_LENGTH(dim)(v)); \
	}

#define CCV_DEFINE_VEC_REFLECT(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_REFLECT(dim)(const CCV_VEC_TYPENAME(dim) n, const CCV_VEC_TYPENAME(dim) r) { \
		return CCV_FUNC_VEC_SUBTRACT(dim)(r, CCV_FUNC_VEC_MULTIPLY(dim)(n, 2 * CCV_FUNC_VEC_DOTPRODUCT(dim)(n, r))); \
	}

#define CCV_DEFINE_VEC_MIX(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_VEC_MIX(dim)(const CCV_VEC_TYPENAME(dim) a, const CCV_VEC_TYPENAME(dim) b, const ccvType f) { \
		return CCV_FUNC_VEC_ADD(dim)(a, CCV_FUNC_VEC_MULTIPLY(dim)(CCV_FUNC_VEC_SUBTRACT(dim)(b, a), f)); \
	}

#define CCV_DEFINE_VEC_EQUAL(dim) \
	static inline int CCV_FUNC_VEC_EQUAL(dim)(const CCV_VEC_TYPENAME(dim) a, const CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			if(a.v[i] != b.v[i]) \
				return 0; \
		return 1; \
	}

// Matrix operations

#define CCV_DEFINE_MAT_ZERO(dim) \
	static inline void CCV_FUNC_MAT_ZERO(dim)(CCV_MAT_TYPENAME(dim) m) { \
		memset(m, 0, sizeof(ccvType)* dim * dim); \
	}

#define CCV_DEFINE_MAT_ISZERO(dim) \
	static inline int CCV_FUNC_MAT_ISZERO(dim)(CCV_MAT_TYPENAME(dim) m) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				if(m[row][col] != 0) return 0; \
		return 1; \
	}

#define CCV_DEFINE_MAT_ADD(dim) \
	static inline void CCV_FUNC_MAT_ADD(dim)(CCV_MAT_TYPENAME(dim) m, const CCV_MAT_TYPENAME(dim) a, const CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				m[row][col] = a[row][col] + b[row][col]; \
	}

#define CCV_DEFINE_MAT_SUBTRACT(dim) \
	static inline void CCV_FUNC_MAT_SUBTRACT(dim)(CCV_MAT_TYPENAME(dim) m, const CCV_MAT_TYPENAME(dim) a, const CCV_MAT_TYPENAME(dim) b) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) \
				m[row][col] = a[row][col] - b[row][col]; \
	}

#define CCV_DEFINE_MAT_COPY(dim) \
	static inline void CCV_FUNC_MAT_COPY(dim)(CCV_MAT_TYPENAME(dim) dest, const CCV_MAT_TYPENAME(dim) source) { \
		memcpy(dest, source, sizeof(ccvType) * dim * dim); \
	}

#define CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline void CCV_FUNC_MAT_IDENTITY(dim)(CCV_MAT_TYPENAME(dim) m) { \
		unsigned int i; \
		CCV_FUNC_MAT_ZERO(dim)(m); \
		for(i = 0; i < dim; ++i) \
			m[i][i] = 1; \
	}

#define CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline void CCV_FUNC_MAT_MULTIPLY_SCALAR(dim)(CCV_MAT_TYPENAME(dim) m, const ccvType n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; ++col) \
			for(row = 0; row < dim; ++row) m[row][col] *= n; \
	}

#define CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_MAT_MULTIPLY_VECTOR(dim)(const CCV_MAT_TYPENAME(dim) a, const CCV_VEC_TYPENAME(dim) b) { \
		CCV_VEC_TYPENAME(dim) v; \
		unsigned int i, j; \
		for(i = 0; i < dim; ++i) { \
			v.v[i] = a[0][i] * b.v[0]; \
			for(j = 1; j < dim; ++j) \
				v.v[i] += a[j][i] * b.v[j]; \
		} \
		return v; \
	}

#define CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	static inline void CCV_FUNC_MAT_MULTIPLY_MATRIX(dim)(CCV_MAT_TYPENAME(dim) m, const CCV_MAT_TYPENAME(dim) a, const CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j, k; \
		for(j = 0; j < dim; ++j) \
			for(i = 0; i < dim; ++i) { \
				m[i][j] = a[i][0] * b[0][j]; \
				for(k = 1; k < dim; ++k) \
					m[i][j] += a[i][k] * b[k][j]; \
			} \
	}

#define CCV_DEFINE_MAT_GET_ROW(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_MAT_GET_ROW(dim)(CCV_MAT_TYPENAME(dim) m, const unsigned int n) { \
		CCV_VEC_TYPENAME(dim) v; \
		unsigned int i; \
		for(i = 0; i < dim; ++i) \
			v.v[i] = m[i][n]; \
		return v; \
	}

#define CCV_DEFINE_MAT_GET_COL(dim) \
	static inline CCV_VEC_TYPENAME(dim) CCV_FUNC_MAT_GET_COL(dim)(CCV_MAT_TYPENAME(dim) m, const unsigned int n) { \
		CCV_VEC_TYPENAME(dim) v; \
		memcpy(v.v, m[n], sizeof(ccvType)* dim); \
		return v; \
	}

#define CCV_DEFINE_MAT_TRANSPOSE(dim) \
	static inline void CCV_FUNC_MAT_TRANSPOSE(dim)(CCV_MAT_TYPENAME(dim) m, CCV_MAT_TYPENAME(dim) n) { \
		unsigned int i, j; \
		for(j = 0; j < dim; ++j) \
			for(i = 0; i < dim; ++i) \
				m[i][j] = n[j][i]; \
	}

#define CCV_DEFINE_MAT_EQUAL(dim) \
	static inline int CCV_FUNC_MAT_EQUAL(dim)(CCV_MAT_TYPENAME(dim) a, CCV_MAT_TYPENAME(dim) b) { \
		unsigned int i, j; \
		for(j = 0; j < dim; ++j) \
			for(i = 0; i < dim; ++i) \
				if(a[i][j] != b[i][j]) \
					return 0; \
		return 1; \
	}

#define CCV_DEFINE_MAT_DEMOTE(dimTarget, dimSource) \
	static inline void CCV_FUNC_MAT_DEMOTE(dimSource)(CCV_MAT_TYPENAME(dimTarget) m, CCV_MAT_TYPENAME(dimSource) n) { \
		unsigned int i, j; \
		for(j = 0; j < dimTarget; ++j) \
			for(i = 0; i < dimTarget; ++i) \
				m[i][j] = n[i][j]; \
	}

// Definition calls

#define CCV_DEFINE_VEC(dim) \
	CCV_DEFINE_VEC_TYPE(dim) \
	CCV_DEFINE_VEC_ZERO(dim) \
	CCV_DEFINE_VEC_NEGATE(dim) \
	CCV_DEFINE_VEC_ISZERO(dim) \
	CCV_DEFINE_VEC_ADD(dim) \
	CCV_DEFINE_VEC_SUBTRACT(dim) \
	CCV_DEFINE_VEC_MULTIPLY(dim) \
	CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	CCV_DEFINE_VEC_LENGTH(dim) \
	CCV_DEFINE_VEC_NORMALIZE(dim) \
	CCV_DEFINE_VEC_REFLECT(dim) \
	CCV_DEFINE_VEC_MIX(dim) \
	CCV_DEFINE_VEC_EQUAL(dim)

#define CCV_DEFINE_MAT(dim) \
	CCV_DEFINE_VEC_TYPE(dim) \
	CCV_DEFINE_MAT_TYPE(dim) \
	CCV_DEFINE_MAT_ZERO(dim) \
	CCV_DEFINE_MAT_ISZERO(dim) \
	CCV_DEFINE_MAT_ADD(dim) \
	CCV_DEFINE_MAT_SUBTRACT(dim) \
	CCV_DEFINE_MAT_COPY(dim) \
	CCV_DEFINE_MAT_IDENTITY(dim) \
	CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	CCV_DEFINE_MAT_MULTIPLY_MATRIX(dim) \
	CCV_DEFINE_MAT_GET_ROW(dim) \
	CCV_DEFINE_MAT_GET_COL(dim) \
	CCV_DEFINE_MAT_TRANSPOSE(dim) \
	CCV_DEFINE_MAT_EQUAL(dim)

// Vector type override

typedef union {
	ccvType v[2];
	struct { ccvType x, y; };
} CCV_VEC_TYPENAME(2);

typedef union {
	ccvType v[3];
	union {
		struct {
			union {
				struct { ccvType x, y; };
				union {
					CCV_VEC_TYPENAME(2) xy;
				};
			};
			ccvType z;
		};
		struct {
			ccvType _x;
			CCV_VEC_TYPENAME(2) yz;
		};
	};
} CCV_VEC_TYPENAME(3);

typedef union {
	ccvType v[4];
	union {
		struct {
			union {
				struct {
					union {
						struct { ccvType x, y; };
						CCV_VEC_TYPENAME(2) xy;
					};
					union {
						struct { ccvType z, w; };
						CCV_VEC_TYPENAME(2) zw;
					};
				};
				struct {
					ccvType _x;
					CCV_VEC_TYPENAME(2) yz;
					ccvType _w;
				};
			};
		};
		struct {
			union {
				struct {
					union {
						CCV_VEC_TYPENAME(3) xyz;
					};
					ccvType __w;
				};
				struct {
					ccvType __x;
					CCV_VEC_TYPENAME(3) yzw;
				};
			};
		};
	};
} CCV_VEC_TYPENAME(4);

typedef CCV_VEC_TYPENAME(4) CCV_QUAT_TYPENAME;

// Define 2d, 3d and 4d vectors and matrices

CCV_DEFINE_VEC(2)
CCV_DEFINE_VEC(3)
CCV_DEFINE_VEC(4)

CCV_DEFINE_MAT(2)
CCV_DEFINE_MAT(3)
CCV_DEFINE_MAT(4)

CCV_DEFINE_MAT_DEMOTE(2, 3)
CCV_DEFINE_MAT_DEMOTE(3, 4)

// Define n-dimensional vector type

#undef CCV_DEFINE_VEC_TYPE
#define CCV_DEFINE_VEC_TYPE(dim) \
	typedef struct { \
		ccvType v[dim]; \
	} CCV_VEC_TYPENAME(dim);

// Shorthand transformation multiplier

#define CCV_APPLY_MATRIX(dim, operation) { \
	CCV_MAT_TYPENAME(dim) buffer, multiply; \
	operation; \
	CCV_FUNC_MAT_COPY(dim)(buffer, m); \
	CCV_FUNC_MAT_MULTIPLY_MATRIX(dim)(m, buffer, multiply); \
	}
	
// Define vector utilities

static inline CCV_VEC_TYPENAME(2) CCV_FUNC_VEC_ORTHOGONAL(2)(const CCV_VEC_TYPENAME(2) a)
{
	CCV_VEC_TYPENAME(2) v;

	v.x = -a.y;
	v.y = a.x;

	return v;
}

static inline CCV_VEC_TYPENAME(2) CCV_FUNC_VEC_NEW(2)(const ccvType x, const ccvType y)
{
	CCV_VEC_TYPENAME(2) v;

	v.x = x;
	v.y = y;

	return v;
}

static inline CCV_VEC_TYPENAME(3) CCV_FUNC_VEC_CROSS_PRODUCT(3)(const CCV_VEC_TYPENAME(3) a, const CCV_VEC_TYPENAME(3) b)
{
	CCV_VEC_TYPENAME(3) v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;

	return v;
}

static inline CCV_VEC_TYPENAME(3) CCV_FUNC_VEC_NEW(3)(const ccvType x, const ccvType y, const ccvType z)
{
	CCV_VEC_TYPENAME(3) v;

	v.x = x;
	v.y = y;
	v.z = z;

	return v;
}

static inline CCV_VEC_TYPENAME(4) CCV_FUNC_VEC_NEW(4)(const ccvType x, const ccvType y, const ccvType z, const ccvType w)
{
	CCV_VEC_TYPENAME(4) v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;

	return v;
}

// Define quaternion operations

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_IDENTITY()
{
	CCV_QUAT_TYPENAME q;

	q.x = q.y = q.z = 0;
	q.w = 1;

	return q;
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_ROTATE(CCV_VEC_TYPENAME(3) axis, ccvType radians)
{
	CCV_QUAT_TYPENAME q;
	ccvType s = CCV_SIN(radians * (ccvType)0.5);

	q.xyz = CCV_FUNC_VEC_MULTIPLY(3)(axis, s);
	q.w = CCV_COS(radians * (ccvType)0.5);

	return q;
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_MULTIPLY(const CCV_QUAT_TYPENAME a, const CCV_QUAT_TYPENAME b)
{
	CCV_QUAT_TYPENAME r;
	CCV_VEC_TYPENAME(3) w;

	r.xyz = CCV_FUNC_VEC_CROSS_PRODUCT(3)(a.xyz, b.xyz);
	w = CCV_FUNC_VEC_MULTIPLY(3)(a.xyz, b.w);
	r.xyz = CCV_FUNC_VEC_ADD(3)(r.xyz, w);
	w = CCV_FUNC_VEC_MULTIPLY(3)(b.xyz, a.w);
	r.xyz = CCV_FUNC_VEC_ADD(3)(r.xyz, w);

	r.w = a.w * b.w - CCV_FUNC_VEC_DOTPRODUCT(3)(a.xyz, b.xyz);

	return r;
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_ADD_ROTATION(CCV_QUAT_TYPENAME q, CCV_VEC_TYPENAME(3) axis, ccvType radians)
{
	return CCV_FUNC_QUAT_MULTIPLY(q, CCV_FUNC_QUAT_ROTATE(axis, radians));
}

static inline CCV_VEC_TYPENAME(3) CCV_FUNC_QUAT_MULTIPLY_VECTOR(const CCV_QUAT_TYPENAME q, const CCV_VEC_TYPENAME(3) p)
{
	CCV_VEC_TYPENAME(3) t = CCV_FUNC_VEC_MULTIPLY(3)(CCV_FUNC_VEC_CROSS_PRODUCT(3)(q.xyz, p), 2);
	
	return CCV_FUNC_VEC_ADD(3)(CCV_FUNC_VEC_ADD(3)(p, CCV_FUNC_VEC_MULTIPLY(3)(t, q.w)), CCV_FUNC_VEC_CROSS_PRODUCT(3)(q.xyz, t));
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_ADD(const CCV_QUAT_TYPENAME a, const CCV_QUAT_TYPENAME b)
{
	return CCV_FUNC_VEC_ADD(4)(a, b);
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_SUBTRACT(const CCV_QUAT_TYPENAME a, const CCV_QUAT_TYPENAME b)
{
	return CCV_FUNC_VEC_SUBTRACT(4)(a, b);
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_SCALE(const CCV_QUAT_TYPENAME q, const ccvType n)
{
	return CCV_FUNC_VEC_MULTIPLY(4)(q, n);
}

static inline CCV_QUAT_TYPENAME CCV_FUNC_QUAT_MIX(const CCV_QUAT_TYPENAME a, const CCV_QUAT_TYPENAME b, const ccvType f)
{
	ccvType cosHalfTheta = CCV_FUNC_VEC_DOTPRODUCT(4)(a, b);

	if(CCV_ABS(cosHalfTheta) >= 1)
		return a;
	else {
		ccvType sinHalfTheta = CCV_SQRT(1 - cosHalfTheta * cosHalfTheta);

		if(CCV_ABS(sinHalfTheta) < CCV_EPSILON)
			return CCV_FUNC_VEC_NORMALIZE(4)(CCV_FUNC_VEC_MIX(4)(a, b, (ccvType)0.5));
		else
			return CCV_FUNC_VEC_NORMALIZE(4)(CCV_FUNC_VEC_MIX(4)(a, b, CCV_SIN(f * CCV_ACOS(cosHalfTheta)) / sinHalfTheta));
	}
}

// Define rotation methods

#define CCV_SET_ROTATION_2D() \
	m[0][0] = (ccvType)CCV_COS(r); \
	m[0][1] = (ccvType)CCV_SIN(r); \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]

static inline void CCV_FUNC_MAT_SET_ROTATION(2)(CCV_MAT_TYPENAME(2) m, const ccvType r)
{
	CCV_SET_ROTATION_2D();
}

static inline void CCV_FUNC_MAT_ROTATE(2)(CCV_MAT_TYPENAME(2) m, const ccvType r) CCV_APPLY_MATRIX(2, CCV_FUNC_MAT_SET_ROTATION(2)(multiply, r));

static inline void CCV_FUNC_MAT_SET_ROTATION_2D(2)(CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	CCV_FUNC_MAT_ZERO(3)(m);

	CCV_SET_ROTATION_2D();
	m[2][2] = 1;
}

static inline void CCV_FUNC_MAT_ROTATE_2D(3)(CCV_MAT_TYPENAME(3) m, const ccvType r) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_ROTATION_2D(2)(multiply, r));

#define CCV_SET_ROTATION_3D_X() \
	m[0][0] = 1; \
	m[0][1] = 0; \
	m[0][2] = 0; \
	m[1][0] = 0; \
	m[1][1] = (ccvType)CCV_COS(r); \
	m[1][2] = (ccvType)CCV_SIN(r); \
	m[2][0] = 0; \
	m[2][1] = -m[1][2]; \
	m[2][2] = m[1][1]

#define CCV_SET_ROTATION_3D_Y() \
	m[0][0] = (ccvType)CCV_COS(r); \
	m[0][1] = 0; \
	m[1][0] = 0; \
	m[1][1] = 1; \
	m[1][2] = 0; \
	m[2][0] = (ccvType)CCV_SIN(r); \
	m[0][2] = -m[2][0]; \
	m[2][1] = 0; \
	m[2][2] = m[0][0]

#define CCV_SET_ROTATION_3D_Z() \
	m[0][0] = (ccvType)CCV_COS(r); \
	m[0][1] = (ccvType)CCV_SIN(r); \
	m[0][2] = 0; \
	m[1][0] = -m[0][1]; \
	m[1][1] = m[0][0]; \
	m[1][2] = 0; \
	m[2][0] = 0; \
	m[2][1] = 0; \
	m[2][2] = 1

static inline void CCV_FUNC_MAT_SET_ROTATION_X(3)(CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	CCV_SET_ROTATION_3D_X();
}

static inline void CCV_FUNC_MAT_SET_ROTATION_Y(3)(CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	CCV_SET_ROTATION_3D_Y();
}

static inline void CCV_FUNC_MAT_SET_ROTATION_Z(3)(CCV_MAT_TYPENAME(3) m, const ccvType r)
{
	CCV_SET_ROTATION_3D_Z();
}

static inline void CCV_FUNC_MAT_ROTATE_X(3)(CCV_MAT_TYPENAME(3) m, const ccvType r) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_ROTATION_X(3)(multiply, r))

static inline void CCV_FUNC_MAT_ROTATE_Y(3)(CCV_MAT_TYPENAME(3) m, const ccvType r) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_ROTATION_Y(3)(multiply, r))

static inline void CCV_FUNC_MAT_ROTATE_Z(3)(CCV_MAT_TYPENAME(3) m, const ccvType r) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_ROTATION_Z(3)(multiply, r))

static inline void CCV_FUNC_MAT_SET_ROTATION_X(4)(CCV_MAT_TYPENAME(4) m, const ccvType r)
{
	CCV_FUNC_MAT_ZERO(4)(m);

	CCV_SET_ROTATION_3D_X();
	m[3][3] = 1;
}

static inline void CCV_FUNC_MAT_SET_ROTATION_Y(4)(CCV_MAT_TYPENAME(4) m, const ccvType r)
{
	CCV_FUNC_MAT_ZERO(4)(m);

	CCV_SET_ROTATION_3D_Y();
	m[3][3] = 1;
}

static inline void CCV_FUNC_MAT_SET_ROTATION_Z(4)(CCV_MAT_TYPENAME(4) m, const ccvType r)
{
	CCV_FUNC_MAT_ZERO(4)(m);

	CCV_SET_ROTATION_3D_Z();
	m[3][3] = 1;
}

static inline void CCV_FUNC_MAT_ROTATE_X(4)(CCV_MAT_TYPENAME(4) m, const ccvType r) CCV_APPLY_MATRIX(4, CCV_FUNC_MAT_SET_ROTATION_X(4)(multiply, r))

static inline void CCV_FUNC_MAT_ROTATE_Y(4)(CCV_MAT_TYPENAME(4) m, const ccvType r) CCV_APPLY_MATRIX(4, CCV_FUNC_MAT_SET_ROTATION_Y(4)(multiply, r))

static inline void CCV_FUNC_MAT_ROTATE_Z(4)(CCV_MAT_TYPENAME(4) m, const ccvType r) CCV_APPLY_MATRIX(4, CCV_FUNC_MAT_SET_ROTATION_Z(4)(multiply, r))

// Define translation methods

static inline void CCV_FUNC_MAT_SET_TRANSLATION(3)(CCV_MAT_TYPENAME(3) m, const CCV_VEC_TYPENAME(2) v)
{
	CCV_FUNC_MAT_IDENTITY(3)(m);

	m[2][0] = v.x;
	m[2][1] = v.y;
}

static inline void CCV_FUNC_MAT_TRANSLATE(3)(CCV_MAT_TYPENAME(3) m, const CCV_VEC_TYPENAME(2) v) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_TRANSLATION(3)(multiply, v))

static inline void CCV_FUNC_MAT_SET_TRANSLATION(4)(CCV_MAT_TYPENAME(4) m, const CCV_VEC_TYPENAME(3) v)
{
	CCV_FUNC_MAT_IDENTITY(4)(m);

	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
}

static inline void CCV_FUNC_MAT_TRANSLATE(4)(CCV_MAT_TYPENAME(4) m, const CCV_VEC_TYPENAME(3) v) CCV_APPLY_MATRIX(4, CCV_FUNC_MAT_SET_TRANSLATION(4)(multiply, v))

// Define scaling methods

static inline void CCV_FUNC_MAT_SET_SCALE(2)(CCV_MAT_TYPENAME(2) m, const ccvType scale)
{
	m[0][0] = m[1][1] = scale;
	m[1][0] = m[0][1] = 0;
}

static inline void CCV_FUNC_MAT_SCALE(2)(CCV_MAT_TYPENAME(2) m, const ccvType scale) CCV_APPLY_MATRIX(2, CCV_FUNC_MAT_SET_SCALE(2)(multiply, scale))

static inline void CCV_FUNC_MAT_SET_SCALE_2D(3)(CCV_MAT_TYPENAME(3) m, const ccvType scale)
{
	CCV_FUNC_MAT_ZERO(3)(m);

	m[2][2] = 1;
	m[0][0] = m[1][1] = scale;
}

static inline void CCV_FUNC_MAT_SCALE_2D(3)(CCV_MAT_TYPENAME(3) m, const ccvType scale) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_SCALE_2D(3)(multiply, scale))

static inline void CCV_FUNC_MAT_SET_SCALE(3)(CCV_MAT_TYPENAME(3) m, const ccvType scale)
{
	CCV_FUNC_MAT_ZERO(3)(m);
	
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void CCV_FUNC_MAT_SCALE(3)(CCV_MAT_TYPENAME(3) m, const ccvType scale) CCV_APPLY_MATRIX(3, CCV_FUNC_MAT_SET_SCALE(3)(multiply, scale))

static inline void CCV_FUNC_MAT_SET_SCALE(4)(CCV_MAT_TYPENAME(4) m, const ccvType scale)
{
	CCV_FUNC_MAT_ZERO(4)(m);
	
	m[3][3] = 1;
	m[0][0] = m[1][1] = m[2][2] = scale;
}

static inline void CCV_FUNC_MAT_SCALE(4)(CCV_MAT_TYPENAME(4) m, const ccvType scale) CCV_APPLY_MATRIX(4, CCV_FUNC_MAT_SET_SCALE(4)(multiply, scale))

// Inverse matrix

static inline void CCV_FUNC_MAT_INVERSE(3)(CCV_MAT_TYPENAME(3) t, CCV_MAT_TYPENAME(3) m)
{
	ccvType s[3][3];
	ccvType idet;

	s[0][0] = m[1][1] * m[2][2] - m[2][1] * m[1][2];
	s[1][0] = - m[0][1] * m[2][2] + m[2][1] * m[0][2];
	s[2][0] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
	s[0][1] = - m[1][0] * m[2][2] + m[1][2] * m[2][0];
	s[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
	s[2][1] = - m[0][0] * m[1][2] + m[0][2] * m[1][0];
	s[0][2] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	s[1][2] = - m[0][0] * m[2][1] + m[0][1] * m[2][0];
	s[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	idet = m[0][0] * s[0][0] + m[1][0] * s[1][0] + m[2][0] * s[2][0];
#ifdef _DEBUG
	assert(idet != 0);
#endif
	idet = 1 / idet;

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

static inline void CCV_FUNC_MAT_INVERSE(4)(CCV_MAT_TYPENAME(4) t, CCV_MAT_TYPENAME(4) m)
{
	ccvType s[6];
	ccvType c[6];
	ccvType idet;

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

	idet = s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0];
#ifdef _DEBUG
	assert(idet != 0);
#endif
	idet = 1 / idet;

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

static inline void CCV_FUNC_MAT_PERSPECTIVE(4)(CCV_MAT_TYPENAME(4) m, ccvType angle, ccvType aspect, ccvType zNear, ccvType zFar)
{
	ccvType a = CCV_TAN(angle * (ccvType)0.5);

#ifdef _DEBUG
	assert(aspect != 0);
	assert(a != 0);
#endif

	a = 1 / a;

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

static inline void CCV_FUNC_MAT_LOOK_AT(4)(CCV_MAT_TYPENAME(4) m, CCV_VEC_TYPENAME(3) from, CCV_VEC_TYPENAME(3) to, CCV_VEC_TYPENAME(3) up)
{
	unsigned int i;
	CCV_VEC_TYPENAME(3) f = CCV_FUNC_VEC_NORMALIZE(3)(CCV_FUNC_VEC_SUBTRACT(3)(to, from));
	CCV_VEC_TYPENAME(3) s = CCV_FUNC_VEC_NORMALIZE(3)(CCV_FUNC_VEC_CROSS_PRODUCT(3)(f, up));
	CCV_VEC_TYPENAME(3) t = CCV_FUNC_VEC_CROSS_PRODUCT(3)(s, f);

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
		CCV_VEC_TYPENAME(3) r = CCV_FUNC_MAT_GET_ROW(4)(m, i).xyz;
		m[3][i] = -CCV_FUNC_VEC_DOTPRODUCT(3)(r, from);
	}

	m[3][3] = 1;
}

#ifdef __cplusplus
}
#endif

#endif
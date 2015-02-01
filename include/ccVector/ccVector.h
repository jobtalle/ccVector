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

#include <math.h>
#include <string.h>

#ifndef inline
#define inline __inline
#endif

// Type

#define _CCV_TYPE float

// Prefixes

#define _CCV_VEC_TYPENAME(dim) ccvVec##dim

#define _CCV_MAT_TYPENAME(dim) ccvMat##dim

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

#define _CCV_DEFINE_VEC_CROSSPRODUCT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##CrossProduct(_CCV_VEC_TYPENAME(dim) v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] = a[i] * b[i]; \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Multiply(_CCV_VEC_TYPENAME(dim) v, _CCV_TYPE n) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v[i] *= n; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline float _CCV_VEC_TYPENAME(dim)##DotProduct(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		float result = 0; \
		for(i = 0; i < dim; i++) \
			result += a[i] * b[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline float _CCV_VEC_TYPENAME(dim)##Length(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		float squaredResult = 0; \
		for(i = 0; i < dim; i++) \
			squaredResult += v[i] * v[i]; \
		return sqrtf(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim)##Normalize(_CCV_VEC_TYPENAME(dim) v) { \
		_CCV_VEC_TYPENAME(dim)##Multiply(v, 1.0f / _CCV_VEC_TYPENAME(dim)##Length(v)); \
	}

// Matrix operations

#define _CCV_DEFINE_MAT_ZERO(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Zero(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; col++) \
			for(row = 0; row < dim; row++) m[row][col] = 0; \
		}

#define _CCV_DEFINE_MAT_IDENTITY(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##Identity(_CCV_MAT_TYPENAME(dim) m) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; col++) \
			for(row = 0; row < dim; row++) m[row][col] = row == col ? 1.f : 0; \
		}

#define _CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyScalar(_CCV_MAT_TYPENAME(dim) m, _CCV_TYPE n) { \
		unsigned int row = 0; \
		unsigned int col = 0; \
		for(col = 0; col < dim; col++) \
			for(row = 0; row < dim; row++) m[row][col] *= n; \
		}

#define _CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim) \
	static inline _CCV_MAT_TYPENAME(dim)##MultiplyVector(_CCV_VEC_TYPENAME(dim) v, _CCV_MAT_TYPENAME(dim) a, _CCV_VEC_TYPENAME(dim) b) { \
	}

// Definition calls

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ZERO(dim) \
	_CCV_DEFINE_VEC_ADD(dim) \
	_CCV_DEFINE_VEC_SUBTRACT(dim) \
	_CCV_DEFINE_VEC_CROSSPRODUCT(dim) \
	_CCV_DEFINE_VEC_MULTIPLY(dim) \
	_CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	_CCV_DEFINE_VEC_LENGTH(dim) \
	_CCV_DEFINE_VEC_NORMALIZE(dim)

#define CCV_DEFINE_MAT(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_MAT_TYPE(dim) \
	_CCV_DEFINE_MAT_ZERO(dim) \
	_CCV_DEFINE_MAT_IDENTITY(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_SCALAR(dim) \
	_CCV_DEFINE_MAT_MULTIPLY_VECTOR(dim)

// Getters & setters

#define CCV_VEC_SET(vec, n, value) vec[n] = value
#define CCV_VEC_GET(vec, n) vec[n]

#define CCV_MAT_SET(mat, row, col, value) mat[row][col] = value
#define CCV_MAT_GET(mat, row, col) mat[row][col]
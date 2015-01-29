//__________________________________________________________________________________//
//                                                                                  //
//                           __      __       _                                     //
//                           \ \    / /      | |                                    //
//                      ___ __\ \  / /__  ___| |_ ___  _ __                         //
//                     / __/ __\ \/ / _ \/ __| __/ _ \| '__|                        //
//                    | (_| (__ \  /  __/ (__| || (_) | |                           //
//                     \___\___| \/ \___|\___|\__\___/|_| v1.0                      //
//                                                                                  //
//              Copyright (C) 2014 - 2015 \ Job Talle (job@ccore.org)               //
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

#ifndef inline
#define inline __inline
#endif

#define _CCV_VEC_TYPENAME(dim) ccvVec##dim

#define _CCV_DEFINE_VEC_TYPE(dim) \
	typedef struct { \
	float elements[dim]; \
	} _CCV_VEC_TYPENAME(dim);

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Add(_CCV_VEC_TYPENAME(dim) *v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v->elements[i] = a.elements[i] + b.elements[i]; \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Subtract(_CCV_VEC_TYPENAME(dim) *v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v->elements[i] = a.elements[i] - b.elements[i]; \
	}

#define _CCV_DEFINE_VEC_CROSSPRODUCT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##CrossProduct(_CCV_VEC_TYPENAME(dim) *v, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v->elements[i] = a.elements[i] * b.elements[i]; \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Multiply(_CCV_VEC_TYPENAME(dim) *v, float n) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) \
			v->elements[i] *= n; \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline float _CCV_VEC_TYPENAME(dim)##DotProduct(const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		float result = 0; \
		for(i = 0; i < dim; i++) \
			result += a.elements[i] * b.elements[i]; \
		return result; \
	}

#define _CCV_DEFINE_VEC_LENGTH(dim) \
	static inline float _CCV_VEC_TYPENAME(dim)##Length(const _CCV_VEC_TYPENAME(dim) v) { \
		unsigned int i; \
		float squaredResult = 0; \
		for(i = 0; i < dim; i++) \
			squaredResult += v.elements[i] * v.elements[i]; \
		return sqrtf(squaredResult); \
	}

#define _CCV_DEFINE_VEC_NORMALIZE(dim) \
	static inline _CCV_VEC_TYPENAME(dim)##Normalize(_CCV_VEC_TYPENAME(dim) *v) { \
		unsigned int i; \
		float length = _CCV_VEC_TYPENAME(dim)##Length(*v); \
		for(i = 0; i < dim; i++) \
			v->elements[i] /= length; \
	}

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ADD(dim) \
	_CCV_DEFINE_VEC_SUBTRACT(dim) \
	_CCV_DEFINE_VEC_CROSSPRODUCT(dim) \
	_CCV_DEFINE_VEC_MULTIPLY(dim) \
	_CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	_CCV_DEFINE_VEC_LENGTH(dim) \
	_CCV_DEFINE_VEC_NORMALIZE(dim)

#define CCV_SET(vec, n, value) vec.elements[n] = value
#define CCV_GET(vec, n) (vec.elements[n])
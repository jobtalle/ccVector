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

#ifndef inline
#define inline __inline
#endif

#define _CCV_VEC_TYPENAME(dim) ccvVec##dim

#define _CCV_DEFINE_VEC_TYPE(dim) \
	typedef struct { \
	float elements[dim]; \
	} _CCV_VEC_TYPENAME(dim);

#define _CCV_DEFINE_VEC_ADD(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Add(_CCV_VEC_TYPENAME(dim) *result, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) { \
			result->elements[i] = a.elements[i] + b.elements[i]; \
		} \
	}

#define _CCV_DEFINE_VEC_SUBTRACT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Subtract(_CCV_VEC_TYPENAME(dim) *result, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) { \
			result->elements[i] = a.elements[i] - b.elements[i]; \
		} \
	}

#define _CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##DotProduct(_CCV_VEC_TYPENAME(dim) *result, const _CCV_VEC_TYPENAME(dim) a, const _CCV_VEC_TYPENAME(dim) b) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) { \
			result->elements[i] = a.elements[i] * b.elements[i]; \
		} \
	}

#define _CCV_DEFINE_VEC_MULTIPLY(dim) \
	static inline void _CCV_VEC_TYPENAME(dim)##Multiply(_CCV_VEC_TYPENAME(dim) *result, float n) { \
		unsigned int i; \
		for(i = 0; i < dim; i++) { \
			result->elements[i] *= n; \
		} \
	}

#define CCV_DEFINE_VEC(dim) \
	_CCV_DEFINE_VEC_TYPE(dim) \
	_CCV_DEFINE_VEC_ADD(dim) \
	_CCV_DEFINE_VEC_SUBTRACT(dim) \
	_CCV_DEFINE_VEC_DOTPRODUCT(dim) \
	_CCV_DEFINE_VEC_MULTIPLY(dim)

#define CCV_SET(vec, n, value) vec.elements[n] = value
#define CCV_GET(vec, n) (vec.elements[n])
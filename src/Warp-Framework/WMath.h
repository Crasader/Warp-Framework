// � 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_MATH_H_
#define _W_MATH_H_

#include "WDefines.h"
#include <math.h>

constexpr W_FLOAT PI = 3.14159265f;
constexpr W_DOUBLE PI_D = 3.1415926535897932;

template <typename T>
inline auto sq(const T& x)
{
	return x* x;
}

inline W_FLOAT clamp(W_FLOAT x, W_FLOAT lowerlimit, W_FLOAT upperlimit)
{
	if (x < lowerlimit) x = lowerlimit;
	if (x > upperlimit) x = upperlimit;
	return x;
}

template<typename T>
inline T lerp(const T& src, const T& dst, W_FLOAT alpha)
{
	return src + (dst - src)* alpha;
}

inline W_FLOAT smoothstep(W_FLOAT from, W_FLOAT to, W_FLOAT x)
{
	x = clamp((x - from) / (to - from), 0.0f, 1.0f);
	return x* x* (3 - 2* x);
}

inline bool isNear(W_FLOAT a, W_FLOAT b, W_FLOAT min)
{
	if (a > b)
	{
		if (a - b < min) { return true; }
		else { return false; }
	}
	else
	{
		if (b - a < min) { return true; }
		else { return false; }
	}
}

#endif // !_W_MATH_H_


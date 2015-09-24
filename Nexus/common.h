#ifndef _COMMON_
#define _COMMON_

struct point {
	int x;
	int y;

	explicit point(int x=0, int y=0): x(x),y(y){}
};

#endif
#ifndef _COMMON_
#define _COMMON_

struct point {
	int x;
	int y;

	explicit point(int x=0, int y=0): x(x),y(y){}

	//Comparision operators
	bool operator!=(point a) const{
		if (a.x!=x || a.y!=y) return true;
		else return false;
	}
};

#endif
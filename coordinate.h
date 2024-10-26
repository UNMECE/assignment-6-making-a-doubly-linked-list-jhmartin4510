#ifndef _COORDINATE_H_
#define _COORDINATE_H_

struct _coordinate
{
	float x;
	float y;
	int coord_id;
	struct _coordinate *next;
	struct _coordinate *previous;
	
//	_coordinate(){};
/*	_coordinate(int x, int y)
	{
		x = x;
		y = y;
		coord_id++;
		next = NULL;
		previous = NULL;
	};
*/
};
typedef struct _coordinate Coordinate;

#endif


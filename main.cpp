#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "coordinate.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
void add_coordinate(Coordinate* &list_end, float x, float y)
{
	Coordinate *New = new Coordinate;
	New->x= x;
	New->y = y;
	New->previous = NULL;
	New->next = NULL;
	
	if(list_end == NULL)
	{
		New->coord_id=1;
		list_end = New;  
		return;
	}	
	
	Coordinate *temp = list_end;
	while(temp->next != NULL)
	{
		temp = temp-> next;		
	}

	New->coord_id = (temp->coord_id)+1;
	temp->next = New;
	New->previous = temp;	

}
void forward_display(Coordinate *list_end)
{
	Coordinate *node = list_end;
	std::cout<< "Forward list" <<std::endl;
	if(node == NULL)
	{
		std::cout<<"The list is empty" <<std::endl;
	}
	while(node != NULL)
	{
		std::cout<<std::fixed <<std::setprecision(4) <<node->x <<"\t" <<node->y <<"\t" <<node->coord_id <<std::endl;
		node = node->next;
	}
}
void backwards_display(Coordinate *list_beginning)
{
	Coordinate *node = list_beginning;
	std::cout <<"List in Reverse" <<std::endl;
	if(node == NULL)
	{
		std::cout<<"The list is empty" <<std::endl;
	}	
	while(node->next != NULL)
	{
		node = node->next;
	}
	while(node != NULL)
	{
		std::cout <<node->x <<"\t" <<node->y <<std::endl;
		node = node->previous;
	}
}

void list_length(Coordinate *list_beginning)
{
	Coordinate *temp = list_beginning;
	int ct = 1;
	while(temp->next != NULL)
	{
		temp = temp->next;
		ct++;
	}
	std::cout<<"The size of this list is: " <<ct <<std::endl;
}

void delete_coordinate(Coordinate* &list_beginning, int coord_id_to_delete)
{
	Coordinate *temp = list_beginning;
	while(temp->next != NULL  && temp->coord_id != coord_id_to_delete)
	{
		temp = temp->next;
	}
	if(temp->next == NULL)
	{
		std::cout<<"No coord_id found" <<std::endl;
	}
	if(temp->previous != NULL)
	{
		temp->previous->next = temp->next;
	}		
	if(temp->next != NULL)
	{
		temp->next->previous = temp->previous;	
	}
	if(list_beginning == temp)
	{
		list_beginning = temp->next;
	}
	delete temp;
}

void closest_to(Coordinate *beginning_list, float x, float y)
{
	
}

int main(int argc, char** argv)
{

char *a = argv[1];
int list_coord = atoi(a);

std::cout<<"The number of coordinates in list is:" <<list_coord <<std::endl;

Coordinate *list = new Coordinate;
list = NULL;

int ct = 0;
srand(time(NULL));
float rand_x;
float rand_y;
while(ct<list_coord)
{
	rand_x = (float) (rand()) / (float) (RAND_MAX);
	rand_y = (float) (rand()) / (float) (RAND_MAX);
	add_coordinate(list,rand_x, rand_y);	
	ct++;
}
forward_display(list);
backwards_display(list);
list_length(list);
delete_coordinate(list, 8);
delete_coordinate(list, 6);
forward_display(list);
list_length(list);
return 0;	
}

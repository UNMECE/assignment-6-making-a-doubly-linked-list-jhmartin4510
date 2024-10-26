#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "coordinate.h"
#include <ctime>
#include <iomanip>
#include <cmath>


/*adds a coordinate to the address of the list pointer with the parameters of x and y.*/
void add_coordinate(Coordinate* &list_end, float x, float y)
{
	Coordinate *New = new Coordinate;
	New->x= x;
	New->y = y;
	New->previous = NULL;
	New->next = NULL;
/*checking if list is empty and adding the coordinate to the start of list*/	
	if(list_end == NULL)
	{
		New->coord_id=1; 	//initializng first coord_id
		list_end = New;  	//address of list_end now points to the address of "New" object
		return;
	}	

	Coordinate *temp = list_end;	
/*Traverses the list to find the end of the list*/
	while(temp->next != NULL)
	{
		temp = temp-> next;		
	}


	New->coord_id = (temp->coord_id)+1;	//incremeting the coord_id of the new object from the temp coord_id that at the previous end of the list
	temp->next = New;	//setting the temp's next pointer to the object that the New pointer is pointing to
	New->previous = temp;	//seeting the previos pointer of New to point to the temp object 

}

/*Prints the list in forward order*/
void forward_display(Coordinate *list_end)
{
	Coordinate *node = list_end;
	std::cout<< "------------" <<std::endl;
	std::cout<< "Forward list" <<std::endl;
	/*if list is empty*/
	if(node == NULL)
	{
		std::cout<<"The list is empty" <<std::endl;
	}
	/*Printing x, y and coord_id from the list until reaches end of the list*/
	while(node != NULL)
	{
		std::cout<<std::fixed <<std::setprecision(4) <<node->x <<"\t" <<node->y <<"\t" <<node->coord_id <<std::endl;
		node = node->next;
	}
	std::cout <<"-----------" <<std::endl;
}

/*Prints the list backwards*/
void backwards_display(Coordinate *list_beginning)
{
	Coordinate *node = list_beginning;
	std::cout <<"---------------" <<std::endl;
	std::cout <<"List in Reverse" <<std::endl;
	/*checking if list is empty*/
	if(node == NULL)
	{
		std::cout<<"The list is empty" <<std::endl;
	}
	/*finding the end of the list*/	
	while(node->next != NULL)
	{
		node = node->next;
	}
	/*Printing x,y, coord_id of each object in the list using the previous pointer*/
	while(node != NULL)
	{
		std::cout <<node->x <<"\t" <<node->y <<std::endl;
		node = node->previous;
	}
	std::cout <<"---------------" <<std::endl;
}

/*calculates the length of the list*/
void list_length(Coordinate *list_beginning)
{
	Coordinate *temp = list_beginning;
	int ct = 1;	//initializing a counter
	/*using the counter to count how many object are in the list*/
	while(temp->next != NULL)
	{
		temp = temp->next;
		ct++;
	}
	std::cout<<"----------------------------" <<std::endl;
	std::cout<<"The size of this list is: " <<ct <<std::endl;
	std::cout<<"----------------------------" <<std::endl;
}

/*Deletes a coordiante from the list*/
void delete_coordinate(Coordinate* &list_beginning, int coord_id_to_delete)
{
	Coordinate *temp = list_beginning;
	/*traversing the list until temp reaches end of list or coord_id is found in the list*/
	while(temp != NULL  && temp->coord_id != coord_id_to_delete)
	{
		temp = temp->next;
	}
	/*if coord_id is not found, then exit function*/
	if(temp == NULL)
	{
		std::cout<<"-------------------------" <<std::endl;
		std::cout<<"No coord_id found for: " <<coord_id_to_delete <<std::endl;
		std::cout<<"-------------------------" <<std::endl;
		return;
	}
	/*initializing previous pointer to point to the next pointer of temp*/
	if(temp->previous != NULL)
	{
		temp->previous->next = temp->next;
	}
	/*initializing next pointer to pointer to previous pointer of temp*/		
	if(temp->next != NULL)
	{
		temp->next->previous = temp->previous;	
	}
	/*if deleting the beginning of the list, changing the address that list_beginning points to set to the next object in the list)*/
	if(list_beginning == temp)
	{
		list_beginning = temp->next;
	}
	delete temp;
}


/*finds the closest coordinate in the list to a giving x,y set.*/
void closest_to(Coordinate *beginning_list, float x, float y)
{
	Coordinate *temp = beginning_list;
	float diff_x= x-(temp->x);
	float diff_y= y-(temp->y);
	float s = sqrt((diff_x*diff_x)+(diff_y*diff_y));	//setting s to the distance of the first object in the list
	float distance;
	Coordinate *small = beginning_list;	//using this pointer to save the smallest coordinate
	
	/*traversing the list and performing the distance calculation*/
	while(temp != NULL)
	{
		diff_x = x-(temp->x);
		diff_y = y-(temp->y);
		distance = sqrt((diff_x*diff_x)+(diff_y*diff_y));
//		std::cout<<"Distance for " <<temp->coord_id << " is:  " <<distance <<std::endl;
/*If distance is smaller than s, set *small to *temp and set s to the new smallest distance*/
		if(distance < s)
		{
			small = temp;
			s = distance;
		}
		temp = temp->next;
	}
	std::cout<<"---------------------------------------" <<std::endl;
	std::cout<<"The closest coordinate is: " <<small->x <<"\t" <<small->y <<"\t" <<small->coord_id <<std::endl;
	std::cout<<"---------------------------------------" <<std::endl;
}

int main(int argc, char** argv)
{
/*command line argument*/
char *a = argv[1];
int list_coord = atoi(a);

//std::cout<<"The number of coordinates in list is:" <<list_coord <<std::endl;

Coordinate *list = new Coordinate;
list = NULL;

int ct = 0;
srand(time(NULL));	
float rand_x;
float rand_y;
while(ct<list_coord)
{
	/*Generateing random number from  0 to 1 and adding those coodinates to list*/
	rand_x = (float) (rand()) / (float) (RAND_MAX);
	rand_y = (float) (rand()) / (float) (RAND_MAX);
	add_coordinate(list,rand_x, rand_y);	
	ct++;
}

forward_display(list);
backwards_display(list);
list_length(list);		//reports list size
delete_coordinate(list, 8);	//deleting object with coord_id 8
delete_coordinate(list, 6);	//deleting object with coord_id 6
forward_display(list);
list_length(list);		//reports new list size after deletes
closest_to(list, .5 , .5);	//reports the coordinate closest to (0.5, 0.5)

return 0;	
}

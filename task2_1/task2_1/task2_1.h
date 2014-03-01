#pragma  once
struct point
{
	float x;
	float y;
	float z;

};
/*displays some information about program*/
void Interface();

/*checking entered data and return 0 if type doesn't match requirements*/
unsigned char Type_checking(int retCode, int val);

/*input coordinates of space points into list of points return 0 if some data doesn't match requirements*/
unsigned char Input(struct point* points, unsigned int num);

/*output list of points on display*/
unsigned char Output(const struct point* points, unsigned int num);

/*checking if string pstr involves only digits*/
unsigned char Is_digit(const char* pstr);

/*unit test for function is digit*/
void Test();

/*sorted array of space points by ascending z coordinate */
unsigned char Sort_points(struct point* p, unsigned int n);

/*displays the smallest distance between points in the list*/
unsigned char Display_distance(const struct point* p, unsigned int num);

/*evaluate the distance between two points*/
double Get_distance(const struct point* a, const struct point* b);


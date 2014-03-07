/**
* @file		task2_1.h
* @brief	header file for task2_1.cpp
			defines data types and prototypes for functions used in task2_1.cpp
*/

#pragma  once
/*defines data type for holding coordinates of space points*/
struct point
{
	float x;
	float y;
	float z;
};

/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface();


/**
* @brief				Checking if data match requirements set to that data types or functions return values

* @param	[in]		unsigned char retCode - return value of other functions for checking functions ended properly
			[in]		int val - number for checking if it's negative or zero
* @return	unsigned char		Return ERROR if data doesn't match requirements
								Return SUCCESS if inputed data match requirements
*/
unsigned char Type_checking(unsigned char retCode, int val);





/**
* @brief					Function for input coordinates of space points
* @param	[in/out]		struct point* points - pointer to array of structures that holds coordinates of points
			[in]			unsigned int num - number of points in list
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was inputed
*/
unsigned char Input(struct point* points, unsigned int num);



/**
* @brief					Function for displaying list of  space points coordinates
* @param	[in]			const struct point* points - pointer to array of structures that holds coordinates of points
			[in]			unsigned int num - number of points in list
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was displayed
*/
unsigned char Output(const struct point* points, unsigned int num);




/**
* @brief					Function for checking if inputed string involves only digits
* @param	[in]			const char* pstr - pointer to, checking for numbers, string
* @return	unsigned char	Return ERROR if string contains not only numbers
							Return SUCCESS if string contains only numbers
*/
unsigned char Is_digit(const char* pstr);


/**
* @brief					Function sorts space points by ascending z coordinate
* @param	[in/out]		struct point* p - pointer to array of structures that holds coordinates of points
			[in]			unsigned int n - number of points in list
* @return	unsigned char	Return ERROR if pointer to array of structures p is NULL
							Return SUCCESS if points were sorted
*/
unsigned char Sort_points(struct point* p, unsigned int n);



/**
* @brief					Function calls function to estimate the distance between space points 
							and displays the smallest distance
* @param	[in]			CONST struct point* p - pointer to array of structures that holds coordinates of points
			[in]			unsigned int num - number of points in list
* @return	unsigned char	Return ERROR if pointer to array of structures p is NULL
							Return SUCCESS if distance was estimated and showed on the screen
*/
unsigned char Display_distance(const struct point* p, unsigned int num);



/**
* @brief					Function estimates the distance between two space points
* @param	[in]			const struct point* a - pointer to structure that holds coordinates of first point
			[in]			const struct point* a - pointer to structure that holds coordinates of second point
* @return	double			Return ERROR if pointer to array of structures a or b is NULL
							Return distance between points if distance was estimated
*/
double Get_distance(const struct point* a, const struct point* b);



/*unit test for function is_digit*/
void Test();
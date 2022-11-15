
#include<stdio.h> /*printf*/
#include <stdlib.h> /* malloc, free*/
#include <assert.h>   /* assert */
/* state table:
1 = dead
0 = alive
2 = killer
*/
static int Find(int soldiers[], size_t index,int state,size_t size);
static int Josephus(int soldiers[],size_t size);
static void FuncTest(size_t out, size_t e_out, const char *name);
static int* Init(int *arr,size_t size);
static void TestJosephus();
static void DataType(); /* e3 */
static int *Matrix(int *arr, int rows, int cols, int *res);
static int* InitMatrix(int *arr, int rows, int cols);
static int* InitRes(int *arr, int rows);
static void TestMatrix();
int main()
{
	TestMatrix();
	TestJosephus();
	/*
	DataType();*/
	return 0;
}
static void TestMatrix()
{
	int *res;
	int arr[16] = {0,1,2,3, 0,1,1,1 ,0,8,2,5, 0,9,1,3};
	int e_out[4] = {6,3,15,13};
	int rows = 4, i = 0;
	int cols = 4;
	printf("Ws3\n");
	
	res = InitRes(res,rows);
	res = Matrix(arr, rows, cols, res);
	
	for (i = 0; i < rows; ++i)
	{
		FuncTest((size_t)res[i],(size_t)e_out[i],"Matrix");
	}
	free(res);
	res = NULL;
}
static int *Matrix(int *arr, int rows, int cols, int *res)
{
	int i = 0, j = 0, sum = 0, counter = 0;
	for (i = 0; i < rows*cols; i += cols)
	{
		for (j = 0; j < cols; ++j)
		{
			sum += arr[i+j];
		}
		res[counter] = sum;
		sum = 0;
		++counter;
	}
	return res;
}
static int* InitRes(int *arr, int rows)
{
	int i = 0;
	arr = (malloc(sizeof(int)*rows));
	
	/*printf("size is %ld\n", (rows*sizeof(int)));*/
	/*check if malloc succses */
	if (arr == NULL)
	{
		printf("ERORR: MALLOC FAILED");
		return NULL;
	}
	for(i = 0; i < rows; ++i)
	{
		arr[i] = 0;
	}
	
	return arr;
}
static int* InitMatrix(int *arr, int rows, int cols)
{
	int i = 0;
	int size = rows * cols;
	arr = (malloc(sizeof(int)*size));
	/*printf("size is %ld\n", (size*sizeof(int)));*/
	/* check if malloc succses */
	if (arr == NULL)
	{
		printf("ERORR: MALLOC FAILED");
		return NULL;
	}
	/* init to zero the arr */
	for(i = 0; i < size; ++i)
	{
		arr[i] = 1;
	}
	return arr;
}
static int Find(int soldiers[], size_t index,int state,size_t size)
{
 /*check if already pass all the array */
int flag = 0;
++index; 
		if (index >= size)
		{
			index = 0;
		}
	/*to check the next soldier */
	while(soldiers[index] != state)
	{
		++index;
		/* if index greater then size, need to check from the start */
		if (index >= size)
		{
			index = 0;
		/*Update flag to avoid infinty loop */	
			++flag; 
		}
		
		if (flag == 2)
		{
			/*printf("\tmid return index: %ld\n", index);*/
			return index;
		}
	}
			/*printf("\treturn index: %ld\n", index);*/
	return index;
}
static int Josephus(int soldiers[],size_t size)
{
	int killer = 0;
	int who_is_alive = 0;
	int who_get_the_sword = 0;
	size_t n = 0;
	/*printf("size: %ld start running\n", size);*/
	for (n = 0; n < (size - 1); ++n)
	{
	
		killer = Find(soldiers,who_get_the_sword,2,size);
			
		/*printf("\t killer is: %d\n",killer);*/
		
		who_is_alive = Find(soldiers,killer,0,size);
		
		soldiers[who_is_alive] = 1;
		
		/*printf("\t dead: %d\n",who_is_alive);*/
		
		soldiers[killer] = 0;
		
		who_get_the_sword = Find(soldiers,who_is_alive,0,size);
		
		soldiers[who_get_the_sword] = 2;
	}
	
/*printf("final result: %d\n", killer);*/
		
return killer;
}
static void FuncTest(size_t out, size_t e_out, const char *name)
{
	if (out != e_out)
	{
		printf("func: %s FAILED out: %ld, expected output: %ld  \n",name ,out ,e_out);
	}
}
static int* Init(int *arr,size_t size)
{
	size_t i = 0;
	arr = (malloc(sizeof(int) * size));
	
	/* check if malloc succses */
	if (arr == NULL)
	{
		printf("ERORR: MALLOC FAILED");
		return NULL;
	}
	/* init to zero the arr */
	for(i = 0; i < size; ++i)
	{
		arr[i] = 0;
	}
	/* create killer */
	arr[0] = 2;
	return arr;
}
static void TestJosephus()
{
	size_t i = 0;
	size_t size[] = {10,9,11,14};
	size_t e_out[] = {4,2,6,12};
	int *soldiers = NULL; 
	size_t size_cases = sizeof(size)/sizeof(size[0]);
	
	/* printf("cases: %ld \n",size_cases);*/
	
	for (i = 0; i < size_cases; ++i)
	{
	
	/* printf("size: %ld\n", size[i]);*/
	
		soldiers = Init(soldiers, size[i]);
		soldiers[0] = 2;
		
		FuncTest(Josephus(soldiers,size[i]),e_out[i],"Josephus");
		
		free(soldiers);
		
		soldiers = NULL;
	}
}
static void DataType()
{
	int dt_int = 0;
	double dt_double = 0;
	long double dt_long_double = 0;
	float dt_float = 0;
	char dt_char = 0;
	size_t dt_size_t = 0;
	unsigned char dt_unsigned_char = 0;
	signed char dt_signed_char = 0;
	short int dt_short_int = 0;
	unsigned int dt_unsigned_int = 0;
	signed int dt_signed_int = 0;
	unsigned short int dt_unsigned_short_int = 0;
	signed short int dt_signed_short_int = 0;
	long int dt_long_int = 0;
	/*long long int dt_long_long_int = 0; no support C90*/
	signed long int dt_signed_long = 0;
	unsigned long int dt_unsigned_long_int = 0;
	unsigned long dt_unsigned_long = 0;
	
	printf("int: %ld \n", sizeof(dt_int));
	printf("double: %ld \n", sizeof(dt_double));
	printf("long double: %ld \n", sizeof(dt_long_double));
	printf("float: %ld \n", sizeof(dt_float));
	printf("char: %ld \n", sizeof(dt_char));
	printf("size_t: %ld \n", sizeof(dt_size_t));
	printf("unsigned char: %ld \n", sizeof(dt_unsigned_char));
	printf("signed char: %ld \n", sizeof(dt_signed_char));
	printf("short int: %ld \n", sizeof(dt_short_int));
	printf("unsigned int: %ld \n", sizeof(dt_unsigned_int));
	printf("long int: %ld \n", sizeof(dt_long_int));
	printf("signed long int: %ld \n", sizeof(dt_signed_long));
	printf("unsigned long int: %ld \n", sizeof(dt_unsigned_long_int));
	printf("unsigned long: %ld \n", sizeof(dt_unsigned_long));
	printf("signed short int %ld \n", sizeof(dt_signed_short_int));
	printf("dt unsigned short int %ld \n", sizeof(dt_unsigned_short_int));
	printf("signed int %ld \n", sizeof(dt_signed_int));
}
	
	

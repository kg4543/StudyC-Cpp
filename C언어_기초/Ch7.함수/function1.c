
void function1(int , int );

int sub1(void) 
{

	printf("\n-------------\n");

	int a = 10, b = 20;

	function1(a,b);

	return 0;
}

void function1(int x, int y) 
{
	int res;
	res = x + y;
	printf("res : %d\n",res);
}
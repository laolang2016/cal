#include<stdio.h>
#include<math.h>

int main(void) {
	printf("\n\nHello World!\n");
	char expression[] = "123.0";
	double res = atof(expression);
	res = atan(res) * 180.0 / 3.141592;
	return 0;
}

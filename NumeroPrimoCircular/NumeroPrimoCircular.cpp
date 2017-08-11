#include <stdio.h>
using namespace std;

void esPrimo(int n)
{
	int i;
	int res = 0;
	for (i = 1; i < (n + 1); i++)
	{
		if (n % i == 0)
		{
			res++;
		}
	}

	if (res != 2)
	{
		printf("No es Primo \n");
	}
	else
	{
		printf("Si es Primo \n");
	}
}

int main()
{
	int n;
	int arr[3] = { 0, 0, 0 };
	printf("Introduce un numero: \n");
	scanf("%i", &n);

	esPrimo(n);

	return 0;

}
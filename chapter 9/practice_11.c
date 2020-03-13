#include <stdio.h>

void Fibonacci(int n);
int main(void)
{
    int num;
    printf("Please enter an integer: ");
    while (scanf("%d",&num)==1)
        Fibonacci(num);
    printf("Done\n");
    return 0;
}

void Fibonacci(int n)
{
    int Fn=0;
    int Fn1=0;
    int Fn2 =1;
    int i=1;
    while(i<=n)
    {

        printf("%d ",Fn);
                Fn = Fn1 + Fn2;
        if (i%2==0)
        Fn1=Fn;
        else
        {
            Fn2 =Fn;
        }
        
        i++;
    }
}

/*#include <stdio.h>

void Fibonacci(int n);

int main(void)
{
	int n;
	
	printf("Please enter an integer: ");
	scanf("%d", &n);
	Fibonacci(n);
	
	return 0;
}

void Fibonacci(int n)
{
	int Fn = 0; // Fibonacci numbers
	int Fn1 = 0;
	int Fn2 = 1;
	int counter = 0;
	
	printf("All Fibanocci numbers that smaller than %d are: \n", n);
	while (counter < n)
	{
		printf("%d", Fn);
		printf("\n");
		Fn = Fn1 + Fn2;
		if (counter % 2 == 0)
			Fn1 = Fn;
		else
			Fn2 = Fn;
		counter++;
	}
}
*/
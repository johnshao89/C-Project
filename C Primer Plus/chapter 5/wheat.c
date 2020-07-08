#include <stdio.h>

int main(void)
{
    int count=1;
    double current_wheat, total_wheat;
    current_wheat=total_wheat=1;
    while (count <64)
        {
            current_wheat = current_wheat*2;
            total_wheat = total_wheat + current_wheat;
            count = count +1;
        }
    printf("The total wheat is %e\n",total_wheat);
    return 0;
    
}
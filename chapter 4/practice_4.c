#include <stdio.h>

int main(void)
{
    float file_size, download_speed, download_time;
    printf("Please enter the download speed, unit is megabits(Mb): ");
    scanf("%f", &download_speed);
    printf("Please enter the file size to be downloaded, unit is megabytes(MB):");
    scanf("%f", &file_size);
    download_time = file_size*8.0/download_speed;
    printf("At %f megabits per second, a file of %f megabytes downloads in %.2f seconds.",download_speed,
    file_size,download_time);
    return 0;
}
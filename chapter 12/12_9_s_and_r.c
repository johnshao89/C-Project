unsigned long int next =1;
unsigned int srand1(unsigned seed)
{
    next = seed;
}

unsigned int rand1(void)
{
    next = next *1103515245 +12345;
    return (unsigned int)(next/65536)%32768;
}
#include <unistd.h>

int main()
{
	char a = 15;
	write(1, &a, 1);
	return (0);
}

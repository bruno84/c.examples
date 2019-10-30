#include <time.h>
#include <stdio.h>
#include <string.h>

int main()
{
	time_t timeSec = time(NULL);
	printf("timeSec : %d\n", timeSec);
	
    char* timeStr = ctime(&timeSec);
    printf("timeStr : %s\n", timeStr);
	
	return;
}


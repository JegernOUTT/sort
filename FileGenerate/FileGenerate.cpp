#include <cstdlib>
#include <stdio.h>
#include <wchar.h>

#define MIN_SYMBOL_CODE 0x0041
#define MAX_SYMBOL_CODE 0x005A
#define MIN_STRING_SIZE 50
#define MAX_STRING_SIZE 100
#define FILE_SIZE 50000000000l

int main()
{
    FILE *fp;
    fp = fopen64("test.txt", "a");

    wchar_t *tmp = (wchar_t*)malloc(sizeof(wchar_t) * 500);
	
    for(int j = 0; j < FILE_SIZE; j++)
    {
	int n = MIN_STRING_SIZE + (rand() % (MAX_STRING_SIZE - MIN_STRING_SIZE));
        for (int i = 0; i < n; i++)
        {
            tmp[i] =  MIN_SYMBOL_CODE + (rand() % (MAX_SYMBOL_CODE - MIN_SYMBOL_CODE));            
        }
	fputws(tmp, fp);
        fputwc('\n', fp);
	for (int i = 0; i < n; i++)
        {
            tmp[i] =  0;            
        }
    }

   free(tmp);
   fclose(fp);

   exit(0);
}



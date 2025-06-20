
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include  <consoleapi.h>



int parseFile(const char* file_name);
void someFunction(bool fail1, bool fail2);

typedef struct {
	int x;
	int y;
} point_t;

typedef struct {
	point_t center;
	int radius;
} circle_t;

typedef struct {
	point_t start;
	point_t end;
} line_t;

void bar();

int nnn;

BOOL WINAPI ConsoleCtrlHandler(DWORD CtrlType)
{
	if (CtrlType== CTRL_C_EVENT)
	{
		printf("Control+C");
		return TRUE;
	}
	return FALSE;
}


int main(int argc, char** argv) {
	// https://learn.microsoft.com/en-us/windows/console/setconsolectrlhandler?redirectedfrom=MSDN
	SetConsoleCtrlHandler(ConsoleCtrlHandler, TRUE);

	putchar(208);
	putchar(186);

	int c;
	while ((c=getchar())!=EOF)
	{
		putchar(c);
	}

	return 0;
	

	//int c = getchar();
	//while (c!=EOF)
	//{
	//	putchar(c);
	//	c = getchar();
	//}

	exit(0);

	for (int fahr = 0; fahr <= 300; fahr=fahr+20)
	{
		printf("%3d%6.1f\n", fahr, (5.f / 9.f) * (fahr - 32));
	}

	
	//someFunction(false,true);

	/*const char* file = "keywords.txt";
	int r = parseFile(file);

	printf("parseFile returns %d\n", r);*/

	return(0);
}


void test_time()
{
	time_t tictoc = time(NULL);
	printf("The time is now %lld\n", tictoc);

	char buffer[50];
	_ctime64_s(buffer, 50, &tictoc);
	printf("The time is now %s\n", buffer);

	struct tm today;
	errno_t _ = localtime_s(&today, &tictoc);
	printf("Heutiges Datum: %d.%d.%d\n",
		today.tm_mday,
		today.tm_mon + 1,
		today.tm_year + 1900);
}


void someFunction(bool fail1, bool fail2) {
	if (fail1)
	{
		printf("fail 1\n");
		goto cleanup1;
	}
	if (fail2)
	{
		printf("fail 2\n");
		goto cleanup2;
	}
	printf("main functionality\n");
cleanup2:
	printf("cleanup 2\n");
cleanup1:
	printf("cleanup 1\n");
}

int searchFileForKeywords(FILE* file_pointer, char* buffer, int BUFFER_SIZE)
{
	/* parse file content*/
	int NO_KEYWORD_FOUND = 2;
	int return_value = NO_KEYWORD_FOUND;
	int KEYWORD_ONE_FOUND_FIRST = 3;
	int KEYWORD_TWO_FOUND_FIRST = 4;
	while (fgets(buffer, BUFFER_SIZE, file_pointer) != NULL)
	{
		//printf("%s", buffer);
		if (strcmp("KEYWORD_ONE\n", buffer) == 0)
		{
			return_value = KEYWORD_ONE_FOUND_FIRST;
			break;
		}
		if (strcmp("KEYWORD_TWO\n", buffer) == 0)
		{
			return_value = KEYWORD_TWO_FOUND_FIRST;
			break;
		}
	}
	return return_value;
}


int parseFile(const char* file_name) {
	int BUFFER_SIZE = 256;
	int ERROR_ = 1;


	int return_value = ERROR_;

	assert(file_name != NULL && "Filename is NULL");

	FILE* file_pointer = file_pointer = fopen(file_name, "r");

	if (!file_pointer)
		return return_value;

	char* buffer = 0;
	if ((buffer = (char*)malloc(BUFFER_SIZE)))
	{
		return_value = searchFileForKeywords(file_pointer, buffer, BUFFER_SIZE);
		free(buffer);
	}
	int _ = fclose(file_pointer);

	return return_value;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

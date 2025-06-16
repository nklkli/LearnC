#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int parseFile(const char* file_name);


int main() {

	const char* file = NULL;
	int r = parseFile(file);

	printf("parseFile returns %d\n", r);

	return(0);
}


void test_time()
{
	time_t tictoc = time(nullptr);
	printf("The time is now %lld\n", tictoc);

	char buffer[50];
	_ctime64_s(buffer, &tictoc);
	printf("The time is now %s\n", buffer);

	struct tm today;
	errno_t _ = localtime_s(&today, &tictoc);
	printf("Heutiges Datum: %d.%d.%d\n",
		today.tm_mday,
		today.tm_mon + 1,
		today.tm_year + 1900);
}


int parseFile(const char* file_name) {
	int BUFFER_SIZE = 256;
	int ERROR = 1;
	int NO_KEYWORD_FOUND = 2;
	int KEYWORD_ONE_FOUND_FIRST = 3;
	int KEYWORD_TWO_FOUND_FIRST = 4;

	int return_value = ERROR;

	assert(file_name != nullptr && "Filename is NULL");


	FILE* file_pointer = 0;
	if ((file_pointer = fopen(file_name, "r")))
	{
		char* buffer = 0;
		if ((buffer = (char*)malloc(BUFFER_SIZE)))
		{
			/* parse file content*/
			return_value = NO_KEYWORD_FOUND;
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
			free(buffer);
		}
		int _ = fclose(file_pointer);

	}
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

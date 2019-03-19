#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "util.h"
#include "heap.h"

using namespace std;

int nextCommand(int *i, int *v, int *f)	// this method takes input from the command line and formats it properly for the main class
{
	char c;
	while (1) {
		scanf("%c", &c);
		c = toupper(c);

		if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		if (c == 'S' || c == 'R' || c == 'W') {
			break;
		}
		if (c == 'C')
		{
			scanf("%d", i);
			break;
		}
		if (c == 'I')
		{
			scanf("%d", f); scanf("%d", v);
			break;
		}
		if (c == 'D')
		{
			scanf("%d", f);
			break;
		}
		if (c == 'K' || c == 'k') {
			scanf("%d", f); scanf("%d", i); scanf("%d", v);
			break;
		}

		printf("Invalid Command\n");
	}
	return c;
}
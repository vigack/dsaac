#pragma once
#include "dutil.h"
#include <stdio.h>
#include <string.h>

void *checked_malloc(int len) {
	void *p = malloc(len);
	if (!p) {
		fatal("\nOut of memory!\n");
	}
	return p;
}

void fatal(string msg) {
	fprintf(stderr, msg);
	exit(1);
}

string String(char *s) {
	string p = checked_malloc(strlen(s) + 1);
	strcpy(p, s);
	return p;
}

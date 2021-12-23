#pragma once
#include "stdafx.h"
#include "Log.h"

#define max_word 1000
#define size_word 20

const char Separators[] = { " ><%,;(){}=+-*/|~" };

void Cleaning(char source[], int size, Log::LOG logfile);
char** SeparateText(char source[], int size);

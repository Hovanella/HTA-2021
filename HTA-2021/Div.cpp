#include "Div.h"

void CleanCode(char source[], int size, Log::LOG logfile) {
	int count = 0;
	bool is_Literal_find = false;

	for (int i = 0; i < size; i++) {
		if (source[i] == '\'' || source[i] == '\"') {
			is_Literal_find = !is_Literal_find;
			count++;
		}

		if ((source[i] == ' ') && !is_Literal_find) {
			for (int j = 0; j < sizeof(Separators) - 1; j++) {
				if (source[i + 1] == Separators[j] || source[i - 1] == Separators[j] || i == 0) {
					for (int k = i; k < size; k++) {
						source[k] = source[k + 1];
					}
					i--;
					break;
				}
			}
		}
	}

	if (count % 2 != 0)
		Log::WriteError(logfile, Error::geterror(300));

	//ÓÄÀËÈÒÜ ÂÛÂÎÄ
	for (int i = 0; i < size; i++)
	{
		std::cout << source[i];
	}
	std::cout << std::endl;
}

char** TextSeparation(char source[], int size)
{
	char** word = new char* [max_word];

	for (int i = 0; i < max_word; i++) {
		word[i] = new char[size_word] {NULL};
	}

	bool is_separator_find, is_literal_find = false;
	int j = 0;

	for (int i = 0, k = 0; i < size - 1; i++, k++) {
		is_separator_find = false;

		if (source[i] == '\'' || source[i] == '\"') is_literal_find = !is_literal_find;

		for (int t = 0; t < sizeof(Separators) - 1; t++) {
			if (source[i] == Separators[t] && !is_literal_find) {
				is_separator_find = true;
				if (word[j][0] != NULL) {
					word[j++][k] = '\0';
					k = 0;
				}
				if (Separators[t] == ' ') {
					k = -1;
					break;
				}
				word[j][k++] = Separators[t];
				word[j++][k] = '\0';
				k = -1;
				break;
			}
		}

		if (!is_separator_find) word[j][k] = source[i];
	}

	word[j] = NULL;
	for (int i = 0; i < j; i++) {
		if (!strcmp((char*)word[i], "")) return NULL;
	}

	return word;
}
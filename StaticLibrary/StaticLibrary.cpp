#include <iostream>
#include <Windows.h>

#pragma warning(disable: 4996)

extern "C" {
	void BREAKL() {
		std::cout << std::endl;
	}

	void OutputInt(int a) {
		std::cout << a;
	}

	void OutputStr(char* ptr) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr) {
			std::cout << std::endl;
			return;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
	}

	void ShowChar(char* ptr) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr) {
			std::cout << std::endl;
			return;
		}
		std::cout << ptr[0];
	}
	void ShowCharLine(char* ptr) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr) {
			std::cout << std::endl;
			return;
		}
		std::cout << ptr[0] << std::endl;
	}

	void OutputIntLn(int a) {
		std::cout << a << std::endl;
	}

	void OutputStrLn(char* ptr) {
		OutputStr(ptr);
		std::cout << std::endl;
	}

	int destiny(int leftBorder, int rightBorder) {
		return leftBorder + (rand() % ((rightBorder - leftBorder) + 1));
	}

	int findSymb(char* string, char* symb) {
		if (string == nullptr || symb == nullptr)
			return -1;

		char symbol = symb[0];

		for (int i = 0; string[i] != '\0'; i++)
			if (string[i] == symbol) return i;

		return -1;
	}
}
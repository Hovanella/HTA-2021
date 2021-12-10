#include "stdafx.h"
#include "IT.h"
#include "Error.h"
#include "Parm.h"
using namespace std;

namespace IT {
	IdTable Create(int size) {
		IdTable* table = new IdTable;
		if (size < TI_MAXSIZE) throw ERROR_THROW(203);
		table->maxsize = size;
		table->size = 0;
		table->table = new Entry[size];
		return *table;
	}

	void Add(IdTable& idtable, Entry entry) {
		if (idtable.size + 1 > idtable.maxsize) throw ERROR_THROW(204);

		idtable.table[idtable.size] = entry;
		idtable.size++;
	}

	Entry GetEntry(IdTable& idtable, int n) {
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE]) {
		for (int i = 0; i < idtable.size; i++) {
			char buffer[ID_MAXSIZE];
			strcpy(buffer, idtable.table[i].id);
			if (strcmp(buffer, id) == 0) return i;
		}

		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable) {
		delete[] idtable.table;
	}
}
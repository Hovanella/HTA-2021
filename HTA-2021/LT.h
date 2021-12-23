#pragma once
#include "Error.h"
#include "Parm.h"
#define LEXEMA_FIXSIZE	1
#define LT_MAXSIZE		4096
#define LT_TI_NULLIDX	0xffffffff
#define LEX_INT			't'
#define LEX_STRING		't'
#define LEX_CHAR        't'
#define LEX_BOOL		't'
#define LEX_ID			'i'
#define LEX_LITERAL		'l'
#define LEX_MINOR	    'f'
#define LEX_DEFINE		'd'
#define LEX_GIVE		'g'
#define LEX_SHOW		'o'
#define LEX_MAJOR		'm'
#define LEX_SEMICOLON	';'
#define LEX_COMMA		','
#define LEX_LEFTBRACE	'{'
#define LEX_RIGHTBRACE  '}'
#define LEX_LEFTTHESIS	'('
#define LEX_RIGHTTHESIS	')'
#define LEX_PLUS		'v'
#define LEX_MINUS		'v'
#define LEX_STAR		'v'
#define LEX_DIRSLASH	'v'
#define LEX_OPERATOR	'v'
#define LEX_EQUAL		'='
#define LEX_CONTINUE    'u'
#define LEX_VOID	    'p'
#define LEX_IF		    'w'
#define LEX_ELSE		'!'
#define LEX_SHOWBR		'b'
#define LEX_CALL        '@'

#define LEX_TYPE 't'
#define LEX_OPERATOR 'v'

namespace LT {
	enum operations {
		ONOT = -1,
		OPLUS,
		OMINUS,
		OMUL,
		ODIV,
		OMOD,
		OMORE,
		OLESS,
		OEQU,
		ONEQU
	};

	struct Entry {
		char lexema;
		int line;
		int idxTI;
		int priority;
		operations op;
	};

	struct LexTable {
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);
	void Add(LexTable& lextable, Entry entry);
	Entry GetEntry(LexTable& lextable, int n);
	void Delete(LexTable& lextable);
	Entry WriteEntry(Entry& entry, char lexema, int indx, int line);
	void ShowTable(LexTable lextable, Parm::PARM parm);
}
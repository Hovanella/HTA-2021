#pragma once
#include "stdafx.h"
#include "Log.h"
#include "LexAnalisys.h"
#include "IT.h"

namespace Semantic {
	bool Analyze(Lex::LEX lex, Log::LOG log);

	struct func {
		int parm_count = 0;
		std::string id;
		IT::IDDATATYPE parmType[100];
	};
}
#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include "Out.h"
#include "FST.h"
#include "Polish.h"
#include "LexAnalisys.h"
#include "MFST.h"
#include "GRB.h"
#include "SemAnalysis.h"
#include "Generation.h"

using namespace std;

int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "RUS");

	Log::LOG log = Log::INITLOG;

	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);

		In::IN in = In::Getin(parm);
		Log::WriteIn(log, in);

		Lex::LEX lex = Lex::LexAnaliz(log, in);

		WriteIdTableLog(lex.idtable, log);
		WriteLexTableLog(lex.lextable, log);

		MFST::check_syntax(lex, log, *log.stream);

		if (!Semantic::Analyze(lex, log)) {
			std::cout << "Semantic errors. Check log file to get more info";
			exit(-1);
		}

		Polish::startPolish(lex);
		Lex::Synchronization(lex);
		Gen::Generator Gener(lex.lextable, lex.idtable, parm.out);
		Log::Close(log);
	}
	catch (Error::ERROR e) {
		Log::WriteError(log, e);
	}
}
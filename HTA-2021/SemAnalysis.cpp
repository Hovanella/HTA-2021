#include "SemAnalysis.h"

namespace Semantic {
	bool Analyze(Lex::LEX lex, Log::LOG log) {
		bool is_ok = true;
		bool is_function_unic = true;

		int j = 0;

		func functions_id[100] = { 0 };
		func current_function;

		func dest_func = { 2,"destiny", {IT::INT,IT::INT} };
		func findSymb_func = { 2,"findSymb", {IT::STR,IT::CHAR} };

		int functions_counter = -1;

		int counter = 0;
		int k;

		std::vector<std::string> variables_id;

		for (int i = 0; i < lex.lextable.size; i++) {
			switch (lex.lextable.table[i].lexema) {
			case LEX_ID:

				if (lex.lextable.table[i + 1].lexema == LEX_LEFTTHESIS && lex.idtable.table[lex.lextable.table[i].idxTI].idtype == IT::V) {
					Log::WriteError(log, Error::geterrorin(311, lex.lextable.table[j].line, -1));
					is_ok = false;
				}
				else
					if (lex.lextable.table[i - 1].lexema != LEX_MINOR && lex.lextable.table[i - 1].lexema != LEX_VOID && lex.idtable.table[lex.lextable.table[i].idxTI].iddatatype == IT::PROC) {
						j = i + 1;

						for (k = 0; k <= functions_counter; k++) {
							if (lex.idtable.table[lex.lextable.table[i].idxTI].id == functions_id[k].id)
								break;
						}

						while (lex.lextable.table[j].lexema != LEX_LEFTTHESIS) {
							j++;
						}
						j++;

						counter = 0;
						while (lex.lextable.table[j].lexema != LEX_RIGHTTHESIS) {
							if (lex.lextable.table[j].lexema == LEX_ID || lex.lextable.table[j].lexema == LEX_LITERAL) {
								if (counter == functions_id[k].parm_count) {
									Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
									is_ok = false;
									break;
								}
								if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != functions_id[k].parmType[counter]) {
									Log::WriteError(log, Error::geterrorin(309, lex.lextable.table[j].line, -1));
									is_ok = false;
								}
								counter++;
							}
							j++;
						}
						if (counter != functions_id[k].parm_count) {
							Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
							is_ok = false;
						}
					}
				continue;
			case LEX_DEFINE:
				if (lex.lextable.table[i + 2].lexema == LEX_ID)
					if (std::count(variables_id.begin(), variables_id.end(), lex.idtable.table[lex.lextable.table[i + 2].idxTI].id)) {
						Log::WriteError(log, Error::geterrorin(316, lex.lextable.table[j].line, -1));
						is_ok = false;
					}
					else
						variables_id.push_back(lex.idtable.table[lex.lextable.table[i + 2].idxTI].id);
				continue;

			case LEX_EQUAL:
				j = i + 1;
				for (j; lex.lextable.table[j].lexema != LEX_SEMICOLON; j++) {
					switch (lex.lextable.table[j].lexema) {
					case LEX_ID:
					case LEX_LITERAL:
						if ((lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype)) {
							Log::WriteError(log, Error::geterrorin(312, lex.lextable.table[j].line, -1));
							is_ok = false;
						}
						continue;

					case LEX_LEFTTHESIS:
						if (lex.lextable.table[j - 1].lexema == LEX_ID && lex.idtable.table[lex.lextable.table[j - 1].idxTI].idtype == IT::F) {
							if (!strcmp(lex.idtable.table[lex.lextable.table[j - 1].idxTI].id, "findSymb") || !strcmp(lex.idtable.table[lex.lextable.table[j - 1].idxTI].id, "destiny")) {
								k = j - 1;
								while (lex.lextable.table[j].lexema != LEX_LEFTTHESIS) {
									j++;
								}
								j++;

								counter = 0;

								if (!strcmp(lex.idtable.table[lex.lextable.table[k].idxTI].id, "findSymb")) current_function = findSymb_func;
								else current_function = dest_func;

								while (lex.lextable.table[j].lexema != LEX_RIGHTTHESIS) {
									if (lex.lextable.table[j].lexema == LEX_ID || lex.lextable.table[j].lexema == LEX_LITERAL) {
										if (counter == current_function.parm_count) {
											Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
											is_ok = false;
											break;
										}
										if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != current_function.parmType[counter]) {
											Log::WriteError(log, Error::geterrorin(309, lex.lextable.table[j].line, -1));
											is_ok = false;
										}
										counter++;
									}
									j++;
								}
								if (counter != current_function.parm_count) {
									Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
									is_ok = false;
								}
							}
							else {
								for (k = 0; k <= functions_counter; k++) {
									if (lex.idtable.table[lex.lextable.table[j - 1].idxTI].id == functions_id[k].id)
										break;
								}

								while (lex.lextable.table[j].lexema != LEX_LEFTTHESIS) {
									j++;
								}
								j++;

								counter = 0;
								while (lex.lextable.table[j].lexema != LEX_RIGHTTHESIS) {
									if (lex.lextable.table[j].lexema == LEX_ID || lex.lextable.table[j].lexema == LEX_LITERAL) {
										if (counter == functions_id[k].parm_count) {
											Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
											is_ok = false;
											break;
										}
										if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != functions_id[k].parmType[counter]) {
											Log::WriteError(log, Error::geterrorin(309, lex.lextable.table[j].line, -1));
											is_ok = false;
										}
										counter++;
									}
									j++;
								}
								if (counter != functions_id[k].parm_count) {
									Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].line, -1));
									is_ok = false;
								}
							}
						}
						continue;
					case LEX_OPERATOR:
						if (lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype == IT::CHAR || lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype == IT::STR) {
							Log::WriteError(log, Error::geterrorin(317, lex.lextable.table[j].line, -1));
							is_ok = false;
						}
						switch (lex.lextable.table[j].op)
						{
						case LT::OMORE:
						case LT::OLESS:
						case LT::ONEQU:
						case LT::OEQU:
							Log::WriteError(log, Error::geterrorin(317, lex.lextable.table[j].line, -1));
							is_ok = false;
							break;
						default:
							break;
						}

						continue;
					}
				}

				continue;
			case LEX_MINOR:
			case LEX_VOID:
				is_function_unic = true;
				for (int k = 0; k < functions_counter; k++)
					if (functions_id->id == lex.idtable.table[lex.lextable.table[i + 1].idxTI].id) {
						Log::WriteError(log, Error::geterrorin(307, lex.lextable.table[i + 1].line, -1));
						is_ok = false;
						is_function_unic = false;
						break;
					}

				if (is_function_unic == true)
				{
					functions_counter++;

					current_function.id = lex.idtable.table[lex.lextable.table[i + 1].idxTI].id;
					current_function.parm_count = 0;

					j = i + 1;

					while (lex.lextable.table[j].lexema != LEX_LEFTTHESIS) {
						j++;
					}
					j++;

					while (lex.lextable.table[j].lexema != LEX_RIGHTTHESIS) {
						if (lex.lextable.table[j].lexema == LEX_ID) {
							current_function.parmType[current_function.parm_count] = lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype;
							current_function.parm_count++;
						}
						j++;
					}
					functions_id[functions_counter] = current_function;
				}

				if (lex.lextable.table[i].lexema == LEX_MINOR) {
					j = i + 1;
					int type = lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype;
					do {
						j++;
					} while ((lex.lextable.table[j].lexema != LEX_GIVE));
					if (lex.idtable.table[lex.lextable.table[j + 1].idxTI].iddatatype != type) {
						Log::WriteError(log, Error::geterrorin(314, lex.lextable.table[j].line, -1));
						is_ok = false;
					}
				}
			}
		}

		return is_ok;
	}
}
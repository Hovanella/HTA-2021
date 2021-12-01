#include"Log.h"
#include"LT.h"
#include"IT.h"
using namespace std;

namespace Log {
	LOG getlog(wchar_t logfile[]) {
		LOG log;
		log.stream = new std::ofstream;
		log.stream->open(logfile);
		if (log.stream->fail())
			throw ERROR_THROW(112);

		wcscpy_s(log.logfile, logfile);
		return log;
	}

	void WriteLine(LOG log, const char* c, ...) {
		const char** ptr = &c;
		while (*ptr != "") {
			*log.stream << *ptr;
			ptr++;
		}

		*log.stream << std::endl;
	}

	void WriteLine(LOG log, const wchar_t* c, ...) {
		const wchar_t** ptr = &c;

		char temp[100];

		while (*ptr != L"") {
			wcstombs(temp, *ptr++, sizeof(temp));
			*log.stream << temp;
		}
		*log.stream << std::endl;
	}

	void WriteLog(LOG log) {
		time_t rawtime;
		tm current_time;
		char temp[100];

		time(&rawtime);
		localtime_s(&current_time, &rawtime);

		*log.stream << "\n|---------- Отчёт ------------|\n";
		strftime(temp, 100, "| Время: %d.%m.%Y, %H:%M:%S |\n", &current_time);
		*log.stream << temp <<
			"|-----------------------------|\n";
	}

	void WriteParm(LOG log, Parm::PARM parm) {
		char in_text[PARM_MAX_SIZE];
		char out_text[PARM_MAX_SIZE];
		char log_text[PARM_MAX_SIZE];

		wcstombs(in_text, parm.in, PARM_MAX_SIZE);
		wcstombs(out_text, parm.out, PARM_MAX_SIZE);
		wcstombs(log_text, parm.log, PARM_MAX_SIZE);

		*log.stream << "\n ---- Параметры ---- \n\n-in: " << in_text
			<< "\n-out: " << out_text
			<< "\n-log: " << log_text << std::endl;
	}

	void WriteIn(LOG log, In::IN in) {
		*log.stream << "\n ---- Информация ----"
			<< "\n\nКоличество символов: " << in.size
			<< "\nКоличество строк: " << in.lines
			<< "\nКоличество пропущенных символов: " << in.ignor << std::endl;
	}

	void WriteError(LOG log, Error::ERROR error) {
		if (log.stream) {
			*log.stream << "\nОшибка " << error.id
				<< ": " << error.message
				<< "\nСтрока ошибки " << error.inext.line
				<< " позиция ошибки " << error.inext.col << std::endl;
			//Close(log);
		}
		else {
			std::cout << "\nОшибка " << error.id
				<< ": " << error.message
				<< "\nСтрока ошибки " << error.inext.line
				<< "позиция ошибки " << error.inext.col << std::endl;
		}
	}

	void WriteLexTableLog(LT::LexTable& lextable, LOG log) {
		int i;
		*log.stream << "\n\t\tТаблица лексем" << std::endl;
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
		*log.stream << "   #" << " | " << "Лексема" << std::setfill(' ') << std::setw(20) << ' ' << std::left
			<< " | " << "Строка" << std::setw(21) << ' ' << std::left << " | " << "Индекс в ТИ" << std::endl;
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
		for (i = 0; i < lextable.size; i++) {
			char op = ' ';
			switch (lextable.table[i].op) {
			case LT::operations::OPLUS:
				op = '+';
				break;
			case LT::operations::OMINUS:
				op = '-';
				break;
			case LT::operations::OMUL:
				op = '*';
				break;
			case LT::operations::ODIV:
				op = '/';
				break;
			case LT::operations::OMOD:
				op = '%';
				break;
			}
			*log.stream << std::setfill('0') << std::setw(4) << std::right << i << " | " << std::setfill(' ')
				<< std::setw(24) << std::left << lextable.table[i].lexema << op << "   | " << std::setw(24) << std::left
				<< lextable.table[i].line << "    | ";
			if (lextable.table[i].idxTI == LT_TI_NULLIDX)
				*log.stream << "-" << std::endl;
			else
				*log.stream << std::setw(23) << lextable.table[i].idxTI << std::endl;
		}
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
		*log.stream << "\tВсего лексем: " << i << std::endl;
		*log.stream << std::setfill('-') << std::setw(90) << '-' << std::endl;
	}

	void WriteIdTableLog(IT::IdTable& idtable, LOG log) {
		int i, j, numberOP = 0;
		*log.stream << "\n";
		*log.stream << setfill('-') << setw(87) << '-' << endl;
		*log.stream << "   #" << " | " << "Идентификатор" << " | " << "Тип данных" << " | " << "Тип идентификатора"
			<< " | " << "Индекс в ТЛ" << " | " << "Значение" << endl;
		*log.stream << setw(87) << '-' << endl;

		for (i = 0, j = 0; i < idtable.size; i++, j++) {
			*log.stream << setfill('0') << setw(4) << right << j << " | ";
			*log.stream << setfill(' ') << setw(13) << left << idtable.table[i].id << " | ";

			if (idtable.table[i].idtype == IT::OP) *log.stream << setw(10) << left << "-" << " | ";
			else {
				switch (idtable.table[i].iddatatype) {
				case IT::IDDATATYPE::INT:
					*log.stream << setw(10) << left;
					*log.stream << "int" << " | ";
					break;
				case  IT::IDDATATYPE::STR:
					*log.stream << setw(10) << left;
					*log.stream << "string" << " | ";
					break;
				case  IT::IDDATATYPE::BOOL:
					*log.stream << setw(10) << left;
					*log.stream << "bool" << " | ";
					break;
				case  IT::IDDATATYPE::CHAR:
					*log.stream << setw(10) << left;
					*log.stream << "char" << " | ";
					break;
				default:
					*log.stream << setw(10) << left << "unknown" << " | ";
					break;
				}
			}

			switch (idtable.table[i].idtype) {
			case 	IT::IDTYPE::V: *log.stream << setw(18) << left << "переменная" << " | "; break;
			case 	IT::IDTYPE::F: *log.stream << setw(18) << left << "функция" << " | "; break;
			case 	IT::IDTYPE::P: *log.stream << setw(18) << left << "параметр" << " | "; break;
			case 	IT::IDTYPE::L: *log.stream << setw(18) << left << "литерал" << " | "; break;
			case 	IT::IDTYPE::OP:
				*log.stream << setw(18) << left << "оператор" << " | ";
				numberOP++;
				break;
			default: *log.stream << setw(18) << left << "unknown" << " | "; break;
			}
			*log.stream << setw(11) << left << idtable.table[i].idxFirstLE << " | ";

			if (idtable.table[i].iddatatype == IT::IDDATATYPE::INT && (idtable.table[i].idtype == IT::IDTYPE::V || idtable.table[i].idtype == IT::IDTYPE::L))
				*log.stream << setw(18) << left << idtable.table[i].value.vint;
			else if (idtable.table[i].iddatatype == IT::IDDATATYPE::STR && (idtable.table[i].idtype == IT::IDTYPE::V || idtable.table[i].idtype == IT::IDTYPE::L))
				*log.stream << "[" << idtable.table[i].value.vstr.len << "]\"" << idtable.table[i].value.vstr.str << "\"";
			else if (idtable.table[i].iddatatype == IT::IDDATATYPE::BOOL && (idtable.table[i].idtype == IT::IDTYPE::V || idtable.table[i].idtype == IT::IDTYPE::L))
				*log.stream << setw(18) << left << (idtable.table[i].value.vint == 0 ? "false" : "true");
			else if (idtable.table[i].iddatatype == IT::IDDATATYPE::CHAR && (idtable.table[i].idtype == IT::IDTYPE::V || idtable.table[i].idtype == IT::IDTYPE::L))
				*log.stream << idtable.table[i].value.vchar;

			else *log.stream << "-";
			*log.stream << endl;
		}

		*log.stream << setfill('-') << setw(87) << "-" << endl;
		*log.stream << "Количество идентификаторов: " << i << endl;
		*log.stream << setw(87) << "-" << endl;
	}

	void Close(LOG log) {
		log.stream->close();
		delete log.stream;
	}
}
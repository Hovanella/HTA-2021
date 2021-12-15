#include"stdafx.h"
#include"Parm.h"
#include"Error.h"

namespace Parm {
	PARM getparm(int argc, wchar_t* argv[]) {
		PARM parm;

		bool is_out_found = false;
		bool is_log_found = false;
		bool is_in_found = false;

		for (int i = 1; i < argc; i++) {
			if (wcslen(argv[i]) > PARM_MAX_SIZE)
				throw ERROR_THROW(104);

			if (wcsstr(argv[i], PARM_IN)) {
				wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));
				is_in_found = true;
			}

			if (wcsstr(argv[i], PARM_OUT)) {
				wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));
				is_out_found = true;
			}

			if (wcsstr(argv[i], PARM_LOG)) {
				wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));
				is_log_found = true;
			}
		}

		if (!is_in_found) throw ERROR_THROW(100);
		if (!is_out_found) {
			wcscpy_s(parm.out, parm.in);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}
		if (!is_log_found) {
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
}
#include"Error.h"
namespace Error {
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Недопустимый код ошибки"),
		ERROR_ENTRY(1, "Системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111, "Запрещённый символ в исходном файле (-in)"),
		ERROR_ENTRY(112, "Ошибка при создании файла протокола (-log)"),
		ERROR_ENTRY_NODEF(113), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "Ошибка лексического анализа: Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(201, "Ошибка лексического анализа: Превышен размер таблицы лексем"),
		ERROR_ENTRY(202, "Ошибка лексического анализа: Переполнение таблицы лексем"),
		ERROR_ENTRY(203, "Ошибка лексического анализа: Превышен размер таблицы идентификаторов"),
		ERROR_ENTRY(204, "Ошибка лексического анализа: Переполнение таблицы идентификаторов"),
		ERROR_ENTRY(205, "Ошибка лексического анализа: Неизвестная последовательность символов"),
		ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Ошибка семантического анализа: Имеется не закрытый строковый литерал"),							// -
		ERROR_ENTRY(301, "Ошибка семантического анализа: Имеется более одной точки входа в main"),						// +
		ERROR_ENTRY(302, "Ошибка семантического анализа: Не имеется точки входа в main"),									// +
		ERROR_ENTRY(303, "Ошибка семантического анализа: Превышен размер строкового литерала"),							// -
		ERROR_ENTRY(304, "Ошибка семантического анализа: Объявление переменной без ключевого слова let"),					// -
		ERROR_ENTRY(305, "Ошибка семантического анализа: Необъявленный идентификатор"),									// -
		ERROR_ENTRY(306, "Ошибка семантического анализа: Объвление переменной без указания типа"),						// -
		ERROR_ENTRY(307, "Ошибка семантического анализа: Попытка реализовать существующую функцию"),						// +
		ERROR_ENTRY(308, "Ошибка семантического анализа: Объявление функции без указания типа"),							// -
		ERROR_ENTRY(309, "Ошибка семантического анализа: Несовпадение типов передаваемых параметров функции"),			// -
		ERROR_ENTRY(310, "Ошибка семантического анализа: Несоответствие арифметических операторов"),						// -
		ERROR_ENTRY(311, "Ошибка семантического анализа: Невозможно деление на ноль"),									// -
		ERROR_ENTRY(312, "Ошибка семантического анализа: Несоответсвие типов данных"),									// +
		ERROR_ENTRY(313, "Ошибка семантического анализа: Несоответсвие открытых и закрытых скобок в выражении"),			// -
		ERROR_ENTRY(314, "Ошибка семантического анализа: Функция возвращает неверный тип данных"),						// +
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};
	ERROR geterror(int id) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			return errors[id];
		}
		else {
			return errors[0];
		}
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else {
			return errors[0];
		}
	}
}
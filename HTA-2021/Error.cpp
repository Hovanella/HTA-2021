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
		ERROR_ENTRY(112, "Ошибка создания файла протокола (-log)"),
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
		ERROR_ENTRY(205, "Ошибка лексического анализа: Переполнение строкового литерала"),
		 ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
			ERROR_ENTRY(300, "Ошибка семантического анализа: Имеется не закрытый строковый литерал"),
		ERROR_ENTRY(301, "Ошибка семантического анализа: Имеется более одной точки входа в main"),
		ERROR_ENTRY(302, "Ошибка семантического анализа: Не имеется точки входа в main"),
		ERROR_ENTRY(303, "Ошибка семантического анализа: Превышен размер строкового литерала"),
		ERROR_ENTRY(304, "Ошибка семантического анализа: Объявление переменной define"),
		ERROR_ENTRY_NODEF(305),
		ERROR_ENTRY_NODEF(306),
		ERROR_ENTRY(307, "Ошибка семантического анализа: Попытка реализовать существующую функцию"),
		ERROR_ENTRY_NODEF(308),
		ERROR_ENTRY(309, "Ошибка семантического анализа: Несовпадение типов передаваемых параметров функции"),
		ERROR_ENTRY(310, "Ошибка семантического анализа: Несоответствие арифметических операторов"),
		ERROR_ENTRY(311, "Ошибка семантического анализа: Необъявленная процедура или функция "),
		ERROR_ENTRY(312, "Ошибка семантического анализа: Несоответсвие типов данных"),
		ERROR_ENTRY_NODEF(313),
		ERROR_ENTRY(314, "Ошибка семантического анализа: Функция возвращает неверный тип данных"),
		ERROR_ENTRY(315, "Ошибка семантического анализа: Несоответсвие количества передаваемых параметров функции"),
		ERROR_ENTRY(316, "Ошибка семантического анализа: Переобъявление переменной"),
		ERROR_ENTRY(317, "Ошибка семантического анализа: Неправильное использование операторов в выражении"),

		ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319),
		ERROR_ENTRY_NODEF10(320), ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360),
		ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400),
		ERROR_ENTRY_NODEF10(500), ERROR_ENTRY_NODEF10(510), ERROR_ENTRY_NODEF10(520), ERROR_ENTRY_NODEF10(530), ERROR_ENTRY_NODEF10(540),
		ERROR_ENTRY_NODEF10(550), ERROR_ENTRY_NODEF10(560), ERROR_ENTRY_NODEF10(570), ERROR_ENTRY_NODEF10(580), ERROR_ENTRY_NODEF10(590),
		ERROR_ENTRY(600, "Ошибка синтаксического анализа: Неправильная структура программы"),
		ERROR_ENTRY(601, "Ошибка синтаксического анализа: Отсутствует список параметров функции"),
		ERROR_ENTRY(602, "Ошибка синтаксического анализа: Ошибка в параметрах функции"),
		ERROR_ENTRY(603, "Ошибка синтаксического анализа: Отсутствует тело функции"),
		ERROR_ENTRY(604, "Ошибка синтаксического анализа: Неверная конструкция в теле функции"),
		ERROR_ENTRY(605, "Ошибка синтаксического анализа: Ошибка в условном выражении"),
		ERROR_ENTRY(606, "Ошибка синтаксического анализа: Ошибка в вызове функции"),
		ERROR_ENTRY(607, "Ошибка синтаксического анализа: Ошибка в арифметическом выражении"),
		ERROR_ENTRY(608, "Ошибка синтаксического анализа: Ошибка в списке параметров при вызове функции"),
		ERROR_ENTRY(609, "Ошибка синтаксического анализа: Ошибка в арифметическом выражении"),
		ERROR_ENTRY(610, "Ошибка синтаксического анализа: Неверная конструкция в теле цикла или условия"),
		ERROR_ENTRY_NODEF(611),ERROR_ENTRY_NODEF(612),ERROR_ENTRY_NODEF(613),
		ERROR_ENTRY_NODEF(614), ERROR_ENTRY_NODEF(615), ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617), ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
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
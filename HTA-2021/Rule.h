#pragma once
#include "GRB.h"
#define GRB_ERROR_SERIES 600
#define NS(n) GRB::Rule::Chain::N(n)
#define TS(n) GRB::Rule::Chain::T(n)
#define ISNS(n) GRB::Rule::Chain::isN(n)

namespace GRB {
	Greibach greibach(
		NS('S'), TS('$'),
		13,
		Rule(
			NS('S'), GRB_ERROR_SERIES + 0,   //Стартовый символ,очевидно ошибка здесь есть ошибка на старте
			5,
			Rule::Chain(6, TS('t'), TS('f'), TS('i'), NS('F'), NS('B'), NS('S')),
			Rule::Chain(5, TS('p'), TS('i'), NS('F'), NS('U'), NS('S')),
			Rule::Chain(4, TS('m'), TS('{'), NS('N'), TS('}')),
			Rule::Chain(5, TS('t'), TS('f'), TS('i'), NS('F'), NS('B')),
			Rule::Chain(4, TS('p'), TS('i'), NS('F'), NS('U'))
		),
		Rule(
			NS('F'), GRB_ERROR_SERIES + 1,  // Указание параметров функции
			2,
			Rule::Chain(3, TS('('), NS('P'), TS(')')), //Непустые параметры
			Rule::Chain(2, TS('('), TS(')'))  // Пустые параметры
		),
		Rule(
			NS('P'), GRB_ERROR_SERIES + 2, // Ограничения на сами параметры
			2,
			Rule::Chain(2, TS('t'), TS('i')),  // Последний параметр
			Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('P')) //Очередной параметр
		),
		Rule(
			NS('B'), GRB_ERROR_SERIES + 3, // ограничение на тело функции
			3,
			Rule::Chain(6, TS('{'), NS('N'), TS('r'), NS('I'), TS(';'), TS('}')),
			Rule::Chain(5, TS('{'), TS('r'), NS('I'), TS(';'), TS('}')),
			Rule::Chain(3, TS('{'), NS('N'), TS('}'))
		),
		Rule(
			NS('I'), GRB_ERROR_SERIES + 4, // Недопустимое выражение
			2,
			Rule::Chain(1, TS('i')), // Идентификатор
			Rule::Chain(1, TS('l'))  // Литерал
		),
		Rule(
			NS('U'), GRB_ERROR_SERIES + 5, //Отсутствует тело условия или цикла
			1,
			Rule::Chain(3, TS('{'), NS('N'), TS('}')) // Непустой цикл или условие
													  // Можно сделать пустой цикл                             !!!!!!!
		),
		Rule(
			NS('N'), GRB_ERROR_SERIES + 6, // Неверная инструкция в функции ( последние  10 - это последнее выражение в теле,  первые 10 - те же выражения,не являющиеся последними в теле

			20,
			Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('N')),  // Прим. let int a; и ещё какие-то выражения...
			Rule::Chain(7, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),  // Прим. lety int a = 10; и ещё какие-то выражения...
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')), // a = 12; и ещё какие-то выражения...
			Rule::Chain(8, TS('u'), TS('('), NS('R'), TS(')'), TS('{'), NS('X'), TS('}'), NS('N')), // цикл ( условие цикла ) { тело цикла } и ещё какие-то выражения;
			Rule::Chain(8, TS('w'), TS('('), NS('R'), TS(')'), TS('{'), NS('X'), TS('}'), NS('N')), // условие (условие условия) {тело условия} и ещё какие-то выражения
			Rule::Chain(12, TS('w'), TS('('), NS('R'), TS(')'), TS('{'), NS('X'), TS('}'), TS('!'), TS('{'), NS('X'), TS('}'), NS('N')), // условие (условие условия) { тело условия } else {тела else} и ещё какие-то выражения
			Rule::Chain(4, TS('o'), NS('I'), TS(';'), NS('N')), // write выводимое; и ещё какие-то выражения
			Rule::Chain(4, TS('b'), NS('I'), TS(';'), NS('N')), // writeln выводимое; и ещё какие-то выражения
			Rule::Chain(4, TS('r'), NS('E'), TS(';'), NS('N')), // return E; и ещё какие-то выражения                     !!!!!!!!!
			Rule::Chain(4, TS('i'), NS('K'), TS(';'), NS('N')), // прим. a K ; и ещё какие-то выражения

			Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
			Rule::Chain(6, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(7, TS('u'), TS('('), NS('R'), TS(')'), TS('{'), NS('X'), TS('}')),
			Rule::Chain(7, TS('w'), TS('('), NS('R'), TS(')'), TS('{'), NS('X'), TS('}')),
			Rule::Chain(11, TS('w'), TS('('), NS('R'), TS(')'), TS('{'), NS('X'), TS('}'), TS('!'), TS('{'), NS('X'), TS('}')),
			Rule::Chain(3, TS('o'), NS('I'), TS(';')),
			Rule::Chain(3, TS('b'), NS('I'), TS(';')),
			Rule::Chain(3, TS('r'), NS('E'), TS(';')),
			Rule::Chain(3, TS('i'), NS('K'), TS(';'))
		),
		Rule(
			NS('R'), GRB_ERROR_SERIES + 7, // Условное выражения цикла или условия          !!!!!!!!
			4,
			Rule::Chain(1, TS('i')), //
			Rule::Chain(3, TS('i'), TS('v'), TS('i')), // идентификатор
			Rule::Chain(3, TS('i'), TS('v'), TS('l')),
			Rule::Chain(3, TS('l'), TS('v'), TS('i'))
		),
		Rule(
			NS('K'), GRB_ERROR_SERIES + 8, // вызов функции
			2,
			Rule::Chain(3, TS('('), NS('W'), TS(')')), // ( параметры функции )    !!!!!!
			Rule::Chain(2, TS('('), TS(')')) // ()
		),
		Rule(  // Арифметическое выражение
			NS('E'), GRB_ERROR_SERIES + 9,
			8,
			Rule::Chain(1, TS('i')), // идентифекатор
			Rule::Chain(1, TS('l')),// литерал
			Rule::Chain(3, TS('('), NS('E'), TS(')')),//(арифметическое выражение)
			Rule::Chain(2, TS('i'), NS('K')),// идентифекатор и вызов функции    !!!!!!

			Rule::Chain(2, TS('i'), NS('M')),
			Rule::Chain(2, TS('l'), NS('M')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(3, TS('i'), NS('K'), NS('M'))
		),
		Rule(
			NS('W'), GRB_ERROR_SERIES + 10,   //  список параметров при вызове функция      !!!!!!!!!!!!
			4,
			Rule::Chain(1, TS('i')), // идентификатор
			Rule::Chain(1, TS('l')), // лексема
			Rule::Chain(3, TS('i'), TS(','), NS('W')), // идентификатор, и ещё-какие-то параметры
			Rule::Chain(3, TS('l'), TS(','), NS('W'))  // лексема и ещё какие-то параметры
		),
		Rule(                                      //Что-то из мат.выражений                   !!!!!!!!!
			NS('M'), GRB_ERROR_SERIES + 11,
			2,
			Rule::Chain(2, TS('v'), NS('E')), // оператор и мат.выражение
			Rule::Chain(3, TS('v'), NS('E'), NS('M')) // оператор, мат.выражение , и новое это правило
		),
		Rule(
			NS('X'), GRB_ERROR_SERIES + 12,  // тело цикла или условия
			14,
			Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('N')), // то же,что и в N
			Rule::Chain(7, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')), // то же,что и в N
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')), // идентификатор = арифмет. выражение и ещё какое-то выражение           !!!!!
			Rule::Chain(4, TS('o'), NS('I'), TS(';'), NS('N')),  // write идентификатор||лексема ; и ещё какое-то выражение
			Rule::Chain(4, TS('b'), NS('E'), TS(';'), NS('N')),  // writeln мат.выражеие ; и ещё какое-то выражение                     !!!!!
			Rule::Chain(4, TS('r'), NS('E'), TS(';'), NS('N')),  // return мат.выражение ; и ещё какое-то выражение
			Rule::Chain(4, TS('i'), NS('K'), TS(';'), NS('N')),  // идентификаторФункции вызов функции; и ещё какие-то выражения;

			Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
			Rule::Chain(6, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('o'), NS('I'), TS(';')),
			Rule::Chain(3, TS('b'), NS('I'), TS(';')),
			Rule::Chain(3, TS('r'), NS('E'), TS(';')),
			Rule::Chain(3, TS('i'), NS('K'), TS(';'))
		)
	);
}
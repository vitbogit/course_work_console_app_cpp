#include <iostream>
#include "structures_definition.h"
#include "additional_functions.h"
#include "group_delete.h"

using namespace std;


// Закрытие программы:
void console_menu_option_exit_programm(bus_station* bs) {


	cout << "\tВЫХОД ИЗ ПРОГРАММЫ\n\n";


	// Объявление переменных:
	string user_input; // Пользовательский ввод


	cout << "- Вы точно выходите (1 - выйти из программы, 2 - вернуться в меню)?\n";

		
	user_input = get_user_input_with_conditions(0, "is_1_or_2");

	// Возвращение в меню по решению пользователя:
	if (user_input == "2") {
		
		
		// Вернемся в меню
		return;


	} // Конец блока "Возвращение в меню по решению пользователя"


	// В случае односвязных списков
	if (bs->bus_station_type_of_list == '1') {


		// Удалим односвязный список автобусов и записи о нем в файле хранения бд:
		delete_all_data(bs->bus_station_buses_linear_singly_linked_list);


	}
	else { // В случае двухсвязных списков


		/// Удалим двухсвязный список автобусов и записи о нем в файле хранения бд:
		delete_all_data(bs->bus_station_buses_linear_doubly_linked_list);


	}

		

	// Выйдем из программы:
	exit(0);


} // Конец блока "Закрытие программы"
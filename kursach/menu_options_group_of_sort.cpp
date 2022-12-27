

#include "structures_definition.h"
#include "additional_functions.h"
#include <iostream>
#include "group_sort.h"

using namespace std;


// Сортировка по заданному условию:
void console_menu_option_sort_data(bus_station* bs) {

	cout << "\tСОРТИРОВКА\n\n";


	if (bs->bus_station_type_of_list == '1') {

		if (bs->bus_station_buses_linear_singly_linked_list->buses_first_bus == NULL) return; // Список пуст

		if (bs->bus_station_buses_linear_singly_linked_list->buses_first_bus->bus_next_bus == NULL) return; // В списке 1 элемент

	}
	else {

		if (bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus == NULL) return; // Список пуст

		if (bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus->bus_next_bus == NULL) return; // В списке 1 элемент

	}

	string user_input; // Пользовательский ввод

	int n = 7; // Число параметров вывода

	int choosen_option; // Выбранный параметр 

	string sort_mode; // Сортировка по убыванию или возрастанию

	cout << "- По каким условиям сортировать данные?\n";

	cout << "Направление (1)"
		<< " / " << "Номер рейса (2)"
		<< " / " << "Марка автобуса (3)"
		<< " / " << "Время отправления (4)"
		<< " / " << "ФИО Водителя (5)"
		<< " / " << "Число проданных билетов (6)"
		<< " / " << "Расчетное число пассажиров (7)\n\n";


	user_input = get_user_input_with_conditions(n + 1, "lower_then_n");

	choosen_option = stoi(user_input);

	cout << "\n- Сортировка по возрастанию (1) или убыванию (2)?\n\n";

	sort_mode = get_user_input_with_conditions(0, "is_1_or_2");

	sort(sort_mode, choosen_option, bs);


}
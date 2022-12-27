#include "constants.h"
#include "structures_definition.h"
#include "additional_functions.h"
#include "group_output.h"
#include <iostream>
#include <iomanip> 
#include <fstream>

using namespace std;



// Вывод всех данных на экран:
void console_menu_option_output_all_data_to_console(bus_station* bs) {

	cout << "\tВЫВОД ВСЕХ ДАННЫХ В КОНСОЛЬ\n\n";

	if (bs->bus_station_type_of_list == '1') { // Односвязный

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {

			
			cout << "Автобусов на станции нет...\n\n";

			return;

		}

		int i = 1;
		cout << setiosflags(ios::left);
		cout << setw(5) << "№"
			<< setw(15) << "Направление" 
			<< setw(15) << "Номер рейса"
			<< setw(18) << "Марка автобуса"
			<< setw(20) << "Время отправления"
			<< setw(35) << "ФИО Водителя"
			<< setw(38) << "Число проданных билетов (за неделю)"
			<< setw(15) << "Расчетное число пассажиров (за сегодня)\n";

		while (iterator_bus != NULL) { // Поочередно печатаем автобусы

			cout << setw(5) << i;
			output_bus_to_console(iterator_bus);

			iterator_bus = iterator_bus->bus_next_bus;
			i++;
		}

	}


	else { // Двухсвязный

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {


			cout << "Автобусов на станции нет...\n\n";

			return;

		}

		int i = 1;
		cout << setiosflags(ios::left);
		cout << setw(5) << "№"
			<< setw(15) << "Направление"
			<< setw(15) << "Номер рейса"
			<< setw(18) << "Марка автобуса"
			<< setw(20) << "Время отправления"
			<< setw(35) << "ФИО Водителя"
			<< setw(38) << "Число проданных билетов (за неделю)"
			<< setw(15) << "Расчетное число пассажиров (за сегодня)\n";

		while (iterator_bus != NULL) { // Поочередно печатаем автобусы

			cout << setw(5) << i;
			output_bus_to_console(iterator_bus);

			iterator_bus = iterator_bus->bus_next_bus;
			i++;
		}

	}

	
}

// Вывод всех данных в файл:
void console_menu_option_output_all_data_to_file(bus_station* bs) {


	cout << "\tВЫВОД ВСЕХ ДАННЫХ В ФАЙЛ\n\n";


	// Файл выходных данных в режиме чтения:
	ofstream output_file;

	// Стираем прошлый вывод:
	output_file.open(gl_output_file, std::ofstream::out | std::ofstream::trunc); 
	output_file.close();


	if (bs->bus_station_type_of_list == '1') {

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {


			cout << "Автобусов на станции нет...\n\n";

			return;

		}


		while (iterator_bus != NULL) { // Поочередно печатаем автобусы

			output_bus_to_file(iterator_bus);
				
			iterator_bus = iterator_bus->bus_next_bus;

		}

	}


	else {

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {


			cout << "Автобусов на станции нет...\n\n";

			return;

		}


		while (iterator_bus != NULL) { // Поочередно печатаем автобусы

			output_bus_to_file(iterator_bus);

			iterator_bus = iterator_bus->bus_next_bus;
		}

	}


}


// Вывод на экран данных по заданному условию:
void console_menu_option_output_choosen_data_to_console(bus_station* bs) {


	cout << "\tВЫВОД В КОНСОЛЬ ДАННЫХ ПО ЗАДАННОМУ УСЛОВИЮ\n\n";

	string user_input; // Пользовательский ввод

	int n = 7; // Число параметров вывода

	int choosen_option; // Выбранный параметр поиска

	cout << "- По каким условиям выводить данные?\n";

	cout << "Направление (1)"
		<< " / " << "Номер рейса (2)"
		<< " / " << "Марка автобуса (3)"
		<< " / " << "Время отправления (4)"
		<< " / " << "ФИО Водителя (5)"
		<< " / " << "Число проданных билетов (6)"
		<< " / " << "Расчетное число пассажиров (7)\n\n";


	user_input = get_user_input_with_conditions(n+1, "lower_then_n");

	choosen_option = stoi(user_input);

	switch (choosen_option) { // Выбираем опцию для вывода по ней

	case 1:
		cout << "Введите направление. ";
		cin >> user_input;
		break;
	case 2:
		cout << "Введите номер рейса. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 3:
		cout << "Введите марку автобуса: ";
		cin >> user_input;
		break;
	case 4:
		cout << "Введите время отправления: ";
		cin >> user_input;
		break;
	case 5:
		cout << "Введите ФИО водителя: ";
		cin.ignore();
		getline(cin, user_input);
		break;
	case 6:
		cout << "Введите число проданных билетов. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 7:
		cout << "Введите расчетное число пассажиров. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;

	default:
		cout << "error";
		return;

	}

	cout << "\nИщем подходящие автобусы...\n\n";

	bool flag = false; // Был ли найден хоть один подходящий автобус

	if (bs->bus_station_type_of_list == '1') {

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;



		while (iterator_bus != NULL) { // Перебираем автобусы

			switch (choosen_option) { // В зависимости от опции принимаем решение о выводе

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;

			}

			iterator_bus = iterator_bus->bus_next_bus;
		}

		

	}
	else {

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;




		while (iterator_bus != NULL) { // Перебираем все автобусы

			switch (choosen_option) { // В зависимости от опции принимаем решение о выводе

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_console(iterator_bus);
					flag = true;

				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;
			}

			iterator_bus = iterator_bus->bus_next_bus;
		}




	}
	if (!flag) {
		cout << "\nПодходящих автобусов нет...\n\n";
	}


} // Конец блока "Вывод на экран данных по заданному условию"

// Вывод в файл данных по заданному условию:
void console_menu_option_output_choosen_data_to_file(bus_station* bs) {


	cout << "\tВЫВОД В ФАЙЛ ДАННЫХ ПО ЗАДАННОМУ УСЛОВИЮ\n\n";

	string user_input; // Пользовательский ввод

	int n = 7; // Число параметров вывода

	int choosen_option; // Выбранный параметр поиска

	// Сотрем вывод прошлых запусков:
	ofstream output_file;
	output_file.open(gl_output_file);
	output_file.close();

	cout << "- По каким условиям выводить данные?\n";

	cout << "Направление (1)"
		<< " / " << "Номер рейса (2)"
		<< " / " << "Марка автобуса (3)"
		<< " / " << "Время отправления (4)"
		<< " / " << "ФИО Водителя (5)"
		<< " / " << "Число проданных билетов (6)"
		<< " / " << "Расчетное число пассажиров (7)\n\n";


	user_input = get_user_input_with_conditions(n + 1, "lower_then_n");

	choosen_option = stoi(user_input);

	switch (choosen_option) { // Выбираем опцию

	case 1:
		cout << "Введите направление. ";
		cin >> user_input;
		break;
	case 2:
		cout << "Введите номер рейса. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 3:
		cout << "Введите марку автобуса: ";
		cin >> user_input;
		break;
	case 4:
		cout << "Введите время отправления: ";
		cin >> user_input;
		break;
	case 5:
		cout << "Введите ФИО водителя: ";
		cin.ignore();
		getline(cin, user_input);
		break;
	case 6:
		cout << "Введите число проданных билетов. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 7:
		cout << "Введите расчетное число пассажиров. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;

	default:
		cout << "error";
		return;

	}

	cout << "\nИщем подходящие автобусы...\n\n";

	bool flag = false; // Был ли найден хоть один подходящий автобус

	if (bs->bus_station_type_of_list == '1') {

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;



		while (iterator_bus != NULL) {

			switch (choosen_option) {

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;

			}

			iterator_bus = iterator_bus->bus_next_bus;
		}



	}
	else {

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;




		while (iterator_bus != NULL) { // Перебираем автобусы

			switch (choosen_option) { // В зависимости от опции принимаем решение о выводе

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_file(iterator_bus);
					flag = true;

				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;
			}

			iterator_bus = iterator_bus->bus_next_bus;
		}




	}
	if (!flag) {
		cout << "\nПодходящих автобусов нет...\n\n";

	}



}
// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
// ----------------------------------- Курсовая работа ----------------------------------------
// --------------------------------------------------------------------------------------------
// -----------Файл определения функций опций меню из группы опций удаления данных--------------
// --------------------------------------------------------------------------------------------




// Подключение стандартных библиотек:
#include <iostream>
#include <fstream>




// Подключение стандартного пространста имен:
using namespace std;




// Подключение других файлов программы:
#include "structures_definition.h" // Файл с определением вводимых структур (включает, в частности, 
								   // определение структуры автобусной станции bus_station, структуру списка автобусов и т.д.) 

#include "additional_functions.h" // Файл с заголовками дополнительных функций (таких как "является ли строка числом от 1 до n)

#include "group_delete.h" // Файл с заголовками функций, содержащих главную часть алгоритма удаления данных

#include "group_output.h" // Файл с заголовками функций, содержащих главную часть алгоритма вывода данных

#include "constants.h" // Файл с определением констант




// Объявление функций:

// Удаление всех данных:
void console_menu_option_delete_all_data(bus_station* bs);

// Удаление выбранных данных:
void console_menu_option_delete_choosen_data(bus_station* bs);




// Определение функций:




// Удаление всех данных:
void console_menu_option_delete_all_data(bus_station* bs) {


	cout << "\tУДАЛЕНИЕ ВСЕХ ДАННЫХ\n\n";


	// Объявление переменных:

	string user_input; // Пользовательский ввод


	// Если база данных не пуста (хранит данные об автобусах):
	if (!is_data_base_holding_empty_list(bs)) {


		// Вывод на экран предупреждения о возможной потере данных с предложением вернуться в меню:
		cout << "- Предупреждение: в базе данных уже хранятся данные об автобусах.\n"
			"Вы уверены, что хотите их стереть (1) или выберите вернуться в меню (2)?\n\n";


		// Получим от пользователя ответ, хочет ли он вернуться в меню:
		user_input = get_user_input_with_conditions(0, "is_1_or_2"); // Получение от пользователя ответа с проверкой на корректность: введена ли единица или двойка


		// Если пользователь выбрал вернуться в меню, то возвращаем его в меню:
		if (user_input == "2") {


			return; // Прерываем выполнение функции типа void, вызванной из цикла меню. Возвращаемся в цикл меню.


		} // Конец блока "Если пользователь выбрал вернуться в меню, то возвращаем его в меню"


	} // Конец блока "Если база данных не пуста (хранит данные об автобусах)"


	// Вызываем функцию удаления всех данных для линейного односвязного списка, если такой тип списка установлен в БД:
	// Примечание: функция так же удалит и все данные из файла хранения данных и все данные из файла выходных данных
	if (bs->bus_station_type_of_list == '1') delete_all_data(bs->bus_station_buses_linear_singly_linked_list);

	// В случае двухсвязного списка, передаем в ту же функцию указатель на двухсвязный список, хранящийся в БД:
	else delete_all_data(bs->bus_station_buses_linear_doubly_linked_list);


} // Конец блока "Удаление всех данных"




// Удаление выбранных данных:
void console_menu_option_delete_choosen_data(bus_station* bs) {


	cout << "\tУДАЛЕНИЕ ВЫБРАННЫХ ДАННЫХ\n\n";


	// Объявление переменных:

	int n = 7; // Число параметров удаления 

	int delete_parameter; // Номер параметра удаления, выбранный пользователем (от 1 до 7)

	string delete_key; // Значение параметра удаления, по которому будут удаляться данные


	cout << "- По каким условиям удалять данные?\n";


	cout << "Направление (1)"
		<< " / " << "Номер рейса (2)"
		<< " / " << "Марка автобуса (3)"
		<< " / " << "Время отправления (4)"
		<< " / " << "ФИО Водителя (5)"
		<< " / " << "Число проданных билетов (6)"
		<< " / " << "Расчетное число пассажиров (7)\n\n";


	// Считывание от пользователя номера параметра удаления с проверкой на корректность: было ли введено натуральное число:
	delete_parameter = stoi(get_user_input_with_conditions(n + 1, "lower_then_n")); 


	// В зависимости от номера параметра удаления, считываем параметр удаления
	// (у разных параметров разный способ ввода)
	switch (delete_parameter) {

	case 1:
		cout << "Введите направление. ";
		cin >> delete_key;
		break;
	case 3:
		cout << "Введите марку автобуса: ";
		cin >> delete_key;
		break;
	case 4:
		cout << "Введите время отправления: ";
		cin >> delete_key;
		break;
	case 5:
		cout << "Введите ФИО водителя: ";
		cin.ignore();
		getline(cin, delete_key);
		break;
	case 2:
		cout << "Введите номер рейса. ";
		delete_key = get_user_input_with_conditions(0, "natural_number");
		break;
	case 6:
		cout << "Введите число проданных билетов. ";
		delete_key = get_user_input_with_conditions(0, "natural_number");
		break;
	case 7:
		cout << "Введите расчетное число пассажиров. ";
		delete_key = get_user_input_with_conditions(0, "natural_number");
		break;
	default:
		cout << "error";
		return;

	} // Конец блока "В зависимости от номера параметра удаления, считываем параметр удаления"


	cout << "\nУдаляем автобусы по заданным критериям...\n\n";


	bool flag = false; // Был ли удален хотя бы один автобус
	bool deliting = false; // Удаляем ли этот автобус
	

	// Линейный односвязный список, удаление выбранных элементов:
	if (bs->bus_station_type_of_list == '1') {


		// Создадим переменную-автобуса для "движения" по списку:
		bus_from_linear_singly_linked_list* iterator_bus = new bus_from_linear_singly_linked_list;  


		// Установим ее до начала списка, т.е. она будет указывать на первый элемент списка.
		// Таким образом, удалять мы будем не текущий элемент, а следующий, но так же переберем все автобусы из списка, ведь
		// начали не с первого элемента, а с "добавленного" перед первым элемента.
		iterator_bus->bus_next_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;


		// Цикл прохода по списку:
		while (iterator_bus->bus_next_bus != NULL) {


			// В зависимости от номера параметра удаления, делаем соответствующее сравнение с данными автобуса:
			switch (delete_parameter) {


			case 1: // Номер параметра удаления соответствует "Направление"

				// Если у следующего автобуса "Направление" равно удаляемому пользователям, то удаляем следующий автобус:
				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_destination) deliting = true; 
				break;

			case 2: // Аналогично ...

				// Аналогично...
				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_passage_number) deliting = true;
				break;

			case 3: // ... 

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_brand) deliting = true;
				break;

			case 4:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_departure_time) deliting = true;
				break;

			case 5:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_full_name_of_the_driver) deliting = true;
				break;

			case 6:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_number_of_tickets_sold) deliting = true;
				break;

			case 7:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_estimated_number_of_passengers) deliting = true;
				break;

			default:

				cout << "Error in delete function";
				exit(1);

			} // Конец блока "В зависимости от номера параметра удаления, делаем соответствующее сравнение с данными автобуса"


			// Удаление автобуса
			if (deliting) {

				
				cout << "\nУдаляем автобус: ";


				// Печатаем автобус:
				output_bus_to_console(iterator_bus->bus_next_bus);


				// Если удаляемый автобус - это первый в списке:
				if (iterator_bus->bus_next_bus == bs->bus_station_buses_linear_singly_linked_list->buses_first_bus) {

					// Сдвинем указатель на начало списка на следующий автобус (или на NULL):
					bs->bus_station_buses_linear_singly_linked_list->buses_first_bus = iterator_bus->bus_next_bus->bus_next_bus;

				}


				// Удаляем автобус:
				delete_next_bus(iterator_bus);


				flag = true; // Был удален хоть один автобус
				deliting = false; // Этот флаг должен стоять false в начале каждого прохода цикла, он опредяляет, будет ли удаление


			} // Конец блока "Удаление автобуса"

			// Идем дальше по списку
			iterator_bus = iterator_bus->bus_next_bus;

		} // Конец блок "Цикл прохода по списку"



	} // Конец блока "Линейный односвязный список, удаление выбранных элементов"

	// Линейный двухсвязный список, удаление выбранных элементов:
	else {


		// Создадим переменную-автобуса для "движения" по списку:
		bus_from_linear_doubly_linked_list* iterator_bus = new bus_from_linear_doubly_linked_list;


		// Установим ее до начала списка, т.е. она будет указывать на первый элемент списка.
		// Таким образом, удалять мы будем не текущий элемент, а следующий, но так же переберем все автобусы из списка, ведь
		// начали не с первого элемента, а с "добавленного" перед первым элемента.
		iterator_bus->bus_next_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;


		// Цикл прохода по списку:
		while (iterator_bus->bus_next_bus != NULL) {


			// В зависимости от номера параметра удаления, делаем соответствующее сравнение с данными автобуса:
			switch (delete_parameter) {


			case 1: // Номер параметра удаления соответствует "Направление"

				// Если у следующего автобуса "Направление" равно удаляемому пользователям, то удаляем следующий автобус:
				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_destination) deliting = true;
				break;

			case 2: // Аналогично ...

				// Аналогично...
				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_passage_number) deliting = true;
				break;

			case 3: // ... 

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_brand) deliting = true;
				break;
			
			case 4:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_departure_time) deliting = true;
				break;
			
			case 5:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_full_name_of_the_driver) deliting = true;
				break;

			case 6:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_number_of_tickets_sold) deliting = true;
				break;

			case 7:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_estimated_number_of_passengers) deliting = true;
				break;

			default:

				cout << "Error in delete function";
				exit(1);

			} // Конец блока "В зависимости от номера параметра удаления, делаем соответствующее сравнение с данными автобуса"


			// Удаление автобуса:
			if (deliting) {


				cout << "\nУдаляем автобус: ";


				// Печатаем автобус:
				output_bus_to_console(iterator_bus->bus_next_bus);


				// Если удаляемый автобус - это первый в списке:
				if (iterator_bus->bus_next_bus == bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus) {

					// Сдвинем указатель на начало списка на следующий автобус (или на NULL):
					bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus = iterator_bus->bus_next_bus->bus_next_bus;

				}


				// Удаляем автобус:
				delete_next_bus(iterator_bus);
				flag = true;
				deliting = false;


			} // Конец блока "Удаление автобуса"


			// Идем дальше по списку
			iterator_bus = iterator_bus->bus_next_bus;


		} // Конец блок "Цикл прохода по списку"


	} // Конец блока "Линейный двухсвязный список, удаление выбранных элементов"


	// Если не был удален ни один автобус:
	if (!flag) cout << "\nНи один автобусов не был удален...\n\n";


	// Если был удален хотя бы один автобус, придется обновить содержимое файла хранения базы данных:
	else {


		// Линейный односвязный список:
		if (bs->bus_station_type_of_list == '1') save_all_buses_to_storage_file(bs->bus_station_buses_linear_singly_linked_list);


		// Линейный двухсвязный список:
		else save_all_buses_to_storage_file(bs->bus_station_buses_linear_doubly_linked_list);


	}


} // Конец функции "Удаление выбранных данных"

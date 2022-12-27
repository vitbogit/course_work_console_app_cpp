// Подключение стандартных библиотек:
#include <fstream>
#include <iostream>
#include <iomanip>




// Подключение стандартного пространста имен: 
using namespace std;




// Подключение других файлов программы:
#include "structures_definition.h"
#include "additional_functions.h"
#include "constants.h"




// Объявление функций, которые далее в этом файле будут определены:

// Ввод всех данных из файла (линейный односвязный список)
void input_all_data_from_file(buses_linear_singly_linked_list* buses); 

// Ввод всех данных из файла (линейный двухсвязный список)
void input_all_data_from_file(buses_linear_doubly_linked_list* buses);

// Ввод всех данных из консоли (линейный односвязный список):
void input_all_data_from_console(buses_linear_singly_linked_list* buses);

// Ввод всех данных из консоли (линейный двухсвязный список):
void input_all_data_from_console(buses_linear_doubly_linked_list* buses);

// Добавить данные из файла (линейный односвязный список):
void add_data_from_file(buses_linear_singly_linked_list* buses);

// Добавить данные из файла (линейный двухсвязный список):
void add_data_from_file(buses_linear_doubly_linked_list* buses);

// Добавить данные из консоли (линейный односвязный список):
void add_data_from_console(buses_linear_singly_linked_list* buses);

// Добавить данные из консоли (линейный двухсвязный список):
void add_data_from_console(buses_linear_doubly_linked_list* buses);



// Ввод всех данных из файла (линейный односвязный список):
void input_all_data_from_file(buses_linear_singly_linked_list* buses) {


	// Открываем файл входных данных в режиме чтения:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	// Считываем первый автобус из файла:
	if (!intput_file.eof()) {


		// Создаем запись о первом автобусе в списке:
		buses->buses_first_bus = new bus_from_linear_singly_linked_list;


		// Выделяем память под данные о первом автобусе:
		buses->buses_first_bus->bus_data = new bus_data;


		// Пока что второго автобуса нет:
		buses->buses_first_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о первом автобусе:

		intput_file >> buses->buses_first_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		intput_file >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


	} // Конец блока "Считываем первый автобус из файла"


	// Для "движения" по списку создаем переменную-автобус:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// Циклом считываем все оставшиеся автобусы:
	while (!intput_file.eof()) {


		// Создаем запись о следующем автобусе:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// Переходим к следующему автобусу::
		iterator_bus = iterator_bus->bus_next_bus;


		// Выделяем память под данные о первом автобусе:
		iterator_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет:
		iterator_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о данном автобусе:

		intput_file >> iterator_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		intput_file >> iterator_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		intput_file >> iterator_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		intput_file >> iterator_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		intput_file >> f >> i >> o; // Считываем последовательно три строки
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> iterator_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // Конец блока "Циклом считываем все оставшиеся автобусы"



	// Закрываем файлы:
	intput_file.close();
	storage_file.close();


} // Конец блока "Ввод всех данных из файла (линейный односвязный список)"




// Ввод всех данных из файла (линейный двухсвязный список):
void input_all_data_from_file(buses_linear_doubly_linked_list* buses) {


	// Открываем файл входных данных в режиме чтения:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	// Считываем первый автобус из файла:
	if (!intput_file.eof()) {


		// Создаем запись о первом автобусе в списке:
		buses->buses_first_bus = new bus_from_linear_doubly_linked_list;


		// Выделяем память под данные о первом автобусе:
		buses->buses_first_bus->bus_data = new bus_data;
		buses->buses_first_bus->bus_next_bus = NULL;
		buses->buses_first_bus->bus_previous_bus = NULL;


		// Пока что последний автобус - это и первый автобус
		buses->buses_last_bus = buses->buses_first_bus;
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = NULL;


		// Последовательно считываем данные о первом автобусе:

		intput_file >> buses->buses_first_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		intput_file >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


	} // Конец блока "Считываем первый автобус из файла"


	// Циклом считываем все оставшиеся автобусы:
	while (!intput_file.eof()) {


		// В дополнительную переменную запомним адрес последнего автобуса:
		bus_from_linear_doubly_linked_list* tmp;
		tmp = buses->buses_last_bus;


		// Создаем запись о следующем автобусе и делаем его концом списка:
		buses->buses_last_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;
		buses->buses_last_bus = buses->buses_last_bus->bus_next_bus;


		// Выделяем память под данные о последнем автобусе:
		buses->buses_last_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет, а предыдущий автобус - это предыдущий конец списка:
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = tmp;


		// Последовательно считываем данные о данном автобусе:

		intput_file >> buses->buses_last_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_destination << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_passage_number << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_last_bus->bus_data->bus_brand << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		intput_file >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_last_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_last_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // Конец блока "Циклом считываем все оставшиеся автобусы"



	// Закрываем файлы:
	intput_file.close();
	storage_file.close();


} // Конец блока "Ввод всех данных из файла (линейный двухсвязный список)"




// Ввод всех данных из консоли (линейный односвязный список):
void input_all_data_from_console(buses_linear_singly_linked_list* buses) {


	string user_input; // Пользовательский ввод

	int n; // Число вводимых автобусов

	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	cout << "Введите количество автобусов, данные о которых вы хотите ввести. ";


	// Считывание ответа пользователя:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "Вводите для каждого автобуса:\n";
	cout << setiosflags(ios::left);
	cout << setw(15) << "Направление"
		<< setw(15) << "Номер рейса"
		<< setw(18) << "Марка автобуса"
		<< setw(20) << "Время отправления"
		<< setw(35) << "ФИО Водителя"
		<< setw(38) << "Число проданных билетов (за неделю)"
		<< setw(15) << "Расчетное число пассажиров (за сегодня)\n";

	n = stoi(user_input);

	if (n > 0) {

		buses->buses_first_bus = new bus_from_linear_singly_linked_list;
		buses->buses_first_bus->bus_data = new bus_data;
		buses->buses_first_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о данном автобусе:

		cin >> buses->buses_first_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_first_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_first_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_first_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		cin >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


		n--;
	}


	// Для "движения" по списку создаем переменную-автобус:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;

	while (n > 0) {


		// Создаем запись о следующем автобусе:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// Переходим к следующему автобусу::
		iterator_bus = iterator_bus->bus_next_bus;


		// Выделяем память под данные о первом автобусе:
		iterator_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет:
		iterator_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о данном автобусе:

		cin >> iterator_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		cin >> iterator_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		cin >> iterator_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		cin >> iterator_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		cin >> f >> i >> o; // Считываем последовательно три строки
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> iterator_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;
	}


	// Закрываем файлы:
	storage_file.close();


} // Конец блока "Ввод всех данных из консоли (линейный односвязный список)"




// Ввод всех данных из консоли (линейный двухсвязный список):
void input_all_data_from_console(buses_linear_doubly_linked_list* buses) {


	string user_input; // Пользовательский ввод

	int n; // Число вводимых автобусов

	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	cout << "Введите количество автобусов, данные о которых вы хотите ввести: ";


	// Считывание ответа пользователя:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "Вводите для каждого автобуса:";
	cout << setiosflags(ios::left);
	cout << setw(15) << "Направление"
		<< setw(15) << "Номер рейса"
		<< setw(18) << "Марка автобуса"
		<< setw(20) << "Время отправления"
		<< setw(35) << "ФИО Водителя"
		<< setw(38) << "Число проданных билетов (за неделю)"
		<< setw(15) << "Расчетное число пассажиров (за сегодня)\n";

	n = stoi(user_input);

	if (n > 0) {


		// Создаем запись о первом автобусе в списке:
		buses->buses_first_bus = new bus_from_linear_doubly_linked_list;


		// Выделяем память под данные о первом автобусе:
		buses->buses_first_bus->bus_data = new bus_data;
		buses->buses_first_bus->bus_next_bus = NULL;
		buses->buses_first_bus->bus_previous_bus = NULL;


		// Пока что последний автобус - это и первый автобус
		buses->buses_last_bus = buses->buses_first_bus;
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = NULL;


		// Последовательно считываем данные о первом автобусе:

		cin >> buses->buses_first_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_first_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_first_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_first_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		cin >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


		n--;
	}


	// Циклом считываем все оставшиеся автобусы:
	while (n > 0) {


		// В дополнительную переменную запомним адрес последнего автобуса:
		bus_from_linear_doubly_linked_list* tmp;
		tmp = buses->buses_last_bus;


		// Создаем запись о следующем автобусе и делаем его концом списка:
		buses->buses_last_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;
		buses->buses_last_bus = buses->buses_last_bus->bus_next_bus;


		// Выделяем память под данные о последнем автобусе:
		buses->buses_last_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет, а предыдущий автобус - это предыдущий конец списка:
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = tmp;


		// Последовательно считываем данные о данном автобусе:

		cin >> buses->buses_last_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_last_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_last_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_last_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_last_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		cin >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_last_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_last_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_last_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;

	} // Конец блока "Циклом считываем все оставшиеся автобусы"


	// Закрываем файлы:
	storage_file.close();


} // Конец блока "Ввод всех данных из консоли (линейный двухсвязный список)"




// Добавить данные из файла (линейный односвязный список):
void add_data_from_file(buses_linear_singly_linked_list* buses) {

	// Открываем файл входных данных в режиме чтения:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	// Для "движения" по списку создаем переменную-автобус:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// Дойдем до конца списка:
	while (iterator_bus->bus_next_bus != NULL) {

		iterator_bus = iterator_bus->bus_next_bus;

	}


	// Циклом считываем все автобусы:
	while (!intput_file.eof()) {


		// Создаем запись о следующем автобусе:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// Переходим к следующему автобусу::
		iterator_bus = iterator_bus->bus_next_bus;


		// Выделяем память под данные о первом автобусе:
		iterator_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет:
		iterator_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о данном автобусе:

		intput_file >> iterator_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		intput_file >> iterator_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		intput_file >> iterator_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		intput_file >> iterator_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		intput_file >> f >> i >> o; // Считываем последовательно три строки
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> iterator_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // Конец блока "Циклом считываем все оставшиеся автобусы"



	// Закрываем файлы:
	intput_file.close();
	storage_file.close();

}





// Добавить данные из файла (линейный двухсвязный список):
void add_data_from_file(buses_linear_doubly_linked_list* buses) {

	// Открываем файл входных данных в режиме чтения:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	// Для "движения" по списку создаем переменную-автобус:
	bus_from_linear_doubly_linked_list* iterator_bus = buses->buses_last_bus;


	// Циклом считываем все автобусы:
	while (!intput_file.eof()) {


		// Создаем запись о следующем автобусе:
		iterator_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;


		// Переходим к следующему автобусу::
		iterator_bus = iterator_bus->bus_next_bus;


		// Выделяем память под данные о первом автобусе:
		iterator_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет:
		iterator_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о данном автобусе:

		intput_file >> iterator_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		intput_file >> iterator_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		intput_file >> iterator_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		intput_file >> iterator_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		intput_file >> f >> i >> o; // Считываем последовательно три строки
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> iterator_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // Конец блока "Циклом считываем все оставшиеся автобусы"

	buses->buses_last_bus = iterator_bus;

	// Закрываем файлы:
	intput_file.close();
	storage_file.close();

}




// Добавить данные из консоли (линейный односвязный список):
void add_data_from_console(buses_linear_singly_linked_list* buses) {


	string user_input; // Пользовательский ввод

	int n; // Число вводимых автобусов

	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	cout << "Введите количество автобусов, данные о которых вы хотите ввести. ";


	// Считывание ответа пользователя:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "Вводите для каждого автобуса:\n";
	cout << setiosflags(ios::left);
	cout << setw(15) << "Направление"
		<< setw(15) << "Номер рейса"
		<< setw(18) << "Марка автобуса"
		<< setw(20) << "Время отправления"
		<< setw(35) << "ФИО Водителя"
		<< setw(38) << "Число проданных билетов (за неделю)"
		<< setw(15) << "Расчетное число пассажиров (за сегодня)\n";


	n = stoi(user_input);


	// Для "движения" по списку создаем переменную-автобус:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// Дойдем до конца списка:
	while (iterator_bus->bus_next_bus != NULL) {

		iterator_bus = iterator_bus->bus_next_bus;

	}


	while (n > 0) {


		// Создаем запись о следующем автобусе:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// Переходим к следующему автобусу::
		iterator_bus = iterator_bus->bus_next_bus;


		// Выделяем память под данные о первом автобусе:
		iterator_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет:
		iterator_bus->bus_next_bus = NULL;


		// Последовательно считываем данные о данном автобусе:

		cin >> iterator_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		cin >> iterator_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		cin >> iterator_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		cin >> iterator_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		cin >> f >> i >> o; // Считываем последовательно три строки
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> iterator_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;
	}


	// Закрываем файлы:
	storage_file.close();



}




// Добавить данные из консоли (линейный двухсвязный список):
void add_data_from_console(buses_linear_doubly_linked_list* buses) {



	string user_input; // Пользовательский ввод

	int n; // Число вводимых автобусов

	// Открываем файл для хранения БД в режиме записи:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	cout << "Введите количество автобусов, данные о которых вы хотите ввести: ";


	// Считывание ответа пользователя:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "Вводите для каждого автобуса:";
	cout << setiosflags(ios::left);
	cout << setw(15) << "Направление"
		<< setw(15) << "Номер рейса"
		<< setw(18) << "Марка автобуса"
		<< setw(20) << "Время отправления"
		<< setw(35) << "ФИО Водителя"
		<< setw(38) << "Число проданных билетов (за неделю)"
		<< setw(15) << "Расчетное число пассажиров (за сегодня)\n";

	n = stoi(user_input);



	// Циклом считываем все оставшиеся автобусы:
	while (n > 0) {


		// В дополнительную переменную запомним адрес последнего автобуса:
		bus_from_linear_doubly_linked_list* tmp = buses->buses_last_bus;


		// Создаем запись о следующем автобусе и делаем его концом списка:
		buses->buses_last_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;
		buses->buses_last_bus = buses->buses_last_bus->bus_next_bus;


		// Выделяем память под данные о последнем автобусе:
		buses->buses_last_bus->bus_data = new bus_data;


		// Пока что следующего автобуса нет, а предыдущий автобус - это предыдущий конец списка:
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = tmp;


		// Последовательно считываем данные о данном автобусе:

		cin >> buses->buses_last_bus->bus_data->bus_destination; // Пункт назначения данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_last_bus->bus_data->bus_passage_number; // Номер рейса данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_last_bus->bus_data->bus_brand; // Марка данного автобуса 
		storage_file << buses->buses_last_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_last_bus->bus_data->bus_departure_time; // Время отправления данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ФИО храним в трех строках, для простоты реализации считывания
		cin >> f >> i >> o; // Считываем последовательно три строки
		buses->buses_last_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ФИО водителя данного автобуса
		storage_file << buses->buses_last_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_last_bus->bus_data->bus_number_of_tickets_sold; // Число проданных в данном автобусе билетов за последнюю неделю
		storage_file << buses->buses_last_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers; // Расчетное количество пассажиров, которые поедут на данном автобусе сегодня
		storage_file << buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;

	} // Конец блока "Циклом считываем все оставшиеся автобусы"


	// Закрываем файлы:
	storage_file.close();

}
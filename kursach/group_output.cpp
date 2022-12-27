#include <iostream>
#include <iomanip>
#include <fstream>

#include "constants.h"
#include "structures_definition.h"

using namespace std;




// Объявление функций:




// Вывод данных об автобусе в консоль (линейный односвязный список):
void output_bus_to_console(bus_from_linear_singly_linked_list* bus);

// Вывод данных об автобусе в консоль (линейный двухсвязный список):
void output_bus_to_console(bus_from_linear_doubly_linked_list* bus);

// Вывод данных об автобусе в файл выходных данных (линейный односвязный список):
void output_bus_to_file(bus_from_linear_singly_linked_list* bus);

// Вывод данных об автобусе в файл выходных данных (линейный двухсвязный список):
void output_bus_to_file(bus_from_linear_doubly_linked_list* bus);

// Вывод данных об автобусе в файл хранения данных (линейный односвязный список):
void save_bus_to_storage_file(bus_from_linear_singly_linked_list* bus);

// Вывод данных об автобусе в файл хранения данных (линейный двухсвязный список):
void save_bus_to_storage_file(bus_from_linear_doubly_linked_list* bus);

// Сохранение всех автобусов в файл хранения БД (линейный односвязный список):
void save_all_buses_to_storage_file(buses_linear_singly_linked_list* buses);

// Сохранение всех автобусов в файл хранения БД (линейный двухсвязный список):
void save_all_buses_to_storage_file(buses_linear_doubly_linked_list* buses);




// Определение функций:




// Вывод данных об автобусе в консоль (линейный односвязный список):
void output_bus_to_console(bus_from_linear_singly_linked_list* bus) {


	// Последовательно выводим в консоль все данные о данном автобусе:

	cout << setw(15) << bus->bus_data->bus_destination;
	cout << setw(15) << bus->bus_data->bus_passage_number;
	cout << setw(18) << bus->bus_data->bus_brand;
	cout << setw(20) << bus->bus_data->bus_departure_time;
	cout << setw(35) << bus->bus_data->bus_full_name_of_the_driver;
	cout << setw(38) << bus->bus_data->bus_number_of_tickets_sold;
	cout << setw(15) << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // Конец блока "Вывод данных об автобусе в консоль (линейный односвязный список)"




// Вывод данных об автобусе в консоль (линейный двухсвязный список):
void output_bus_to_console(bus_from_linear_doubly_linked_list* bus) {


	// Последовательно выводим в консоль все данные о данном автобусе:

	cout << setw(15) << bus->bus_data->bus_destination;
	cout << setw(15) << bus->bus_data->bus_passage_number;
	cout << setw(18) << bus->bus_data->bus_brand;
	cout << setw(20) << bus->bus_data->bus_departure_time;
	cout << setw(35) << bus->bus_data->bus_full_name_of_the_driver;
	cout << setw(38) << bus->bus_data->bus_number_of_tickets_sold;
	cout << setw(15) << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // Конец блока "Вывод данных об автобусе в консоль (линейный двухсвязный список)




// Вывод данных об автобусе в файл выходных данных (линейный односвязный список):
void output_bus_to_file(bus_from_linear_singly_linked_list* bus){


	// Объявление переменных:

	ofstream output_file; // Поток вывода данных в файл


	// Открытие файла выходных данных в режиме записи в конец файла (append):
	output_file.open(gl_output_file, std::ofstream::app);


	// Последовательно выводим в консоль все данные о данном автобусе:

	output_file << bus->bus_data->bus_destination << " ";
	output_file << bus->bus_data->bus_passage_number << " ";
	output_file << bus->bus_data->bus_brand << " ";
	output_file << bus->bus_data->bus_departure_time << " ";
	output_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	output_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	output_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // Конец блока "Вывод данных об автобусе в файл выходных данных (линейный односвязный список)"




// Вывод данных об автобусе в файл выходных данных (линейный двухсвязный список):
void output_bus_to_file(bus_from_linear_doubly_linked_list* bus) {


	// Объявление переменных:

	ofstream output_file; // Поток вывода данных в файл


	// Открытие файла выходных данных в режиме записи в конец файла (append):
	output_file.open(gl_output_file, std::ofstream::app);


	// Последовательно выводим в консоль все данные о данном автобусе:

	output_file << bus->bus_data->bus_destination << " ";
	output_file << bus->bus_data->bus_passage_number << " ";
	output_file << bus->bus_data->bus_brand << " ";
	output_file << bus->bus_data->bus_departure_time << " ";
	output_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	output_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	output_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // Конец блока "Вывод данных об автобусе в файл выходных данных (линейный двухсвязный список)"




// Вывод данных об автобусе в файл хранения данных (линейный односвязный список):
void save_bus_to_storage_file(bus_from_linear_singly_linked_list* bus) {


	// Объявление переменных:

	ofstream storage_file; // Поток вывода данных в файл


	// Открытие файла хранения данных в режиме записи в конец файла (append):
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app); 


	// Последовательно выводим в консоль все данные о данном автобусе:

	storage_file << bus->bus_data->bus_destination << " ";
	storage_file << bus->bus_data->bus_passage_number << " ";
	storage_file << bus->bus_data->bus_brand << " ";
	storage_file << bus->bus_data->bus_departure_time << " ";
	storage_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	storage_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	storage_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // Конец блока "Вывод данных об автобусе в файл хранения данных (линейный односвязный список)"




// Вывод данных об автобусе в файл хранения данных (линейный двухсвязный список):
void save_bus_to_storage_file(bus_from_linear_doubly_linked_list* bus) {


	// Объявление переменных:

	ofstream storage_file; // Поток вывода данных в файл


	// Открытие файла хранения данных в режиме записи в конец файла (append):
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	// Последовательно выводим в консоль все данные о данном автобусе:

	storage_file << bus->bus_data->bus_destination << " ";
	storage_file << bus->bus_data->bus_passage_number << " ";
	storage_file << bus->bus_data->bus_brand << " ";
	storage_file << bus->bus_data->bus_departure_time << " ";
	storage_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	storage_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	storage_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // Конец блока "Вывод данных об автобусе в файл хранения данных (линейный двухсвязный список)"




// Сохранение всех автобусов в файл хранения БД (линейный односвязный список):
void save_all_buses_to_storage_file(buses_linear_singly_linked_list* buses){


	// Очистим файл хранения БД:
	ofstream file;
	file.open(gl_bus_station_storage_file);
	file.close();


	// Создадим автобус-итератор и установим его в начало списка:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// Переберем все автобусы списка и сохраним их в файл хранения БД:
	while (iterator_bus != NULL) {
		save_bus_to_storage_file(iterator_bus);
		iterator_bus = iterator_bus->bus_next_bus;
	}


} // Конец блока "Сохранение всех автобусов в файл хранения БД (линейный односвязный список)"




// Сохранение всех автобусов в файл хранения БД (линейный двухсвязный список):
void save_all_buses_to_storage_file(buses_linear_doubly_linked_list* buses) {


	// Очистим файл хранения БД:
	ofstream file;
	file.open(gl_bus_station_storage_file);
	file.close();


	// Создадим автобус-итератор и установим его в начало списка:
	bus_from_linear_doubly_linked_list* iterator_bus = buses->buses_first_bus;


	// Переберем все автобусы списка и сохраним их в файл хранения БД:
	while (iterator_bus != NULL) {
		save_bus_to_storage_file(iterator_bus);
		iterator_bus = iterator_bus->bus_next_bus;
	}


} // Конец блока "Сохранение всех автобусов в файл хранения БД (линейный двухсвязный список)"

#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "structures_definition.h"
#include "menu_options_group_of_output.h"
#include "group_output.h"
#include "constants.h"

void sort(string sort_mode, int choosen_option, bus_station* bs);

void sort(string sort_mode, int choosen_option, bus_station* bs) {


	// Описание сортировки: будем перебирать все элементы списка последовательно.
	// Каждый элемент будем сравнивать со всеми предыдущими и передвигать его в соответствующую позицию.
	// То есть на каждом шаге будем получать отсортированный отрезок списка, и с каждом шаге этот отрезок
	// будет увеличиваться в длине на единицу.
	// Так как работа идет со списками, а не с массивами, то реализация данного алгоритма на первый взгляд
	// может показаться запутанной, однако я ввел сразу несколько дополнительных переменных для 
	// максимальной наглядности и простоты понимания реализации алгоритма.


	// Случай линейного односвязного списка:
	if (bs->bus_station_type_of_list == '1') {

		// Основной итератор, используется для перебора всех элементов списка.
		// Итератор будет удаляться со своего прежнего положения и вставляться в отсортированную часть списка.
		// После этого итератор будет равен следующему нерассмотренному элементу:
		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus->bus_next_bus;

		// Место перед вставкой итератора:
		bus_from_linear_singly_linked_list* mesto_pered_vstavkoi_iterator;

		// Место после удаления итератора:
		bus_from_linear_singly_linked_list* mesto_posle_udaleniya_iterator;

		// Место перед удалением итератора:
		bus_from_linear_singly_linked_list* mesto_pered_udaleniem_iterator;


		// Проходим весь список:
		while (iterator_bus != NULL) {


			// Место перед вставкой итератора. Изначально указывает на первый элемент в списке,
			// то есть как бы находится до начала списка:
			mesto_pered_vstavkoi_iterator = new bus_from_linear_singly_linked_list;
			mesto_pered_vstavkoi_iterator->bus_next_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;


			// В зависимости от выбранной опции сортировки, а также направления (возрастание, убывание)
			// ищем место в отсортированной части списка для вставки рассматриваемого элемента:
			switch (choosen_option) {

			case 1: // "Направление"

				if (sort_mode == "1") { // По возрастанию

					// Пока не нашли место для вставки или не наткнулись на этот же элемент:
					while (iterator_bus->bus_data->bus_destination > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						// Передвигаем "место перед вставкой" вперед
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else { // По убыванию

					// Далее все аналогично...

					while (iterator_bus->bus_data->bus_destination < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 2:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_passage_number > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				else {

					while (iterator_bus->bus_data->bus_passage_number < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				break;

			case 3:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_brand > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_brand < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 4:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_departure_time > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_departure_time < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 5:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 6:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 7:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;


			} // Конец блока "// В зависимости от выбранной опции сортировки, а также направления (возрастание, убывание)
			// ищем место в отсортированной части списка для вставки рассматриваемого элемента"


			// Если рассматриваемый элемент и так стоит на своем месте в отсортированной части списка:
			if (mesto_pered_vstavkoi_iterator->bus_next_bus == iterator_bus) {

				// Просто переходим к рассмотрению следующего элемента
				iterator_bus = iterator_bus->bus_next_bus;

			}

			// Иначе делаем перестановку "итератора" на его "место-вставки"...
			else {

				// Найдем "место перед удалением итератора" и сохраним его в эту переменную:
				mesto_pered_udaleniem_iterator = new bus_from_linear_singly_linked_list;
				mesto_pered_udaleniem_iterator = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;
				while (mesto_pered_udaleniem_iterator->bus_next_bus != iterator_bus) {
					mesto_pered_udaleniem_iterator = mesto_pered_udaleniem_iterator->bus_next_bus;
				}

				// Если будем вставлять итератор на место первого элемента списка, то 
				// нужно сделать итератор первым элементом в списке (направить на него указатель first_bus)
				if (mesto_pered_vstavkoi_iterator->bus_next_bus == bs->bus_station_buses_linear_singly_linked_list->buses_first_bus) {
					bs->bus_station_buses_linear_singly_linked_list->buses_first_bus = iterator_bus;
				}


				// Сохраним "место после удаления итератора"
				mesto_posle_udaleniya_iterator = iterator_bus->bus_next_bus;


				// Вставляем итератор в выбранное место:
				iterator_bus->bus_next_bus = mesto_pered_vstavkoi_iterator->bus_next_bus;
				mesto_pered_vstavkoi_iterator->bus_next_bus = iterator_bus;


				// Далее указатель итератора передвигается на следующий элемент в списке.
				// Передвинутый автобус при этом остается на новом месте:
				iterator_bus = mesto_posle_udaleniya_iterator;


				// Место перед удалением итератора должно отправлять на место после удаления,
				// если не написать эту строчку, то будет отправлять на новое место итератора:
				mesto_pered_udaleniem_iterator->bus_next_bus = mesto_posle_udaleniya_iterator;


			} // Конец блока "Иначе делаем перестановку "итератора" на его "место-вставки""


		} // Конец блока "Проходим весь список"


	} // Конец блока "Случай линейного односвязного списка"


	else { // Случай линейного двухсвязного списка

		// Основной итератор, используется для перебора всех элементов списка.
		// Итератор будет удаляться со своего прежнего положения и вставляться в отсортированную часть списка.
		// После этого итератор будет равен следующему нерассмотренному элементу:
		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus->bus_next_bus;

		// Место перед вставкой итератора:
		bus_from_linear_doubly_linked_list* mesto_pered_vstavkoi_iterator;

		// Место после удаления итератора:
		bus_from_linear_doubly_linked_list* mesto_posle_udaleniya_iterator;

		// Место перед удалением итератора:
		bus_from_linear_doubly_linked_list* mesto_pered_udaleniem_iterator;

		// Проходим весь список:
		while (iterator_bus != NULL) {


			// Место перед вставкой итератора. Изначально указывает на первый элемент в списке,
			// то есть как бы находится до начала списка:
			mesto_pered_vstavkoi_iterator = new bus_from_linear_doubly_linked_list;
			mesto_pered_vstavkoi_iterator->bus_next_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;


			// В зависимости от выбранной опции сортировки, а также направления (возрастание, убывание)
			// ищем место в отсортированной части списка для вставки рассматриваемого элемента:
			switch (choosen_option) {

			case 1: // "Направление"

				if (sort_mode == "1") { // По возрастанию

					// Пока не нашли место для вставки или не наткнулись на этот же элемент:
					while (iterator_bus->bus_data->bus_destination > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						// Передвигаем "место перед вставкой" вперед
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else { // По убыванию

					while (iterator_bus->bus_data->bus_destination < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 2: // Аналогично ...

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_passage_number > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				else {

					while (iterator_bus->bus_data->bus_passage_number < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				break;

			case 3:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_brand > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_brand < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 4:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_departure_time > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_departure_time < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 5:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 6:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 7:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;


			} // Конец блока "// В зависимости от выбранной опции сортировки, а также направления (возрастание, убывание)
			// ищем место в отсортированной части списка для вставки рассматриваемого элемента"


			// Если рассматриваемый элемент и так стоит на своем месте в отсортированной части списка:
			if (mesto_pered_vstavkoi_iterator->bus_next_bus == iterator_bus) {

				// Просто переходим к рассмотрению следующего элемента
				iterator_bus = iterator_bus->bus_next_bus;

			}

			// Иначе делаем перестановку "итератора" на его "место-вставки"...
			else {


				// Найдем "место перед удалением итератора" и сохраним его в эту переменную:
				mesto_pered_udaleniem_iterator = new bus_from_linear_doubly_linked_list;
				mesto_pered_udaleniem_iterator = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;
				while (mesto_pered_udaleniem_iterator->bus_next_bus != iterator_bus) {
					mesto_pered_udaleniem_iterator = mesto_pered_udaleniem_iterator->bus_next_bus;
				}


				// Если будем вставлять итератор на место первого элемента списка, то 
				// нужно сделать итератор первым элементом в списке (направить на него указатель first_bus)
				if (mesto_pered_vstavkoi_iterator->bus_next_bus == bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus) {
					bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus = iterator_bus;
				}


				// Сохраним "место после удаления итератора"
				mesto_posle_udaleniya_iterator = iterator_bus->bus_next_bus;


				// Вставляем итератор в выбранное место:
				iterator_bus->bus_next_bus = mesto_pered_vstavkoi_iterator->bus_next_bus;
				iterator_bus->bus_next_bus->bus_previous_bus = iterator_bus;
				iterator_bus->bus_previous_bus = mesto_pered_vstavkoi_iterator;
				mesto_pered_vstavkoi_iterator->bus_next_bus = iterator_bus;


				// Далее указатель итератора передвигается на следующий элемент в списке.
				// Передвинутый автобус при этом остается на новом месте:
				iterator_bus = mesto_posle_udaleniya_iterator;


				// Место перед удалением итератора должно отправлять на место после удаления,
				// если не написать эту строчку, то будет отправлять на новое место итератора:
				mesto_pered_udaleniem_iterator->bus_next_bus = mesto_posle_udaleniya_iterator;
				if (mesto_posle_udaleniya_iterator != NULL) mesto_posle_udaleniya_iterator->bus_previous_bus = mesto_pered_udaleniem_iterator;

			} // Конец блока "Иначе делаем перестановку "итератора" на его "место-вставки""

		} // Конец блока "Проходим весь список"


	} // Конец блока "Случай линейного двухсвязного списка"

	// Синхронизируем содержимое списка и файла хранения БД:

	// Линейный односвязный список:
	if (bs->bus_station_type_of_list == '1') save_all_buses_to_storage_file(bs->bus_station_buses_linear_singly_linked_list);

	// Линейный двухсвязный список:
	else save_all_buses_to_storage_file(bs->bus_station_buses_linear_doubly_linked_list);


} // Конец функции сортировки
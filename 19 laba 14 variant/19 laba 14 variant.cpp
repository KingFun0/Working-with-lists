//Индивидуальное задание :
//Реализовать следующие функции для работы с однонаправленным
//списком :
//-вывод всех элементов со значением больше заданного;	+
//-добавление элемента после каждого четного;		+
//-добавление элемента в начало списка;				+
//-вывод на экран только четных отрицательных элементов списка;	+
//-вывод суммы четных элементов списка на экран.		
//Работу программы реализовать с помощью меню.

#include <iostream>
using namespace std;
struct list
{
	int inf; 
	struct list* next; 
};
void add_last(list** head, int add_inf) {

	list* add = new list;
	add->inf = add_inf;
	add->next = NULL;

	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = add;
	}
	else *head = add;
}
void print_list(list** head) {
	list* ptr;
	ptr = *head;
	cout << "Список " << endl;
	if (ptr == NULL) cout << " пуст";
	else {
		while (ptr != NULL) {
			cout << ptr->inf << "  ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	cout << endl;
}
void add_first(list** head, int add_inf) {
	list* add = new list;
	add->inf = add_inf;

	if (*head != NULL) {
		add->next = *head;
		*head = add;
	}
	else {
		add->next = NULL;
		*head = add;

	}
	cout << endl;
}
void add_after_every_honest(list** head, int add_inf) {
	list *ptr;
	if (*head != NULL) {
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf % 2 == 0) {
				list* lala = new list;
				lala->inf = add_inf;
				lala->next = ptr->next;
				ptr->next = lala;
				ptr = ptr->next;
			}
			ptr = ptr->next;
		}
	}
	else {
		cout << "список пуст";
	}
	cout << endl;
}
void display_all_elements_with_a_value_greater_than_the_specified(list** head,int number) {
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf > number) {
				cout << ptr->inf << " ";
			}
			ptr = ptr->next;
		}
	}
	else {
		cout << "список пуст";
	}
	cout << endl;
}
void display_only_even_negative_elements_of_the_list(list** head) {
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf % 2 == 0) {
				if (ptr->inf < 0) {
					cout << ptr->inf << " ";
				}
			}
			ptr = ptr->next;
		}
	}
	else {
		cout << "список пуст";
	}
	cout << endl;
}
//-вывод суммы четных элементов списка на экран.
void displaying_the_sum_of_even_elements_of_a_list(list** head) {
	int sum = 0;
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf % 2 == 0) {
				sum += ptr->inf;
				
			}
			ptr = ptr->next;
		}
		cout << sum;
	}
	else {
		cout << "список пуст";
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	list** head = new list*;
	*head = NULL;
	while (true) {
		cout << "1. Добавление в начало " << endl;
		cout << "2. Добавление в конец " << endl;
		cout << "3.Добавление значения после каждого чётного " << endl;
		cout << "4.Вывод элементов со значением больше заданного " << endl;
		cout << "5.вывод на экран только четных отрицательных элементов списка " << endl;
		cout << "6.вывод суммы четных элементов списка на экран " << endl;
		cout << "7.Выход " << endl;
		int p;
		cin >> p;
		switch (p) {
		case 1: {
			int a;
			cout << "Введите добавляемое значение " << endl;
			cin >> a;
			add_first(head, a);
			print_list(head);
			break;
		}
		case 2: {
			int a;
			cout << "Введите добавляемое значение " << endl;
			cin >> a;
			add_last(head, a);
			print_list(head);
			break;
		}
		case 3: {
			int one;
			cout << "Введите добовляемое число: " << endl;
			cin >> one;
			add_after_every_honest(head, one);
			print_list(head);
			break;
		}
		case 4: {
			int number;
			cout << "Введите число: " << endl;
			cin >> number;
			display_all_elements_with_a_value_greater_than_the_specified(head, number);
			print_list(head);
			break;
		}
		case 5: {
			display_only_even_negative_elements_of_the_list(head);
			print_list(head);
			break;
		}
		case 6: {
			displaying_the_sum_of_even_elements_of_a_list(head);
			print_list(head);
			break;
		}
		case 7: {
			exit(0);
			break;
		}
		}
	}
}
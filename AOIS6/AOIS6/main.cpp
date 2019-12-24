#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;

struct hesh
{
	string id;
	int value;
	int hesh_code;
	bool collision;
	bool unaval;
	bool terminal;
	bool delining;
	hesh* next;
	string data;
};

int alpha(char);
int get_value(string);
int get_hesh(int, int);
void add_el(vector <hesh>&, string, string);
void del_el(vector <hesh>&, string);
void print_search_el(vector <hesh>, string);
void print_table(vector <hesh>);

int main()
{
	setlocale(LC_ALL, "Russian");
	vector <hesh> table;
	add_el(table, "������", "���������");
	add_el(table, "�����", "������");
	add_el(table, "�������", "��������");
	add_el(table, "���������", "���������");
	add_el(table, "����������", "��������");
	add_el(table, "�����", "������");
	add_el(table, "�����", "��������������");
	add_el(table, "������", "�����������");
	add_el(table, "����", "������");
	add_el(table, "�����", "��������");
	add_el(table, "�������", "���������");
	add_el(table, "����������", "��������");
	add_el(table, "��������� ���", "���������");
	add_el(table, "���������", "��������");
	add_el(table, "�����", "������");
	add_el(table, "����", "��������");
	add_el(table, "������", "��������");
	add_el(table, "�������", "��������");
	add_el(table, "��������", "������");
	add_el(table, "���������", "��������");
	add_el(table, "��� ���", "���������");
	add_el(table, "������������� ��������", "������");
	add_el(table, "������������", "���������");
	add_el(table, "������", "��������");
	print_table(table);
	del_el(table, "�����");
	cout << endl << endl;
	print_table(table);
	cout << endl;
	print_search_el(table, "������");
	cout << endl;
	system("pause");
	return 0;
}

int alpha(char symb)
{
	if (symb == '�' || symb == '�')
	{
		return 1;
	}
	else if (symb == '�' || symb == '�')
	{
		return 2;
	}
	else if (symb == '�' || symb == '�')
	{
		return 3;
	}
	else if (symb == '�' || symb == '�')
	{
		return 4;
	}
	else if (symb == '�' || symb == '�')
	{
		return 5;
	}
	else if (symb == '�' || symb == '�')
	{
		return 6;
	}
	else if (symb == '�' || symb == '�')
	{
		return 7;
	}
	else if (symb == '�' || symb == '�')
	{
		return 8;
	}
	else if (symb == '�' || symb == '�')
	{
		return 9;
	}
	else if (symb == '�' || symb == '�')
	{
		return 10;
	}
	else if (symb == '�' || symb == '�')
	{
		return 11;
	}
	else if (symb == '�' || symb == '�')
	{
		return 12;
	}
	else if (symb == '�' || symb == '�')
	{
		return 13;
	}
	else if (symb == '�' || symb == '�')
	{
		return 14;
	}
	else if (symb == '�' || symb == '�')
	{
		return 15;
	}
	else if (symb == '�' || symb == '�')
	{
		return 16;
	}
	else if (symb == '�' || symb == '�')
	{
		return 17;
	}
	else if (symb == '�' || symb == '�')
	{
		return 18;
	}
	else if (symb == '�' || symb == '�')
	{
		return 19;
	}
	else if (symb == '�' || symb == '�')
	{
		return 20;
	}
	else if (symb == '�' || symb == '�')
	{
		return 21;
	}
	else if (symb == '�' || symb == '�')
	{
		return 22;
	}
	else if (symb == '�' || symb == '�')
	{
		return 23;
	}
	else if (symb == '�' || symb == '�')
	{
		return 24;
	}
	else if (symb == '�' || symb == '�')
	{
		return 25;
	}
	else if (symb == '�' || symb == '�')
	{
		return 26;
	}
	else if (symb == '�' || symb == '�')
	{
		return 27;
	}
	else if (symb == '�' || symb == '�')
	{
		return 28;
	}
	else if (symb == '�' || symb == '�')
	{
		return 29;
	}
	else if (symb == '�' || symb == '�')
	{
		return 30;
	}
	else if (symb == '�' || symb == '�')
	{
		return 31;
	}
	else if (symb == '�' || symb == '�')
	{
		return 32;
	}
	else if (symb == '�' || symb == '�')
	{
		return 33;
	}
	else
	{
		return -9999999999;
	}
}
int get_value(string str)
{
	int value = 0;
	int range;
	if (str.size() >= 3)
	{
		range = 3;
	}
	else
	{
		range = str.size();
	}
	for (size_t i = 0; i < range; i++)
	{
		value += 33 * alpha(str[i]);
	}
	return value;
}
int get_hesh(int V, int B)
{
	int val = V % 10 + B;
	return val;
}
void add_el(vector <hesh>& ref, string id, string data)
{
	int val = get_value(id);
	int hsh = get_hesh(val, ref.size());
	hesh boof;
	bool is = false;

	for (size_t i = 0; i < ref.size(); i++)
	{
		if (hsh == ref[i].hesh_code)
		{
			ref[i].collision = true;
			hesh* ptr = &ref[i];
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new hesh;
			ptr = ptr->next;
			ptr->data = data;
			ptr->next = NULL;
			ptr->id = id;
			ptr->value = val;
			ptr->hesh_code = hsh;
			ptr->collision = true;
			ptr->unaval = true;
			ptr->terminal = 0;
			ptr->delining = false;
			is = true;
		}
	}
	if (!is)
	{
		boof.data = data;
		boof.next = NULL;
		boof.id = id;
		boof.value = val;
		boof.hesh_code = hsh;
		boof.collision = false;
		boof.unaval = true;
		boof.terminal = 0;
		boof.delining = false;
		ref.push_back(boof);
	}
}
void del_el(vector <hesh>& ref, string id)
{
	for (int i = 0; i < ref.size(); i++)
	{
		if (ref[i].collision == 1)
		{
			hesh* ptr = &ref[i];
			while (ptr->next != NULL)
			{
				if (ptr->next->id == id && ptr->next->next == NULL)
				{
					ptr->next = NULL;
				}
				else if (ptr->next->id == id && ptr->next->next != NULL)
				{
					ptr->next = ptr->next->next;
				}
				else
				{
					ptr = ptr->next;
				}
			}
		}
		else if (ref[i].id == id)
		{
			ref.erase(ref.begin() + i);
		}
	}
}
void print_search_el(vector <hesh> ref, string id)
{
	hesh srch;
	for (int i = 0; i < ref.size(); i++)
	{
		if (ref[i].collision == 1)
		{
			hesh* ptr = &ref[i];
			while (id != ptr->id && ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			if (id == ptr->id)
			{
				cout << ptr->data;
			}
		}
		else if (ref[i].id == id)
		{
			cout << ref[i].data;
		}
	}
}
void print_table(vector <hesh> ref)
{
	cout << "id" <<
		", " << "value" <<
		", " << "hesh_code" <<
		", " << "collision" <<
		", " << "unaval" <<
		", " << "terminal" <<
		", " << "delining" <<
		", " << "next" <<
		", " << "data" << endl << endl;
	for (size_t i = 0; i < ref.size(); i++)
	{
		cout << ref[i].id <<
			'\t' << ref[i].value <<
			'\t' << ref[i].hesh_code <<
			'\t' << ref[i].collision <<
			'\t' << ref[i].unaval <<
			'\t' << ref[i].terminal <<
			'\t' << ref[i].delining <<
			'\t' << ref[i].next <<
			'\t' << ref[i].data << endl;
		if (ref[i].next != NULL)
		{
			cout << endl <<
				"******************COLLISION SECTOR*******************" << endl;
			hesh* ptr;
			ptr = ref[i].next;
			while (ptr != NULL)
			{
				cout << ptr->id <<
					'\t' << ptr->value <<
					'\t' << ptr->hesh_code <<
					'\t' << ptr->collision <<
					'\t' << ptr->unaval <<
					'\t' << ptr->terminal <<
					'\t' << ptr->delining <<
					'\t' << ptr->next <<
					'\t' << ptr->data << endl;
				ptr = ptr->next;
			}
			cout << endl <<
				"*****************************************************" << endl;
		}
	}
}

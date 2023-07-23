#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <Windows.h> 

using namespace std;


struct Node
{
    string data;
    Node* next;
};

Node* Head = nullptr;
Node* tail = nullptr;
Node* boys = nullptr;
Node* girls = nullptr;

void Show_definetly_value_of_list(Node* node, int numder);
void addNode(Node*& head, Node*& tail, string name);
void removeNode(Node** node, int index);
void Create_list_and_Choise_list();
int find_kil_words(string filed);
void show_licilka(string filed);
void Create_List_Boys_Girls();
int kil_of_people(Node* node);
void Delete_List(Node* node);
//void Aplly_file_lichilks();
void Show_list(Node* node);


int main() {
    setlocale(LC_ALL, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool Index = true;

    int P = 0;

    Create_List_Boys_Girls();

    Create_list_and_Choise_list();
    Delete_List(Head);
    cout << endl << "Список був видалений" << endl;
}



void Create_list_and_Choise_list()
{
    ifstream File("file.txt");

    int choice;
    const int max_kil_of_Lichilk = 10;
    string counters[max_kil_of_Lichilk];
    string counter;
    int kil_of_Lichilk = 0;
    while (getline(File, counter) && kil_of_Lichilk < max_kil_of_Lichilk) {
        counters[kil_of_Lichilk] = counter;
        kil_of_Lichilk++;
    }
    File.close();

    cout << "Виберіть номер лічилки ( пам'ятайте про кількість ліилок = " << kil_of_Lichilk << " ):" << endl;
    cin >> choice;
    if (choice >= 1 && choice <= kil_of_Lichilk) {
        cout << "Обрана лічилка: " << endl;
        cout << counters[choice - 1] << endl;
    }
    else
    {
        cout << "Введіть коректрне значення";
    }
    string filed = counters[choice - 1];
    int kil_sign_before_last_word = 0;
    int kil_of_words = find_kil_words(filed);
    cout << "Кількість слів - " << kil_of_words << endl;
    int kil_people = kil_of_people(Head);
    cout << "Кількість людей - " << kil_people << endl;
    int index_number_name, k = 0;

    for (int i = 0; filed[i] != '\0'; i++)
    {
        if (filed[i] == ' ')
        {
            k++;
        }
        if (k != (kil_of_words - 1))
        {
            kil_sign_before_last_word++;
        }

    }
    Node* current = Head;
    int i;
    while (kil_people != 1)
    {
        show_licilka(filed);

        if (Head != NULL) {
            i = 0;
            do {
                if (i % kil_people == 0 && i != 0)
                {
                    current = Head;
                }
                cout << current->data << setw(8);
                current = current->next;
                i++;
            } while (i != kil_of_words);
        }
        current = Head;
        //виводимо список
        cout << endl;
        for (int i = 0; filed[i] != '\0'; i++)
        {
            if (i >= kil_sign_before_last_word)
            {
                cout << filed[i];
            }
        }
        cout << " - ";
        if (kil_of_words % kil_people == 0)
        {
            index_number_name = (kil_people - 1);
        }
        else
        {
            index_number_name = (kil_of_words % kil_people) - 1;
        }
        
        Show_definetly_value_of_list(Head, index_number_name);
        cout << "- вилучено";
        removeNode(&Head, index_number_name);
        kil_people--;
        cout << endl;
    }
    cout << "Залишився: " << Head->data;
    
}

void removeNode(Node** node, int index) 
{
    if (*node == nullptr) {
        return;
    }

    int size = 0;
    Node* current = *node;
    Node* prev = nullptr;

    while (size < index) {
        prev = current;
        current = current->next;
        size++;

        if (current == *node) {
            return; 
        }
    }
    if (current == *node) {
        *node = current->next;
    }

    if (prev != nullptr) {
        prev->next = current->next;
    }

    delete current;
}



void Create_List_Boys_Girls()
{
    int N;
    cout << "Введи кількість людей: ";  cin >> N;
    if (N <= 0) 
    {
        cout << "Невірне число" << endl;
        return;
    }
    int p;
    for (int i = 0; i < N; i++)
    {
        cout << "1 - хлопці, 0 - дівчата" << endl;
        cin >> p;
        string field;
        if (p == 1)
        { 
            cout << i + 1 << "-й" << endl;
            cout << "Ім'я: ";
            cin.ignore();
            cin >> field;
            addNode(Head, tail, field);
        }
        else
        {
            cout << i + 1 << "-й" << endl;
            cout << "Ім'я: ";
            cin.ignore();
            cin >> field;
            addNode(Head, tail, field);
        }
    }
}

void addNode(Node *&node, Node *&tail, string name)
{
    Node *temp = new Node;
    temp->data = name;
    temp->next = NULL;

    if (node == NULL) {
        node = temp;
        tail = temp;
        temp->next = node;
    }
    else {
        tail->next = temp;
        tail = temp;
        tail->next = node;
    }
}

void Delete_List(Node* node)
{
    if(node == nullptr) {
        return;
    }

    delete node;
}

int kil_of_people(Node* node)
{
    int i = 0;
    Node* current = node;

    do {
        i++;
        current = current->next;
    } while (current != node);
    return i;
}

void show_licilka(string filed)
{
    for (int i = 0; filed[i] != '\0'; i++)
    {
        if (filed[i] == ' ')
        {
            cout << setw(5);
        }
        else cout << filed[i];

    }
    cout << endl;
}

int find_kil_words(string filed)
{
    int kil_words = 0;
    for (int i = 0; filed[i] != '\0'; i++)
    {
        if (filed[i] == ' ')
        {
            kil_words++;
        }
    }
    kil_words++;
    return kil_words;
}

void Show_list(Node* node)
{
    Node* current = Head;

    if (Head == NULL) {
        cout << "Cписок порожній" << endl;
        return;
    }

    do {
        cout << current->data << "\t";
        current = current->next;
    } while (current != Head);
}

void Show_definetly_value_of_list(Node* node, int numder)
{
    Node* cur = Head;

    if (Head == NULL) {
        cout << "Cписок порожній" << endl;
        return;
    }
    int i = 0;
    do {
        if (i == numder)
        {
            cout << cur->data;
        }
        cur = cur->next;
        i++;
    } while (cur != Head);
}
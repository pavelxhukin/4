#include <string>
#include <iostream>
#include <vector>
using namespace std;

void star() {
    for (int i = 0; i < 87;i++) {
        cout << "-";
    }cout << endl;
}
class Yslyga {
private:
    string data1;
    string data2;
    string data3;
    int cena;

public:
    Yslyga() {}
    Yslyga(int m, string l, string t, string y) {
        cena = m;
        data2 = l;
        data3 = t;
        data1 = y;
    }
    int Cena() {
        return cena;
    }
    string ToString();
    void InitMyEntity();
};
string Yslyga::ToString() {
    string st = "";
    st = to_string(this->cena) + "\t" + this->data1 + "\t" + this->data2 + "\t" + this->data3;
    return st;
}
void Yslyga::InitMyEntity() {
    cout << "Enter cena: ";
    cin >> this->cena;
    cout << "Enter data1: ";
    cin >> this->data1;
    cout << "Enter data2: ";
    cin >> this->data2;
    cout << "Enter data3: ";
    cin >> this->data3;
}

class YsList {
private:
    vector<Yslyga> ysList;
    void Swap(Yslyga& l, Yslyga& m);

public:
    void AddElement(Yslyga data);
    void PrintAutolist();
    void InitList();
    void RemoveElement(int n);
    void sort();
    void sort2();
};
void YsList::AddElement(Yslyga data) {
    ysList.push_back(data);
}
void YsList::PrintAutolist() {
    int j = 0;
    star();
    vector<Yslyga>::iterator b = ysList.begin();
    vector<Yslyga>::iterator e = ysList.end();
    for (auto i = b; i != e; i++, j++) {
        cout << j << "\t" << (*i).ToString() << endl;
    }
    star();
}
void YsList::InitList() {
    Yslyga temp;
    temp.InitMyEntity();
    AddElement(temp);
}
void YsList::RemoveElement(int n) {
    auto b = ysList.begin();
    ysList.erase(b + n);
}
void YsList::Swap(Yslyga& l, Yslyga& m) {
    Yslyga temp = l;
    l = m;
    m = temp;
}
void YsList::sort() {
    int length = ysList.size();

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (ysList.at(j).Cena() > ysList.at(j + 1).Cena()) {
                Swap(ysList.at(j), ysList.at(j + 1));
            }
        }
    }
}
void YsList::sort2() {
    int length = ysList.size();

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (ysList.at(j).Cena() < ysList.at(j + 1).Cena()) {
                Swap(ysList.at(j), ysList.at(j + 1));
            }
        }
    }
}

int menu() {
    cout << "1. Выход" << endl;
    cout << "2. Добавить элемент" << endl;
    cout << "3. Отобразить" << endl;
    cout << "4. Удалить элемент" << endl;
    cout << "5. Сортировка <" << endl;
    cout << "6. Сортировка >" << endl;
    int i;
    cout << endl;
    cin >> i;
    cout << endl;
    return i;
}
int main()
{
    setlocale(LC_ALL, "ru");
    YsList list;
    int cs;
    int remove;
    do
    {
        cs = menu();
        switch (cs) {
        case 2:
            list.InitList();
            break;
        case 3:
            list.PrintAutolist();
            break;
        case 4:
            cout << "Номер элемента? ";
            cin >> remove;
            list.RemoveElement(remove);
            break;
        case 5:
            list.sort();
            break;
        case 6:
            list.sort2();
            break;
        default:
            break;
        }

    } while (cs != 1);

}
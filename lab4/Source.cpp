#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
using namespace std;

// Базовий клас НОСІЙ ДАНИХ
class NosiyDanyh {
protected:
    double obsyag; // Обсяг (Гбайт)
public:
    // Конструктор
    NosiyDanyh(double obsyag = 0) : obsyag(obsyag) {}

    // Віртуальний деструктор
    virtual ~NosiyDanyh() {}

    // Віртуальний метод для виведення інформації
    virtual void print(ostream& os) const {
        os << "Обсяг: " << obsyag << " Гбайт" << endl;
    }

    // Перевантаження оператора виведення
    friend ostream& operator<<(ostream& os, const NosiyDanyh& nosiy) {
        nosiy.print(os);
        return os;
    }

    // Перевантаження оператора введення
    friend istream& operator>>(istream& is, NosiyDanyh& nosiy) {
        cout << "Введіть обсяг (Гбайт): ";
        is >> nosiy.obsyag;
        return is;
    }
};

// Похідний клас ВІНЧЕСТЕР
class Vinchester : public NosiyDanyh {
private:
    int cylinders;  // Кількість циліндрів
    int tracks;     // Кількість доріжок
    int sectors;    // Кількість секторів
    string marka;   // Марка
public:
    // Конструктор
    Vinchester(double obsyag = 0, int cylinders = 0, int tracks = 0, int sectors = 0, string marka = "")
        : NosiyDanyh(obsyag), cylinders(cylinders), tracks(tracks), sectors(sectors), marka(marka) {}

    // Деструктор
    ~Vinchester() {}

    // Метод для виведення інформації
    void print(ostream& os) const override {
        NosiyDanyh::print(os); // Виклик базового методу
        os << "Циліндри: " << cylinders << endl
            << "Доріжки: " << tracks << endl
            << "Сектори: " << sectors << endl
            << "Марка: " << marka << endl;
    }

    // Перевантаження оператора введення
    friend istream& operator>>(istream& is, Vinchester& v) {
        is >> static_cast<NosiyDanyh&>(v); // Виклик базового оператора
        cout << "Введіть кількість циліндрів: ";
        is >> v.cylinders;
        cout << "Введіть кількість доріжок: ";
        is >> v.tracks;
        cout << "Введіть кількість секторів: ";
        is >> v.sectors;
        cout << "Введіть марку: ";
        is >> v.marka;
        return is;
    }
};

// Похідний клас ОПТИЧНИЙ ДИСК
class OptychnyyDysk : public NosiyDanyh {
private:
    int cylinders;  // Кількість циліндрів
    int tracks;     // Кількість доріжок
    int sectors;    // Кількість секторів
    string marka;   // Марка
public:
    // Конструктор
    OptychnyyDysk(double obsyag = 0, int cylinders = 0, int tracks = 0, int sectors = 0, string marka = "")
        : NosiyDanyh(obsyag), cylinders(cylinders), tracks(tracks), sectors(sectors), marka(marka) {}

    // Деструктор
    ~OptychnyyDysk() {}

    // Метод для виведення інформації
    void print(ostream& os) const override {
        NosiyDanyh::print(os); // Виклик базового методу
        os << "Циліндри: " << cylinders << endl
            << "Доріжки: " << tracks << endl
            << "Сектори: " << sectors << endl
            << "Марка: " << marka << endl;
    }

    // Перевантаження оператора введення
    friend istream& operator>>(istream& is, OptychnyyDysk& o) {
        is >> static_cast<NosiyDanyh&>(o); // Виклик базового оператора
        cout << "Введіть кількість циліндрів: ";
        is >> o.cylinders;
        cout << "Введіть кількість доріжок: ";
        is >> o.tracks;
        cout << "Введіть кількість секторів: ";
        is >> o.sectors;
        cout << "Введіть марку: ";
        is >> o.marka;
        return is;
    }
};

// Основна функція
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Vinchester v(500, 200, 20, 40, "Seagate");
    OptychnyyDysk o(50, 100, 10, 20, "Sony");

    // Запис інформації у файл
    ofstream file("data.txt");
    if (file.is_open()) {
        file << "Інформація про вінчестер:" << endl;
        file << v << endl;
        file << "Інформація про оптичний диск:" << endl;
        file << o << endl;
        file.close();
        cout << "Дані записані у файл 'data.txt'." << endl;
    }
    else {
        cout << "Помилка відкриття файлу!" << endl;
    }

    return 0;
}
 
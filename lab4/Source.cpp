#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
using namespace std;

// ������� ���� ��Ѳ� �����
class NosiyDanyh {
protected:
    double obsyag; // ����� (�����)
public:
    // �����������
    NosiyDanyh(double obsyag = 0) : obsyag(obsyag) {}

    // ³��������� ����������
    virtual ~NosiyDanyh() {}

    // ³��������� ����� ��� ��������� ����������
    virtual void print(ostream& os) const {
        os << "�����: " << obsyag << " �����" << endl;
    }

    // �������������� ��������� ���������
    friend ostream& operator<<(ostream& os, const NosiyDanyh& nosiy) {
        nosiy.print(os);
        return os;
    }

    // �������������� ��������� ��������
    friend istream& operator>>(istream& is, NosiyDanyh& nosiy) {
        cout << "������ ����� (�����): ";
        is >> nosiy.obsyag;
        return is;
    }
};

// �������� ���� ²�������
class Vinchester : public NosiyDanyh {
private:
    int cylinders;  // ʳ������ �������
    int tracks;     // ʳ������ ������
    int sectors;    // ʳ������ �������
    string marka;   // �����
public:
    // �����������
    Vinchester(double obsyag = 0, int cylinders = 0, int tracks = 0, int sectors = 0, string marka = "")
        : NosiyDanyh(obsyag), cylinders(cylinders), tracks(tracks), sectors(sectors), marka(marka) {}

    // ����������
    ~Vinchester() {}

    // ����� ��� ��������� ����������
    void print(ostream& os) const override {
        NosiyDanyh::print(os); // ������ �������� ������
        os << "�������: " << cylinders << endl
            << "������: " << tracks << endl
            << "�������: " << sectors << endl
            << "�����: " << marka << endl;
    }

    // �������������� ��������� ��������
    friend istream& operator>>(istream& is, Vinchester& v) {
        is >> static_cast<NosiyDanyh&>(v); // ������ �������� ���������
        cout << "������ ������� �������: ";
        is >> v.cylinders;
        cout << "������ ������� ������: ";
        is >> v.tracks;
        cout << "������ ������� �������: ";
        is >> v.sectors;
        cout << "������ �����: ";
        is >> v.marka;
        return is;
    }
};

// �������� ���� �������� ����
class OptychnyyDysk : public NosiyDanyh {
private:
    int cylinders;  // ʳ������ �������
    int tracks;     // ʳ������ ������
    int sectors;    // ʳ������ �������
    string marka;   // �����
public:
    // �����������
    OptychnyyDysk(double obsyag = 0, int cylinders = 0, int tracks = 0, int sectors = 0, string marka = "")
        : NosiyDanyh(obsyag), cylinders(cylinders), tracks(tracks), sectors(sectors), marka(marka) {}

    // ����������
    ~OptychnyyDysk() {}

    // ����� ��� ��������� ����������
    void print(ostream& os) const override {
        NosiyDanyh::print(os); // ������ �������� ������
        os << "�������: " << cylinders << endl
            << "������: " << tracks << endl
            << "�������: " << sectors << endl
            << "�����: " << marka << endl;
    }

    // �������������� ��������� ��������
    friend istream& operator>>(istream& is, OptychnyyDysk& o) {
        is >> static_cast<NosiyDanyh&>(o); // ������ �������� ���������
        cout << "������ ������� �������: ";
        is >> o.cylinders;
        cout << "������ ������� ������: ";
        is >> o.tracks;
        cout << "������ ������� �������: ";
        is >> o.sectors;
        cout << "������ �����: ";
        is >> o.marka;
        return is;
    }
};

// ������� �������
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Vinchester v(500, 200, 20, 40, "Seagate");
    OptychnyyDysk o(50, 100, 10, 20, "Sony");

    // ����� ���������� � ����
    ofstream file("data.txt");
    if (file.is_open()) {
        file << "���������� ��� ��������:" << endl;
        file << v << endl;
        file << "���������� ��� �������� ����:" << endl;
        file << o << endl;
        file.close();
        cout << "��� ������� � ���� 'data.txt'." << endl;
    }
    else {
        cout << "������� �������� �����!" << endl;
    }

    return 0;
}
 
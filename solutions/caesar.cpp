#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstring source;
    wcout << L"Введите фразу для шифрования/расшифрования: ";
    getline(wcin, source);

    int shift;
    wcout << L"Введите сдвиг (вправо - положительный, влево - отрицательный): ";
    wcin >> shift;
    shift = shift % 32;

    wstring opType;
    wcout << L"Хотите зашифровать (0), или расшифровать (1) фразу: ";
    wcin >> opType;

    if (opType == L"0") {
        for (wchar_t& letter : source) {
            if (letter >= L'А' && letter <= L'Я') {
                letter = L'А' + ((letter - L'А' + shift + 32) % 32);
            } else if (letter >= L'а' && letter <= L'я') {
                letter = L'а' + ((letter - L'а' + shift + 32) % 32);
            }
        }
        wcout << L"Зашифрованная фраза: " << source << endl;
    } else if (opType == L"1") {
        for (wchar_t& letter : source) {
            if (letter >= L'А' && letter <= L'Я') {
                letter = L'А' + ((letter - L'А' - shift + 32) % 32);
            } else if (letter >= L'а' && letter <= L'я') {
                letter = L'а' + ((letter - L'а' - shift + 32) % 32);
            }
        }
        wcout << L"Расшифрованная фраза: " << source << endl;
    }
    else {
        wcout << L"Неверный ввод операции";
    }

    return 0;
}

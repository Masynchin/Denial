#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> to_digits(int number) {
    vector<int> digits;
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

vector<int> input() {
    while (true) {
        int number;
        cout << "Введите трёхзначное число: ";
        cin >> number;
        auto digits = to_digits(number);
        if (digits.size() == 3) {
            return digits;
        } else {
            cout << "Не трёхзначное число. Попробуйте снова" << endl;
            cout << endl;
        }
    }
}

bool is_sum_two_wide(vector<int> digits) {
    auto sum = accumulate(digits.begin(), digits.end(), decltype(digits)::value_type(0));
    return to_digits(sum).size() == 2;
}

bool is_product_three_wide(vector<int> digits) {
    auto product = accumulate(digits.begin(), digits.end(), 1, multiplies<int>());
    return to_digits(product).size() == 3;
}

string humanize(bool boolean) {
    if (boolean) {
        return "Да";
    } else {
        return "Нет";
    }
}

int main() {
    auto digits = input();

    cout
        << "Сумма цифр - двузначное число: "
        << humanize(is_sum_two_wide(digits))
        << endl
        << "Произведение цифр - трёхзначное число: "
        << humanize(is_product_three_wide(digits))
        << endl;

    return 0;
}

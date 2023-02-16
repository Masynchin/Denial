#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> input_heights(string filename) {
    vector<int> numbers;
    fstream myfile(filename);

    int number;
    while (myfile >> number) {
        numbers.push_back(number);
    }

    return numbers;
}

string input_filename() {
    string filename;
    cout << "Введите название файла с числами: ";
    cin >> filename;

    return filename;
}

int max_number(vector<int> numbers) {
    return *max_element(numbers.begin(), numbers.end());
}

void print_bars(vector<int> heights) {
    auto max_height = max_number(heights);
    for (auto i = max_height; i > 0; i--) {
        for (auto height: heights) {
            if (i <= height) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    print_bars(input_heights(input_filename()));

	return 0;
}

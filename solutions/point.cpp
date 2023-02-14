#include <cmath>
#include <iostream>

using namespace std;

class Point {
    private:
        int x;
        int y;

    public:
        // Начало координат
        Point(): Point(0, 0) {};
        // Точка на оси ОХ
        Point(int x): Point(x, 0) {};
        // Произвольная точка
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        };

        // Вывод на экран
        void print() {
            cout << "Point(" << x << ", " << y << ")" << endl;
        };

        // Радиус-вектор
        double radius() {
            return sqrt(pow(x, 2) + pow(y, 2));
        }

        // Угол наклона к оси ОХ (в радианах)
        double angle() {
            return atan2(y, x);
        }
};

int main() {
    // Здравствуйте, конструкторы!
	Point().print();
	Point(1).print();
	Point(1, 1).print();

    // Здравствуйте, мистер Радиус-Вектор!
    cout << Point(3, 4).radius() << endl;

    // Здравствуйте, мистер Угол!
    cout << Point(2, 2).angle() << endl;

	return 0;
}

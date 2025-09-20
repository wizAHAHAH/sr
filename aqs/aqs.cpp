#include <iostream>
#include <string>

class Entity {
protected:
	float x, y; // Координаты объекта
	std::string name; // Имя объекта
public:
	Entity(float x_pos, float y_pos, std::string obj_name)
		: x(x_pos), y(y_pos), name(obj_name) {}
	void Move(float dx, float dy) {
		x += dx;
		y += dy;
	}

	void Print() const {  // Вывод информации
		std::cout << name << " at (" << x << ", " << y << ")" << std::endl;
	}

	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
	std::string getName() const {
		return name;
	}
};

int main()
{
 
}


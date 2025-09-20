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

class Wizard : public Entity {
private:
	int mana;
	int health;
public:
	Wizard(float x_pos, float y_pos, std::string w_name, int w_mana, int w_health)
		: Entity(x_pos, y_pos, w_name), mana(w_mana), health(w_health) {}
	void castSpell() {
		if (mana >= 10) {
			mana -= 10;
			std::cout << name << " использование заклинания!" << std::endl;
		}
		else {
			std::cout << name << " недостаточно маны!" << std::endl;
		}
	}

	int getMana() const {
		return mana;
	}
	int getHealth() const {
		return health;
	}
};

int main()
{
 
}


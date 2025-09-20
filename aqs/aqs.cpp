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
	int mana; // Кол-во маны
	int health; // Здоровье
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

class Resource : public Entity {
private:
	std::string type; // Тип ресурса
	int count; // Количество
public:
	Resource(float x_pos, float y_pos, std::string r_name, std::string r_type, int cnt)
		: Entity(x_pos, y_pos, r_name), type(r_type), count(cnt) {}
	
	void collect() {
		count = 0;
		std::cout << name << " собрано!" << std::endl;
	}
	std::string getType() const {
		return type;
	}
	int getCount() const {
		return count;
	}
};

class Spell {
private:
	std::string name; // Название заклинания
	int mana_cost; // Стоимость маны
public:
	Spell(std::string s_name, int cost) : name(s_name), mana_cost(cost){}
	void Use(Wizard& wizard) {
		if (wizard.getMana() >= mana_cost) {
			std::cout << wizard.getName() << " использует способность: " << name << std::endl;
		}
	}

	int getManaCost() const {
		return mana_cost;
	}
	std::string getName() const {
		return name;
	}
};

class Inventory {
private:
	int herb_count; // Кол-во трав
	int max_capacity; // Макс вместимость
public:
	Inventory(int cap) : herb_count(0), max_capacity(cap) {}
	void addHerb(int cnt) {
		herb_count += cnt;
		if (herb_count > max_capacity)
			herb_count = max_capacity;
	}

	int getHerbCount() const {
		return herb_count;
	}
	bool isFull() const {
		return herb_count >= max_capacity;
	}
	
};
class Location {
private:
	std::string name; // Название локации
	int resource_count; // Кол-во ресурсов;
public:
	Location(std::string loc_name, int res_count)
		: name(loc_name), resource_count(res_count) {}
	void addResource() {
		resource_count++;
		std::cout << "Добавлен ресурс в " << name << std::endl;
	}

	void Print() const {
		std::cout << "Локация: " << name << ",ресурсы: " << resource_count << std::endl;
	}

	int getResourceCount() const {
		return resource_count;
	}
};


int main()
{
 
}


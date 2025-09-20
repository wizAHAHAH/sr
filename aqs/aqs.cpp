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

class Minion : public Entity {
private:
	int health; // Здоровье
	std::string owner; // Владелец
public:
	Minion(float x_pos, float y_pos, std::string m_name, int m_health, std::string w_name)
		: Entity(x_pos, y_pos, m_name), health(m_health), owner(w_name) {}
	
	void Follow() {
		std::cout << name << " следует за " << owner << std::endl;
	}
	
	int getHealth() const {
		return health;
	}
};

// Создание персонажа
Wizard CreateWizard(float x, float y, std::string name, int mana, int health) {
	return(x, y, name, mana, health);
}

// Исопльзование заклинания
void useSpell(Wizard& wizard, Spell& spell) {
	spell.Use(wizard);
}

// Сбор ресурса
void collectResource(Wizard& wizard, Resource& resource) {
	std::cout << wizard.getName() << " собирает " << resource.getType() << std::endl;
	resource.collect();
}

// Добавление ресурса в инвентарь
void addToInventory(Inventory& inv, Resource& res) {
	inv.addHerb(res.getCount());
}

Minion CreateMinion(float x, float y, std::string name, int health, std::string owner) {
	return Minion(x, y, name, health, owner);
}

int main()
{
	Wizard staticWizard(10, 20, "Shadow Wizard", 50, 100);
	Resource staticResource(30, 40, "Трава1", "трава", 5);
	Inventory staticInventory(10);
	Spell staticSpell("Призыв", 10);
	Location staticLocation("Замок", 2);
	Minion staticMinion(50, 60, "Скелет", 20, "Shadow Wizard");

	staticWizard.Print();
	staticWizard.Move(5, 5);
	staticWizard.Print();
	collectResource(staticWizard, staticResource);
	addToInventory(staticInventory, staticResource);
	useSpell(staticWizard, staticSpell);
	staticLocation.Print();
	staticMinion.Follow();
}


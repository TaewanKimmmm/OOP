/*
1. ���� �� ���� ������.
2. �츮�� ��ǥ�� ���Ѵ�. (1~2�ð� �ȿ� �Ϸ� �� �� �ִ� ����)
3. Brainstorming(�극�ν����)�� ���� �� ��ǥ�� �°� ���� task�� �ɰ���. (�� �� �ȿ� �Ϸ��� �� �ִ� ����)
4. � task�� ���� ����, � ������ ���������� ���� ����Ѵ�.
5. �˶��� ���߰� ���� �������� ��Driver-Navigator���� �Ǿ� �����Ѵ�.
6. Task�� �Ϸ��ϸ� ��Ͽ��� ����� �ʿ��� task�� �߰�/���� �ϰ� ���� Task�� ���� �Ͽ� �����Ѵ�.
7. 5~6�� ������ �ݺ��Ѵ�.


- ��ǥ : �ǽ�1~3 �Ϸ� (decorator pattern ���� �� ����)
	�ǽ� 1) java�ڵ带 �м��Ͽ� decorator pattern�� ���� �����Ѵ�.
	�ǽ� 2) java�ڵ带 c++ �ڵ�� �����Ͽ� decorator pattern�� �����Ѵ�.
	�ǽ� 3) ����� size�� �߰��ϰ�, size�� ���� cost�� �ٸ��� ����ϴ� ����� �����Ѵ�.


- task
1. �ǽ�1) �ڵ�м� ����
2. �ǽ�2) Java�ڵ带 C++ �ڵ�� �����Ͽ� Decorator Pattern�� ����
3. �ǽ�3) ����� size�� �߰��ϰ� size�� ���� cost�� �ٸ��� ���

1. �ǽ�1) �ڵ�м�
Beverage�� �߻� Ŭ������ ����Ǹ�, cost() �޼ҵ�� �߻�޼ҵ�� �����.

Beverage�� ��ӹ޴� Ŭ���� : DarkRoast, Decaf, Espresso, HouseBlend, CondimentDecorator
CondimentDecorator�� ��ӹ޴� Ŭ����:  Milk, Mocha, Soy, Whip

Beverage Ŭ������ CondimentDecorator�� �߻� Ŭ�����̴�.

���� Beverage�� �ٸ� Ŭ������ ��ӹ���.
CondimentDecorator�� ����� ������ Ŭ������� ������,
decorator�� ������ Ŭ������ ��� CondimentDecorator�� ��ӹ޴´�.
��ӹ޴� �� Ŭ������ ��� description���� ������ �̸��� ��Ÿ����,
������ ���ݿ� �°� cost()�� �����ϰ�
Decorator�� ��� beverage�� �߰������� �����ϰ� �ȴ�.

2. Java �ڵ带 C++ �ڵ�� �����Ͽ� ���� / 3. ����� Size�� �߰��ϰ� Size�� ���� Cost�� �ٸ��� ���
 1) ���� ����		Driver: ���¿�
 2) Decorator ����	Driver: �Ӽ���
 3) Size ����		Driver: ������

*/

#include <string>
#include <iostream>

enum BeverageSize {
	TALL,
	GRANDE,
	VENTI,
};

class Beverage {
protected:
	std::string description = "Unknown Beverage";
	BeverageSize size;

public:

	virtual std::string getDescription() {
		return description;
	}

	virtual double cost() = 0;

	void displayDescription() {
		std::cout << getDescription() << std::endl;
		std::cout << cost() << std::endl;
	}

	BeverageSize getSize(){
		return size;
	}

	void setSize(BeverageSize size){
		this->size = size;
	}

	virtual ~Beverage() {}
};

class DarkRoast : public Beverage {
public:
	DarkRoast(BeverageSize size) {
		description = "DarkRoast";
		setSize(size);
	}

	double cost() {
		if (getSize() == TALL)
			return .89;
		else if (getSize() == GRANDE)
			return .99;
		else if (getSize() == VENTI)
			return 1.09;
	}
};

class Decaf : public Beverage {
public:
	Decaf(BeverageSize size) {
		description = "Decaf";
		setSize(size);
	}

	double cost() {
				if (getSize() == TALL)
			return .95;
		else if (getSize() == GRANDE)
			return 1.05;
		else if (getSize() == VENTI)
			return 1.15;
	}
};

class Espresso : public Beverage {
public:
	Espresso(BeverageSize size) {
		description = "Espresso";
		setSize(size);
	}

	double cost() {
		if (getSize() == TALL)
			return 1.89;
		else if (getSize() == GRANDE)
			return 1.99;
		else if (getSize() == VENTI)
			return 2.09;
	}
};

class HouseBlend : public Beverage {
public:
	HouseBlend(BeverageSize size) {
		description = "HouseBlend";
		setSize(size);
	}

	double cost() {
		if (getSize() == TALL)
			return .79;
		else if (getSize() == GRANDE)
			return .89;
		else if (getSize() == VENTI)
			return .99;
	}
};

class CondimentDecorator : public Beverage {
protected:
	Beverage* beverage;
public:
	CondimentDecorator(Beverage* beverage) {
		this->beverage = beverage;
	}
	~CondimentDecorator()
	{
		delete beverage;
	}
};

class Milk : public CondimentDecorator {
public:
	Milk(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Milk";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.05;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.10;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.15;
	}
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Mocha";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.15;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.20;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.25;
	}
};

class Soy : public CondimentDecorator {
public:
	Soy(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Soy";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.1;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.15;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.2;
	}
};

class Whip : public CondimentDecorator {
public:
	Whip(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Whip";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + 0.05;
		else if (getSize() == GRANDE)
			return beverage->cost() + 0.10;
		else if (getSize() == VENTI)
			return beverage->cost() + 0.15;
	}
};

int main (){
	Beverage* bever1 = new DarkRoast(TALL);
	bever1 = new Milk(bever1);
	bever1 = new Mocha(bever1);
	bever1 = new Milk(bever1);
	bever1->displayDescription();

	Beverage* bever2 = new Espresso(GRANDE);
	bever2 = new Milk(bever2);
	bever2 = new Milk(bever2);
	bever2 = new Milk(bever2);
	bever2->displayDescription();

	Beverage* bever3 = new HouseBlend(VENTI);
	bever3 = new Whip(bever3);
	bever3 = new Milk(bever3);
	bever3 = new Soy(bever3);
	bever3 = new Mocha(bever3);
	bever3->displayDescription();

	return 0;
}
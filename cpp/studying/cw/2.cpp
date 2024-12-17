#include <iostream>

using namespace std;

class MoneyBox 
{
    private:
        unsigned int nums, vals;
    public:
        MoneyBox()
        {
            this->nums = 0;
            this->vals = 0;
        }

        MoneyBox(int nums, unsigned int value)
        {
            this->nums = nums;
            this->vals = vals;
        }

        // Добавить монетку достоинством value
        void addCoin(unsigned int value)
        {
            this->nums += 1;
            this->vals += value;
        }

        // Получить текущее количество монеток в копилке
        unsigned int getCoinsNumber() const
        {
            return this->nums;
        }

        // Получить текущее общее достоинство всех монеток
        unsigned int getCoinsValue() const
        {
            return this->vals;
        }
};

int main()
{
    MoneyBox m;

    // Добавили монетку достоинством 10
    m.addCoin(10);

    // Добавили монетку достоинством 5
    m.addCoin(5);

    // Ожидаем, что монеток внутри 2 штуки
    cout << m.getCoinsNumber() << endl;
    
    // Ожидаем, что общее достоинство всех монеток 15
    cout << m.getCoinsValue() << endl;
}
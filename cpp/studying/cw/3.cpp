#include <iostream>

class GasStation 
{
    protected:
        unsigned int capacity;
        unsigned int curent;
    public:
        GasStation(unsigned int capacity): capacity(capacity), curent(0) {} 
    
        void fill(unsigned int n) 
        {
            if (curent + n <= capacity)
                curent += n;
            else
                throw std::exception();
        }
        
        void tank(unsigned int n) 
        {
            if (curent >= n) 
                curent -= n;
            else 
                throw std::exception();
        }
        
        unsigned int get_limit() const 
        {
            return curent;
        }
};

int main() 
{
    GasStation s = GasStation(1000); // Колонка на 1000, пока пустая
    s.fill(300); // Это влезет в резервуар,
    std::cout << s.get_limit() << std::endl; // ... так что здесь увидим на экране 300.

    s.tank(100);                             // Забрали из резервуара 100,
    s.fill(300);                             // ... после чего долили ещё 300,
    std::cout << s.get_limit() << std::endl; // ... так что на экране ожидаем 500.

    for(unsigned int i = 0; i < 5; i++) // В цикле забрали 5 раз по 50,
        s.tank(50);
    std::cout << s.get_limit() << std::endl; // ... так что на экране ожидаем 250.

    for(unsigned int i = 0; i < 50; i++) { // Теперь пытаемся забрать 50 раз по 100,
        s.tank(100);                       // из-за чего на третьей попытке ждём exception.
        std::cout << s.get_limit() << std::endl;
    }

    return 0;
}
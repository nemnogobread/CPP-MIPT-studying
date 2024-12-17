#include <iostream>

using namespace std;

class Module 
{
    public:
        // Получить имя модуля
        virtual string getName() const = 0;

        // Запустить модуль
        virtual void run() = 0;
};

class ModuleA : public Module 
{
    public:
        string getName() const 
        {
            return "moduleA";
        }

        void run() 
        {
            cout << "ModuleA runs" << endl;
        }
};

class ModuleB : public Module 
{
    public:
        string getName() const 
        {
            return "moduleB";
        }
        
        void run() 
        {
            cout << "ModuleB runs" << endl;
        }
};

class Dispatcher {
    protected:
        int _size;
        int _cur;
        Module** _modules;
    public:
        Dispatcher(): _size(10), _cur(0), _modules(NULL) {_modules = new Module*[10];}
        
        // Зарегистрировать переданный модуль
        void registerModule(Module* m) 
        {
            if (_cur < _size) 
            {
                _modules[_cur] = m;
                _cur++;
                cout << m->getName() << " registred." << endl;
            } 
            else 
            {
                cout << "Dispatcher is full." << endl;
            }
        }
        
        // Вызвать метод run для модуля с именем moduleName
        // Если такого модуля не зарегистрировано, ничего не делать (но не падать)
        void runModule(const string moduleName) const 
        {
            for (int i = 0; i < _cur; i++) 
            {
                if (_modules[i]->getName() == moduleName) 
                {
                    _modules[i]->run();
                }
            }
        }
};

int main() 
{
    Module* m1 = new ModuleA();
    Module* m2 = new ModuleB();

    Dispatcher d;
    d.registerModule(m1);
    d.registerModule(m2);
    d.runModule("moduleA");
    d.runModule("moduleB");
    d.runModule("moduleC");
    
    delete m1;
    delete m2;
    
    return 0;
}

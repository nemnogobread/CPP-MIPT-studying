#include <iostream>
#include <string>
using namespace std;

class Student 
{
    public:
        void setName(string name) 
        {
            name_ = name;
        }

        void setScore(unsigned int score) 
        {
            score_ = score;
        }

        string getName() const 
        {
            return name_;
        }

        unsigned int getScore() const 
        {
            return score_;
        }

    private:
        string name_;
        unsigned score_ = 0;

    friend istream& operator>> (istream& stream, Student& st);
    friend ostream& operator<< (ostream& stream, Student& st);
};


istream& operator>> (istream& stream, Student& st) 
{
    getline(stream, st.name_);
    return stream;
}

ostream& operator<< (ostream& stream, Student& st) 
{
    stream << "'" << st.name_ << "' : " << st.score_;
    return stream;
}

int main() 
{
    Student s;
    cin >> s;
    s.setScore(10);
    cout << s << endl;
    return 0;
}
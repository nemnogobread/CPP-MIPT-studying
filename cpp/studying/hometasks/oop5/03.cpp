#include <iostream>
using namespace std;

class VectorN {
    public:
        VectorN(unsigned int n) 
        {
            size_ = n;
            arr_ = new unsigned int[n];
        }

        VectorN() : VectorN(0) {}

        ~VectorN() 
        {
            delete[] arr_;
        }

        unsigned int getSize() const 
        {
            return size_;
        }

        int getValue(unsigned int i) const 
        {
            return arr_[i];
        }

        void setValue(unsigned int i, int value) 
        {
            arr_[i] = value;
        }

        bool operator==(const VectorN& rhs) const 
        {
            if(size_ != rhs.size_) return false;
            for(int i = 0; i < size_; i++) 
            {
                if(arr_[i] != rhs.arr_[i])
                    return false;
            }
            return true;
        }

        bool operator!=(const VectorN& rhs) const 
        {
            return !(*this == rhs);
        }

        VectorN operator+(const VectorN& rhs) const 
        {
            VectorN res(size_);
            for(int i = 0; i < rhs.size_; i++)
                res.arr_[i] = arr_[i] + rhs.arr_[i];
            return res;
        }

        VectorN operator-(const VectorN& rhs) const 
        {
            VectorN res(size_);
            for(int i = 0; i < rhs.size_; i++)
                res.arr_[i] = arr_[i] + rhs.arr_[i];
            return res;
        }

        VectorN operator*(const int rhs) const 
        {
            VectorN res(size_);
            for(int i = 0; i < size_; i++)
                res.arr_[i] = arr_[i] * rhs;
            return res;
        }

    friend VectorN operator*(const int lhs, const VectorN& rhs);

    private:
        unsigned int size_;
        unsigned int* arr_;
};

VectorN operator* (const int lhs, const VectorN& rhs) 
{
    return rhs * lhs;
}

int main() 
{
	VectorN a(4);
	a.setValue(0, 0);
	a.setValue(1, 1);
	a.setValue(2, 2);
	a.setValue(3, 3);

	VectorN b(4);
	b.setValue(0, 0);
	b.setValue(1, -1);
	b.setValue(2, -2);
	b.setValue(3, -3);

	cout << (a == b) << endl;
	cout << (a != b) << endl;

	VectorN c = a + b;
	VectorN d = 5 * c;

	for(int i = 0; i < a.getSize(); i++)
	    cout << d.getValue(i) << endl;

	return 0;
}
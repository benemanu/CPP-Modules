#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T> 
class Array {
    private:

    T*              _head;
    unsigned int    _size;

    public:

    Array() {
        _head = nullptr;
        _size = 0;
    }
    Array(unsigned int n) {
        _head = nullptr,
        _size = n;
    }
    Array(const Array &copy) {

    }
    ~Array() {

    }
    Array &operator =(const Array &copy) {

    }
    T &operator[](unsigned int index) {

    }
    
    class ArrayOutOfBoundsException: public std::exception {
		virtual const char *what() const throw() {
			return ("Array out of bounds exception.");
		}
	};
};

#endif
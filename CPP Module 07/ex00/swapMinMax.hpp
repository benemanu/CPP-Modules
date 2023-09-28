#ifndef SWAPMINMAX_HPP
#define SWAPMINMAX_HPP

template<class T> void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T> T min(T& a, T& b) {
    if (a > b)
        return (b);
    else if (a == b)
        return (b);
    else 
        return (a);
}

template<class T> T max(T& a, T& b) {
    if (a > b)
        return (a);
    else if (a == b)
        return (b);
    else 
        return (b);
}

#endif
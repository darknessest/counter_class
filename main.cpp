#include <iostream>

using namespace std;

//template<class A>
//class counter {
// private:
//
//    long integer;
//    double fraction;
// public:
//    counter() {
//        integer = 0;
//        fraction = 0.0;
//    }
//    template<typename T>
//
//    explicit counter(const T &x) {
//        if (typeid(T) == typeid(double) || typeid(T) == typeid(float)) {
//            integer = (long) x;
//            fraction = x - integer;
//            if (fraction < 0)
//                fraction *= -1;
//        } else {
//            integer = x;
//            fraction = 0;
//        }
//    }
//
//    A operator+(const counter &a) {
//        return a.integer + integer;
//    }
//    template<typename TT>
//    friend counter operator-(const counter<TT> &, const counter<TT> &);
//    friend counter operator*(const counter &a, const counter &b);
//    friend counter operator/(const counter &a, const counter &b);
//
////    template <typename TT,typename BB>
////    friend counter<TT> operator +(const counter<TT>&, const counter<BB>&);
//
////    double operator-(counter const &x) {
//////        return val - x.val;
////    }
////    double operator/(counter const &x) {
//////        return val/x.val;
////    }
////    double operator*(counter const &x) {
//////        return val*x.val;
////    }
//    friend ostream &operator<<(ostream &out, const counter &a);
////    friend istream &operator>>(istream &in, T &a);
//};
//template<typename A>
//ostream &operator<<(ostream &out, const counter<A> &a) {
//    out << a.integer + a.fraction;
//    return out;
//}

//template <class A>
//counter<A> operator-(const counter<A> &a, const counter<A> &b) {
//    counter temp{0};
//    temp.integer = a.integer - b.integer;
//    temp.fraction = (a.fraction - b.fraction) > 0 ? a.fraction - b.fraction : (1 + a.fraction - b.fraction);//integer--
//    return temp;
//}

template<typename T>
class xda {
 private:
    T val;
 public:
    xda() {
        val = 0.0;
    }
    explicit xda(const T &x) : val(x) {}

    xda<T> &operator=(const xda<T> &);

    template<typename TT, typename BB, typename CC>
    friend xda<CC> operator+(const xda<TT> &, const xda<BB> &);
    template<typename TT, typename BB>
    friend xda<TT> operator-(const xda<TT> &, const xda<BB> &);
    template<typename TT, typename BB>
    friend xda<TT> operator*(const xda<TT> &, const xda<BB> &);
    template<typename TT, typename BB>
    friend xda<TT> operator/(const xda<TT> &, const xda<BB> &);

    template<typename U>
    // class T : public U
    operator xda<U>() const {
        return xda<U>(val);
    }

    template<typename TT>
    friend ostream &operator<<(ostream &out, const xda<TT> &);
};
template<typename T>
ostream &operator<<(ostream &out, const xda<T> &a) {
    out << a.val;
    return out;
}

template<typename T, typename B, typename C>
xda<C> operator+(const xda<T> &a, const xda<B> &b) {
    if (typeid(B) == typeid(double))
        return xda<B>(a.val + b.val);
    return xda<T>(a.val + b.val);
}
template<typename T, typename B>
xda<T> operator-(const xda<T> &a, const xda<B> &b) {
    return xda<T>(a.val - b.val);
}
template<typename T, typename B>
xda<T> operator*(const xda<T> &a, const xda<B> &b) {
    return xda<T>(a.val*b.val);
}
template<typename T, typename B>
xda<T> operator/(const xda<T> &a, const xda<B> &b) {
    return xda<T>(a.val/b.val);
}

template<typename T>
xda<T> &xda<T>::operator=(const xda<T> &ti) {
    if (this != &ti) {
        val = ti.val;
    }
    return *this;
}

int main() {
    xda a{1.2};
    xda b{2};
    xda c{0};
    cout << (b + a) << endl;

//    counter a(3.123);
//    counter b(11);
//    cout << a + b;
}
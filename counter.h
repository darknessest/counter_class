#include <cmath>

#define PI 3.14159265358979323

template<typename T>
class counter {
 private:
    T val;
 public:
    counter() {
        val = 0.0;
    }
    explicit counter(const T &x) : val(x) {}

    template<typename TT>
    friend std::ostream &operator<<(std::ostream &out, const counter<TT> &);
    template<typename TT>
    friend std::istream &operator>>(std::istream &in, counter<TT> &);

    counter<T> &operator=(const counter<T> &);
    template<typename UU>
    counter<T> &operator=(const UU &);

    //  +
    template<typename TT, typename BB>
    friend counter<TT> operator+(const counter<TT> &, const counter<BB> &);
    template<typename UU>
    counter<T> inline operator+(const UU &);
    template<typename TT, typename UU>
    friend inline UU operator+(const UU &, const counter<TT> &);
    //  -
    template<typename TT, typename BB>
    friend counter<TT> operator-(const counter<TT> &, const counter<BB> &);
    template<typename UU>
    counter<T> inline operator-(const UU &);
    template<typename TT, typename UU>
    friend inline UU operator-(const UU &, const counter<TT> &);
    //  *
    template<typename TT, typename BB>
    friend counter<TT> operator*(const counter<TT> &, const counter<BB> &);
    template<typename UU>
    counter<T> inline operator*(const UU &);
    template<typename TT, typename UU>
    friend inline UU operator*(const UU &, const counter<TT> &);
    //  /
    template<typename TT, typename BB>
    friend counter<TT> operator/(const counter<TT> &, const counter<BB> &);
    template<typename UU>
    counter<T> inline operator/(const UU &);
    template<typename TT, typename UU>
    friend inline UU operator/(const UU &, const counter<TT> &);

    //  ==
    template<typename TT, typename BB>
    friend inline bool operator==(const counter<TT> &lhs, const counter<BB> &rhs);
    template<typename TT, typename UU>
    friend inline bool operator==(const counter<TT> &lhs, const UU &x);
    template<typename TT, typename UU>
    friend inline bool operator==(const UU &x, const counter<TT> &rhs);
    //  !=
    template<typename TT, typename BB>
    friend inline bool operator!=(const counter<TT> &lhs, const counter<BB> &rhs);
    template<typename TT, typename UU>
    friend inline bool operator!=(const counter<TT> &lhs, const UU &x);
    template<typename TT, typename UU>
    friend inline bool operator!=(const UU &x, const counter<TT> &rhs);
    //  <
    template<typename TT, typename BB>
    friend inline bool operator<(const counter<TT> &lhs, const counter<BB> &rhs);
    template<typename TT, typename UU>
    friend inline bool operator<(const counter<TT> &lhs, const UU &x);
    template<typename TT, typename UU>
    friend inline bool operator<(const UU &x, const counter<TT> &rhs);
    //  >
    template<typename TT, typename BB>
    friend inline bool operator>(const counter<TT> &lhs, const counter<BB> &rhs);
    template<typename TT, typename UU>
    friend inline bool operator>(const counter<TT> &lhs, const UU &x);
    template<typename TT, typename UU>
    friend inline bool operator>(const UU &x, const counter<TT> &rhs);
    //  <=
    template<typename TT, typename BB>
    friend inline bool operator<=(const counter<TT> &lhs, const counter<BB> &rhs);
    template<typename TT, typename UU>
    friend inline bool operator<=(const counter<TT> &lhs, const UU &x);
    template<typename TT, typename UU>
    friend inline bool operator<=(const UU &x, const counter<TT> &rhs);
    //  >=
    template<typename TT, typename BB>
    friend inline bool operator>=(const counter<TT> &lhs, const counter<BB> &rhs);
    template<typename TT, typename UU>
    friend inline bool operator>=(const counter<TT> &lhs, const UU &x);
    template<typename TT, typename UU>
    friend inline bool operator>=(const UU &x, const counter<TT> &rhs);
    //  trigonometry
    inline double sin() { return std::sin(this->val*PI/180); }
    inline double cos() { return std::cos(this->val*PI/180); }
    inline double tan() { return std::tan(this->val*PI/180); }
    inline double exp() { return std::exp(this->val); }
    template<typename U>
    inline auto pow(const U &x) { return std::pow(this->val, x); }
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const counter<T> &a) {
    out << a.val;
    return out;
}
template<typename T>
std::istream &operator>>(std::istream &in, counter<T> &a) {
    in >> a.val;
    return in;
}
//  +
template<typename T, typename B>
counter<T> operator+(const counter<T> &a, const counter<B> &rhs) {
    return counter<T>(a.val + rhs.val);
}
template<typename T>
template<typename U>
inline counter<T> counter<T>::operator+(const U &x) {
    return counter<T>(this->val + x);
}
template<typename TT, typename U>
U inline operator+(const U &x, const counter<TT> &rhs) {
    return x + rhs.val;
}
//  -
template<typename T, typename B>
counter<T> operator-(const counter<T> &a, const counter<B> &rhs) {
    return counter<T>(a.val - rhs.val);
}
template<typename T>
template<typename U>
inline counter<T> counter<T>::operator-(const U &x) {
    return counter<T>(this->val - x);
}
template<typename TT, typename U>
U inline operator-(const U &x, const counter<TT> &rhs) {
    return x - rhs.val;
}
//  *
template<typename T, typename B>
counter<T> operator*(const counter<T> &a, const counter<B> &rhs) {
    return counter<T>(a.val*rhs.val);
}
template<typename T>
template<typename U>
inline counter<T> counter<T>::operator*(const U &x) {
    return counter<T>(this->val*x);
}
template<typename TT, typename U>
U inline operator*(const U &x, const counter<TT> &rhs) {
    return x*rhs.val;
}
//  /
template<typename T, typename B>
counter<T> operator/(const counter<T> &a, const counter<B> &rhs) {
    return counter<T>(a.val/rhs.val);
}
template<typename T>
template<typename U>
inline counter<T> counter<T>::operator/(const U &x) {
    return counter<T>(this->val/x);
}
template<typename TT, typename U>
U inline operator/(const U &x, const counter<TT> &rhs) {
    return x/rhs.val;
}

//  ==
template<typename T, typename B>
inline bool operator==(const counter<T> &lhs, const counter<B> &rhs) {
    return lhs.val == rhs.val;
}
template<typename T, typename U>
inline bool operator==(const counter<T> &lhs, const U &x) {
    return lhs.val == x;
}
template<typename T, typename U>
inline bool operator==(const U &x, const counter<T> &rhs) {
    return x == rhs.val;
}
//  !=
template<typename T, typename B>
inline bool operator!=(const counter<T> &lhs, const counter<B> &rhs) {
    return !(rhs == lhs);
}
template<typename T, typename U>
inline bool operator!=(const counter<T> &lhs, const U &x) {
    return !(lhs.val == x);
}
template<typename T, typename U>
inline bool operator!=(const U &x, const counter<T> &rhs) {
    return !(x == rhs.val);
}

//  <
template<typename T, typename B>
inline bool operator<(const counter<T> &lhs, const counter<B> &rhs) {
    return lhs.val < rhs.val;
}
template<typename T, typename U>
inline bool operator<(const counter<T> &lhs, const U &x) {
    return lhs.val < x;
}
template<typename T, typename U>
inline bool operator<(const U &x, const counter<T> &rhs) {
    return x < rhs.val;
}
//  >
template<typename T, typename B>
inline bool operator>(const counter<T> &lhs, const counter<B> &rhs) {
    return rhs < lhs;
}
template<typename T, typename U>
inline bool operator>(const counter<T> &lhs, const U &x) {
    return lhs.val > x;
}
template<typename T, typename U>
inline bool operator>(const U &x, const counter<T> &rhs) {
    return x > rhs.val;
}
//  <=
template<typename T, typename B>
inline bool operator<=(const counter<T> &lhs, const counter<B> &rhs) {
    return !(rhs < lhs);
}
template<typename T, typename U>
inline bool operator<=(const counter<T> &lhs, const U &x) {
    return lhs.val <= x;
}
template<typename T, typename U>
inline bool operator<=(const U &x, const counter<T> &rhs) {
    return x <= rhs.val;
}
//  >=
template<typename T, typename B>
inline bool operator>=(const counter<T> &lhs, const counter<B> &rhs) {
    return !(lhs < rhs);
}
template<typename T, typename U>
inline bool operator>=(const counter<T> &lhs, const U &x) {
    return lhs.val >= x;
}
template<typename T, typename U>
inline bool operator>=(const U &x, const counter<T> &rhs) {
    return x >= rhs.val;
}

template<typename T>
counter<T> &counter<T>::operator=(const counter<T> &x) {
    if (this != &x) {
        val = x.val;
    }
    return *this;
}
template<typename T>
template<typename U>
counter<T> &counter<T>::operator=(const U &x) {
    val = x;
    return *this;
}
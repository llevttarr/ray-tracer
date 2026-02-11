#pragma once
#include <cmath>

template<typename T>
class Vec4 {
public:
    T x,y,z,w;

    constexpr Vec4(): x(0),y(0),z(0),w(0){}
    constexpr Vec4(T x,T y,T z,T w): x(x),y(y), z(z),w(w){}

    constexpr Vec4 operator+(const Vec4& other) const {
        return Vec4(x +other.x, y+other.y,z+other.z,w+other.w);
    }
    constexpr Vec4 operator-(const Vec4& other) const {
        return Vec4(x -other.x, y-other.y,z-other.z,w-other.w);
    }
    constexpr Vec4 operator*(T s) const {
        return Vec4(s*x,s*y,s*z,s*w);
    }
    constexpr bool operator==(const Vec4& other) const{
        return x==other.x && y==other.y && z==other.z && w==other.w;
    }
    Vec4& operator+=(const Vec4& other) {
        x+= other.x;
        y+= other.y;
        z+= other.z;
        w+= other.w;
        return *this;
    }
    Vec4& operator-=(const Vec4& other) {
        x-= other.x;
        y-= other.y;
        z-= other.z;
        w-=other.w;
        return *this;
    }
    Vec4& operator*=(T s) {
        x*=s;
        y*=s;
        z*=s;
        w*=s;
        return *this;
    }
    constexpr T magnitude_sq() const {
        return x*x+y*y+z*z+w*w;
    }
    static constexpr T dot(const Vec4& a,const Vec4& b) {
        return a.x*b.x+ a.y*b.y+a.z*b.z+a.w*b.w;
    }
};

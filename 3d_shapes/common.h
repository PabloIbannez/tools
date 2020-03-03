#ifndef __3D_COMMON__
#define __3D_COMMON__

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

#define real double

struct int3{
    int i,j,k;
};

struct real3{
    real x,y,z;

    bool operator<(const real3& r3){
        if(x == r3.x){
            if(y == r3.y){
                return z < r3.z;
            } else {
                return y < r3.y;
            }
        } else {
            return x < r3.x;
        }
    }

    bool operator==(const real3& r3){
        return (x==r3.x)&&(y==r3.y)&&(z==r3.z);
    }
};

#endif

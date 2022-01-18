#include "Solovay_Strassen.h"
#include <stdexcept>
#include <iostream>
#include <time.h>

Solovay_Strassen::Solovay_Strassen(long long a,long long b) {
    this->a=a;
    this->b=b;
}
void Solovay_Strassen::to_String() {
    std::cout<<this->a<<"\n"<<this->b<<std::endl;
}
bool Solovay_Strassen::warunek_1(long long x,long long y) {
    if (x>0 && x<y)
        return true;
    else
        return false;

}
long long Solovay_Strassen::losuj(long long a) {
    srand(time(NULL));
    long long w;
    try {
        w= (rand() % 2 + a);
        if (!(w>0 && w<a))
            throw w;
    } catch (long long w){
        while(!warunek_1(w,a))
            w = rand() % a;
    }
    return w;
}
long long Solovay_Strassen::pot_mod(long long b, long long c, long long a) {
    long long result = 1, i ,x =b%a;
    for (i=1; i<=b; i<<=1) {
        x %= a;
        if ((c & i) != 0) {
            result *= x;
            result %= a;
        }
        x *= x;
    }
    return result;
}
int Solovay_Strassen::Jacobi(long long a, long long b) {
    if (b%2 == 0 || b<0 )
        throw std::invalid_argument("-1");
    int result;

    if (a == 0) {
        if(b == 1)
            result = 1;
        else
            result =0;
    }
    else if (a ==2){
        if (b%8 == 7)
            result = 1;
        if (b%8 == 5)
            result = -1;
    }
    else if (a>=b)
        result = Jacobi(a%b,b);
    else if(a%2 == 0)
        result = Jacobi(2,b)* Jacobi(a/2,b);
    else if (a%4 == 3 && b%4 ==3)
        result = -Jacobi(b, a);
    else
        result = Jacobi(b,a);
    return  result;
}
long long Solovay_Strassen::licz(){
    if (this->a == 2) {
        std::cout << "primber" << std::endl;
        exit(-1);
    }
    if (this->a%2 == 0){
        std::cout<<"2"<<std::enme nudl;
        exit(1);
    }
    long long q,c = (this->a-1)/2;
    for (int i = 0; i <= this->b; ++i) {
        q = losuj(a);
        std::cout<<pot_mod(q,c, this->a)<<std::endl;
        std::cout<<Jacobi(q,this->a)<<std::endl;
        if (pot_mod(q,c, this->a) != Jacobi(q,this->a)) {
            std::cout<<pot_mod(q,c,a)<<std::endl;
            std::cout<<Jacobi(q,a);
            std::cout << "2" << std::endl;
            exit(2);
        }
    }
    std::cout<<"1"<<std::endl;
    exit(1);
}


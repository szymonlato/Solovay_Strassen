

#ifndef BIEGACZ_SOLOVAY_STRASSEN_A_SOLOVAY_STRASSEN_H
#define BIEGACZ_SOLOVAY_STRASSEN_A_SOLOVAY_STRASSEN_H


class Solovay_Strassen {
    long long  a,b;
public:
    Solovay_Strassen(long long a,long long b);
    void to_String();
    bool warunek_1(long long x,long long y);
    long long losuj(long long a);
    long long pot_mod(long long a,long long b, long long c);
    int Jacobi(long long a,long long b);
    long long licz();
};



#endif //BIEGACZ_SOLOVAY_STRASSEN_A_SOLOVAY_STRASSEN_H

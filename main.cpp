#include <iostream>
#include "Solovay_Strassen.h"



//argv[1]-liczba do sprawdzenia
//argv[2]-liczba iteracji testu
int main(int argc,char** argv) {
    Solovay_Strassen a(atoll(argv[1]),atoll(argv[2]));
    //std::cout<<LLONG_MAX;
    //a.to_String();
    a.licz();

    return 0;
}

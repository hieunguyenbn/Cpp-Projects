#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct BigNumber
{
    static const int base = 10 ;
    int noDigits;
    int Digits[50];
};

void _nhapBN ( BigNumber & bn ) ;
void _generateRandomBN ( BigNumber & bn ) ;
string _toStringBN ( const BigNumber & bn ) ;

BigNumber operator+ ( const BigNumber & bn1 , const BigNumber & bn2 ) ;
BigNumber operator* ( const BigNumber & bn1 , const int & digit ) ;
BigNumber operator* ( const BigNumber & bn1 , const BigNumber & bn2 ) ;

BigNumber operator- ( const BigNumber & bn1 , const BigNumber & bn2 ) ;

BigNumber _average ( BigNumber mangBN[] , const int & soPhanTu ) ;

bool operator< ( const BigNumber & bn1 , const BigNumber & bn2 ) ;
void _sortBN ( BigNumber mangBN[] , const int & soPhanTu ) ;

int main()
{
    BigNumber bn1, bn2 ;
    bn1.noDigits = 2;
    bn1.Digits[0] = 0;
    bn1.Digits[1] = 1;
    bn2.noDigits = 3;
    bn2.Digits[0] = 0;
    bn2.Digits[1] = 1;
    bn2.Digits[2] = 2;
    cout << _toStringBN ( bn1 ) << endl ;
    cout << _toStringBN ( bn2 ) << endl ;
    BigNumber bnTong = ( bn1 + bn2 ) ;
    BigNumber bnHieu = ( bn1 - bn2 ) ;
    BigNumber bnTich = ( bn1 * bn2 ) ;
    cout << _toStringBN ( bnTong ) << endl ;
    cout << _toStringBN ( bnHieu ) << endl ;
    cout << _toStringBN ( bnTich ) << endl ;
    return 0 ;
}

void _nhapBN ( BigNumber & bn ) {
    /*
        ... your code here
    */
}

void _generateRandomBN ( BigNumber & bn ) {
    /*
        ... your code here
    */
}

string _toStringBN ( const BigNumber & bn ) {
    stringstream ss ;
    for (int i = bn.noDigits - 1 ; i >= 0; i-- ) {
        ss << bn.Digits[i];
    }
    return ss.str() ;
}

void _toiGianBN ( BigNumber & bn ) {
    /*
        ... your code here
    */
}

BigNumber operator+ ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    BigNumber bnTong ;
    /*
        ... your code here
    */
    return bn1 ;
}

BigNumber operator* ( const BigNumber & bn , const int & digit ) {
    BigNumber bnTich ;
    /*
        ... your code here
    */
    return bn ;
}

BigNumber operator* ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    BigNumber bnTich ;
    /*
        ... your code here
    */
    return bn1 ;
}


BigNumber operator- ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    BigNumber bnHieu ;
    /*
        ... your code here
    */
    return bn1 ;
}

BigNumber _average ( BigNumber mangBN[] , const int & soPhanTu ) {
    return mangBN[0];
}

bool operator< ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    /*
        ... your code here
    */
    return true ;
}

void _sortBN ( BigNumber mangBN[] , const int & soPhanTu ) {

}

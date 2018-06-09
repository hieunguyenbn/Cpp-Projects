#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct PhanSo
{
    int tuSo;
    int mauSo;
};

void _nhapPS ( PhanSo & ps ) ;
string _toStringPS ( const PhanSo & ps ) ;
void _toiGianPS ( PhanSo & ps ) ;

PhanSo operator+ ( const PhanSo & ps1 , const PhanSo & ps2 ) ;
PhanSo operator- ( const PhanSo & ps1 , const PhanSo & ps2 ) ;
PhanSo operator* ( const PhanSo & ps1 , const PhanSo & ps2 ) ;
PhanSo operator/ ( const PhanSo & ps1 , const PhanSo & ps2 ) ;
PhanSo _average ( PhanSo mangPS[] , const int & soPhanTu ) ;

bool operator< ( const PhanSo & ps1 , const PhanSo & ps2 ) ;
void _sortPS ( PhanSo mangPS[] , const int & soPhanTu ) ;

int main()
{
    PhanSo ps1, ps2 ;
    ps1.tuSo = 1 ;
    ps1.mauSo = 2 ;
    ps2.tuSo = 1 ;
    ps2.mauSo = 2 ;
    cout << _toStringPS ( ps1 ) << endl ;
    cout << _toStringPS ( ps2 ) << endl ;
    PhanSo psTong = ( ps1 + ps2 ) ;
    PhanSo psHieu = ( ps1 - ps2 ) ;
    PhanSo psTich = ( ps1 * ps2 ) ;
    PhanSo psThuong = ( ps1 / ps2 ) ;
    cout << _toStringPS ( psTong ) << endl ;
    cout << _toStringPS ( psHieu ) << endl ;
    cout << _toStringPS ( psTich ) << endl ;
    cout << _toStringPS ( psThuong ) << endl ;
    return 0 ;
}

void _nhapPS ( PhanSo & ps ) {
    /*
        ... your code here
    */
}

string _toStringPS ( const PhanSo & ps ) {
    stringstream ss ;
    ss << ps.tuSo << "/" << ps.mauSo ;
    return ss.str() ;
}

void _toiGianPS ( PhanSo & ps ) {
    /*
        ... your code here
    */
}

PhanSo operator+ ( const PhanSo & ps1 , const PhanSo & ps2 ) {
    PhanSo psTong ;
    /*
        ... your code here
    */
    _toiGianPS(psTong) ;
    return ps1 ;
}

PhanSo operator- ( const PhanSo & ps1 , const PhanSo & ps2 ) {
    PhanSo psHieu ;
    /*
        ... your code here
    */
    _toiGianPS(psHieu) ;
    return ps1 ;
}

PhanSo operator* ( const PhanSo & ps1 , const PhanSo & ps2 ) {
    PhanSo psTich ;
    /*
        ... your code here
    */
    _toiGianPS(psTich) ;
    return ps1 ;
}

PhanSo operator/ ( const PhanSo & ps1 , const PhanSo & ps2 ) {
    PhanSo psThuong ;
    /*
        ... your code here
    */
    _toiGianPS(psThuong) ;
    return ps1 ;
}

PhanSo _average ( PhanSo mangPS[] , const int & soPhanTu ) {
    return mangPS[0];
}

bool operator< ( const PhanSo & ps1 , const PhanSo & ps2 ) {
    /*
        ... your code here
    */
    return true ;
}

void _sortPS ( PhanSo mangPS[] , const int & soPhanTu ) {
    if (mangPS[0] < mangPS[1]) {

    }
    else {

    }
}

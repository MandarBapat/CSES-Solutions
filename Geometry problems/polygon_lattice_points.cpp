#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int x, long long int y){
    if(y == 0){
        return x;
    }
    else{
        return gcd(y, x%y);
    }
}

long long int lattic_points_on_boundary(complex<long long int> p1, complex<long long int> p2){
    long long int slope_num = p2.imag() - p1.imag();
    long long int slope_denum = p2.real() - p1.real();

    long long int g = gcd(abs(max(slope_denum, slope_num)), abs(min(slope_denum, slope_num)) );

    slope_num = slope_num/g;
    slope_denum = slope_denum/g;

    if( p1.real() == p2.real() ){
        return abs(p2.imag() - p1.imag());
    }
    else if(p1.imag() == p2.imag()){
        return abs(p2.real() - p1.real());
    }
    else{
        return min( abs(p2.real() - p1.real())/abs(slope_denum), abs(p2.imag() - p1.imag())/abs(slope_num) );
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    complex<long long int> prev, start;
    long long int sx, sy;
    cin >> sx >> sy;
    start = {sx, sy};
    prev = {sx, sy};
    
    long long int area = 0;
    long long int b = 0;

    for(int i=1;i<n;i++){
        long long int x, y;
        cin >> x >> y;
        complex<long long int> temp = {x, y};

        area += (conj(prev)*temp).imag();
        b += lattic_points_on_boundary(prev, temp);

        prev = temp;
    }

    area += (conj(prev)*start).imag();
    b += lattic_points_on_boundary(prev, start);

    long long int a = (abs(area) + 2 - b)/2;

    cout << a << " " << b;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long int cmp_mul(long long int x1, long long int y1, long long int x2, long long int y2){
    return x1*y2 + y1*x2;
}

bool check_between(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
    bool cond1 = (x3 >= min(x1, x2)) && (x3 <= max(x1, x2));
    bool cond2 = (y3 >= min(y1, y2)) && (y3 <= max(y1, y2));

    if(cond1 && cond2){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int q=1;q<=t;q++){
        long long int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        bool cond1 = ((x1 == x3) && (y1 == y3)) || ((x1 == x4) && (y1 == y4));
        bool cond2 = ((x2 == x3) && (y2 == y3)) || ((x2 == x4) && (y2 == y4));
        if( cond1 || cond2 ){
            cout << "YES\n";
        }
        else{
            long long int prod1 = cmp_mul( (x2-x1), -(y2-y1), (x3-x1), (y3-y1) );
            long long int prod2 = cmp_mul( (x2-x1), -(y2-y1), (x4-x1), (y4-y1) );
            long long int prod3 = cmp_mul( (x4-x3), -(y4-y3), (x1-x3), (y1-y3) );
            long long int prod4 = cmp_mul( (x4-x3), -(y4-y3), (x2-x3), (y2-y3) );

            bool v1 = ((prod1 > 0) && (prod2 < 0)) || ((prod1 < 0) && (prod2 > 0));
            bool v2 = ((prod3 > 0) && (prod4 < 0)) || ((prod3 < 0) && (prod4 > 0));

            if( v1 && v2 ){
                cout << "YES\n";
            }
            else if(prod1 == 0 && check_between(x1, y1, x2, y2, x3, y3)){
                cout << "YES\n";
            }
            else if(prod2 == 0 && check_between(x1, y1, x2, y2, x4, y4)){
                cout << "YES\n";
            }
            else if(prod3 == 0 && check_between(x3, y3, x4, y4, x1, y1)){
                cout << "YES\n";
            }
            else if(prod4 == 0 && check_between(x3, y3, x4, y4, x2, y2)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }

}
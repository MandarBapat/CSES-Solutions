#include <bits/stdc++.h>

using namespace std;

bool check_between(complex<long long int> p1, complex<long long int> p2, complex<long long int> p3){
    bool cond1 = (p3.real() >= min(p1.real(), p2.real())) &&  (p3.real() <= max(p1.real(), p2.real()));
    bool cond2 = (p3.imag() >= min(p1.imag(), p2.imag())) &&  (p3.imag() <= max(p1.imag(), p2.imag()));

    if(cond1 && cond2){
        return 1;
    }
    else{
        return 0;
    }
}

bool check_intersection(complex<long long int> p1, complex<long long int> p2, complex<long long int> p3, complex<long long int> p4, bool &on_boundary){
    if(p1 == p3 || p2 == p3){
        on_boundary = true;
    }
    bool cond1 = (p1 == p3) || (p1 == p4);
    bool cond2 = (p2 == p3) || (p2 == p4);

    if(cond1 || cond2){
        return 1;
    }
    else{
        long long int prod1 = (conj(p2-p1)*(p3-p1)).imag();
        long long int prod2 = (conj(p2-p1)*(p4-p1)).imag();
        long long int prod3 = (conj(p4-p3)*(p1-p3)).imag();
        long long int prod4 = (conj(p4-p3)*(p2-p3)).imag();

        bool c1 = (prod1 > 0 && prod2 < 0) || (prod1 < 0 && prod2 > 0);
        bool c2 = (prod3 > 0 && prod4 < 0) || (prod3 < 0 && prod4 > 0);

        if(c1 && c2){
            return 1;
        }
        else if(prod1 == 0 && check_between(p1, p2, p3)){
            on_boundary = true;
            return 1;
        }
        else if(prod2 == 0 && check_between(p1, p2, p4)){
            return 1;
        }
        else if(prod3 == 0 && check_between(p3, p4, p1)){
            return 1;
        }
        else if(prod4 == 0 && check_between(p3, p4, p2)){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    complex<long long int> p[n];

    long long int max1 = 0;
    long long int max2 = 0;

    for(int i=0;i<n;i++){
        long long int x, y;
        cin >> x >> y;
        max1 = max(max1, x);
        max2 = max(max2, y);
        p[i] = {x, y};
    }

    for(int t=0;t<m;t++){
        long long int x, y;
        cin >> x >> y;

        complex<long long int> point = {x, y};

        complex<long long int> ref1 = {INT32_MAX+1, INT32_MAX+3};

        if(point == ref1){
            cout << "OUTSIDE\n";
        }
        else{
            int ans1 = 0;
            bool flag = 0;
            for(int i=0;i<n;i++){
                if(i == n-1){
                    bool temp1 = check_intersection(p[n-1], p[0], point, ref1, flag);
                    if(flag){
                        cout << "BOUNDARY\n";
                        break;
                    }
                    else{
                        ans1 += temp1;
                    }
                }
                else{
                    bool temp1 = check_intersection(p[i], p[i+1], point, ref1, flag);
                    if(flag){
                        cout << "BOUNDARY\n";
                        break;
                    }
                    else{
                        ans1 += temp1;
                    }
                }
            }

            if(!flag){
                if(ans1&1){
                    cout << "INSIDE\n";
                }
                else{
                    cout << "OUTSIDE\n";
                }
            }
        }
    }
}
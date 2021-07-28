#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#define rep(i,n) for(int i = 0;i < (n); ++i)
using namespace std;

typedef long long LL;
typedef long double LD;

const long double Gratio = (1 + sqrt(5.0)) * 0.5;

long double p;
LD f(LD x){
    LD ans;
    ans = x + 1.0L*p / powl(2.0L, x / 1.5L);
    return ans;
}

LD search(LD left, LD right){
    LD c1 = left + (right - left) * 1.0L / (1.0L + Gratio);
    LD c2 = left + (right - left) * Gratio / (1.0L + Gratio);
    LD c1Value = f(c1);
    LD c2Value = f(c2);
    int maxloop = 100000;
    for(int loop = 0;loop < maxloop; loop++){
        if(c1Value < c2Value){
            right = c2;
            c2 = c1;
            c2Value = c1Value;
            c1 = left + (right - left) * 1.0L / (1.0L + Gratio);
            c1Value = f(c1);
        }else{
            left = c1;
            c1 = c2;
            c1Value = c2Value;
            c2 = left + (right - left) * Gratio / (1.0L + Gratio);
            c2Value = f(c2);
        }
    }
	return f((right + left) * 0.5L);
}

int main(void){
    cin >> p;
    LD left = 0, right = 200, ans;
    ans = search(left, right);
    printf("%.12Lf\n", ans);
}

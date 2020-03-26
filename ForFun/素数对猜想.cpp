//让我们定义d
//​n
//​​ 为：d
//​n
//​​ =p
//​n+1
//​​ −p
//​n
//​​ ，其中p
//​i
//​​ 是第i个素数。显然有d
//1
//​​ =1，且对于n>1有d
//​n
//​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

//现给定任意正整数N(<10
//​5
//​​ )，请计算不超过N的满足猜想的素数对的个数。






#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

bool isPrime( int num )
{
     int tmp =sqrt( num);
     for(int i= 2;i <=tmp; i++)
        if(num %i== 0)
          return 0 ;
     return 1 ;
}

int main(){
    int N,count=0;
    cin>>N;
    if(N <= 2) {
        cout<<0;
        return 0;
    }
    vector<int> PL={};

    for(int i=3; i<=N;i++){
        if(isPrime(i)){
            PL.push_back(i);
        }    
    }

    for(int i=0;i<PL.size()-1;i++){
        if(PL[i+1]-PL[i] == 2){
            count++;
        }
    }

    cout<<count;

    return 0;

}

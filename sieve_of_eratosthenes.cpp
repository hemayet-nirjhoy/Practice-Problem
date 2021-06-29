#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

int prime[300000], cntPrime;
int numbers[1000002];

void sieve(int n)
{
    int i, j, limit=sqrt(n*1.)+2;
    for(i=4; i<=n; i+=2)
    {
        numbers[i]=1;
    }
    prime[cntPrime++]=2;
    for(i=3;i<=n;i+=2){
        if(numbers[i])
            continue;
        prime[cntPrime++]=i;
        for(j=i+1;j<=n;j++){
            if(j%i==0)
                numbers[j]=1;
        }
    }
}

int main()
{

    cout << "Prime Numbers using sieve." << endl;
    clock_t st_time,  end_time;
    st_time = clock();
    sieve(100);
    float diff = (float)clock()-(float)st_time;
    for (int i=0;i<cntPrime;i++){
        cout << "Prime: " << prime[i] << endl;
    }
    cout << "Execution-time: " << diff << endl;

    return 0;
}

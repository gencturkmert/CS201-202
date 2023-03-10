
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

long long alg1(int a, long long n, int p) {
	long long pow = 1;
	for(long long i = 1; i <= n; i++) {

		pow = pow * a;
		pow = pow % p;
	}

	return pow;
}

long long alg2(int a, long long n, int p) {
	long long pow = 1;

    cout<<"2";
	for(long long k = 1; k <= n; k++) {
        //cout<<".";
        //cout<<",";
		pow = pow * a;
		pow = pow % p;


		if (pow == 1) {

			n = n % k;
			pow = 1;
			for (long long j = 0; j < n; j++) {
			   //cout<<".";
				pow = pow * a;
				pow = pow % p;
			}
			return pow;
		}
	}

	return pow;
}

long long alg3(int a, long long n, int p) {
    if (n == 0)
        return 1;

    long long y;

    if (n % 2 == 0) {
        y = alg3(a, n / 2, p);
        //cout<<"y:"<<y<<endl;
        y = (y * y) % p;
        //cout<<"y2:"<<y<<endl;
    }

    else {
        y = alg3(a,(n-1)/2,p);
       // cout<<"y:3"<<y<<endl;
        y = y * y * a;
       // cout<<"y:4"<<y<<endl;
    }

    return y % p;

}

int main() {

/**
	for(long long i = 1; i<=10;i++) {

        double duration;
        clock_t startTime = clock();

            if(i<11) {

            cout << "Alg3, i="<<i<< endl;
            unsigned long long c =i * 1000000000;
            cout<<"c:"<<c<<endl;
            cout<<"p:107"<<endl;
            long long y = alg3(10000,c, 107);
            cout << y <<endl;

            }else if( i<21) {
                i = (long long)(i - (long long)10);
                cout << "Alg3, i="<<i<< endl;
                unsigned long long c =i * 9000000000;
                cout<<"c:"<<c<<endl;
                cout<<"p:1003"<<endl;
                long long y = alg3(10000,c, 1003);
                cout << y <<endl;

            }else if( i<31) {
                i = (long long)(i - (long long)20);
                cout << "Alg3, i="<<i<< endl;
                unsigned long long c =i * 9000000000;
                cout<<"c:"<<c<<endl;
                cout<<"p:10"<<endl;

                long long y = alg3(10000,c, 10);
                cout << y <<endl;
            }else{
                i = (long long)(i - (long long)30);
                cout << "Alg3, i="<<i<< endl;
                unsigned long long c =i * 9000000000;
                cout<<"c:"<<c<<endl;
                cout<<"p:100"<<endl;

                long long y = alg3(10000,c, 100);
                cout << y <<endl;
            }



        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;
    */
    for(long long k = 1; k<=40; k++) {
        double duration;
        clock_t startTime = clock();

        for(int i = 0;i<10000000;i++) {

            if(k<11) {
            unsigned long long c = (long long)(pow(2,k)) * 10000000;
            alg3(1000,c, 107);
            }
            else if(k<21) {
               unsigned long long c = k * 1000000000;
            alg3(10000,c, 1003);
            }else if(k<31) {
               unsigned long long c = k * 1000000000;
            alg3(10000,c, 10);
            }else {
               unsigned long long c = k * 1000000000;
            alg3(10000,c, 100);
            }

        }
             if(k<11) {

            cout << "Alg3, k="<<k<< endl;
            unsigned long long c =(long long)(pow(2,k)) * 100000000;
            cout<<"c:"<<c<<endl;
            cout<<"p:107"<<endl;
            long long y = alg3(1000,c, 107);
            cout << y <<endl;

            }else if( k<21) {
                k = (long long)(k - (long long)10);
                cout << "Alg3, k="<<k<< endl;
                unsigned long long c =k * 9000000000;
                cout<<"c:"<<c<<endl;
                cout<<"p:1003"<<endl;
                long long y = alg3(10000,c, 1003);
                cout << y <<endl;

            }else if( k<31) {
                k = (long long)(k - (long long)20);
                cout << "Alg3, k="<<k<< endl;
                unsigned long long c =k * 9000000000;
                cout<<"c:"<<c<<endl;
                cout<<"p:10"<<endl;

                long long y = alg3(10000,c, 10);
                cout << y <<endl;
            }else{
                k = (long long)(k - (long long)30);
                cout << "Alg3, k="<<k<< endl;
                unsigned long long c =k * 9000000000;
                cout<<"c:"<<c<<endl;
                cout<<"p:100"<<endl;

                long long y = alg3(10000,c, 100);
                cout << y <<endl;

        }

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

	}
	}



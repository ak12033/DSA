#include<iostream>
#include <vector>
using namespace std;

//                            Count Primes(Sieve of Eratosthenes)
/*
int countPrimes(int n) {
    
    vector<bool> prime(n+1,true);
    
    prime[0]=prime[1]=false;

    int cnt=0;
    for(int i=2;i<n;i++){
        if(prime[i]){
            cnt++;
            for(int j=2*i;j<n;j=j+i){
                prime[j]=0;
            }
        }    
    }
    return cnt;
}
int main() {

    int n = 30;
    cout << "Number of primes less than " << n << " : " << countPrimes(n) << endl;

    return 0;
}
*/

//                                      GCD/HCF
/*
int gcd(int a, int b) {

    if(a==0)
    return b;

    if(b==0)
    return a;

    while(a != b) {

        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
int main() {
    
    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;

    int ans = gcd(a,b);

    cout << " The GCD of " << a << " & " << b << " is: " << ans << endl;

    return 0;
}
*/

// LCM(a,b) * GCD(a,b) = a * b
// Pigeon Hole Principle
// Catalan number
// Inclusion and Exclusion Principle
// Segmented sieve

//                              Modular Exponentiation
/*
int modularExponentiation(int x, int n, int m) {

	int res = 1;
	while(n>0){
		if(n&1){
			res = (1LL*(res)*(x)%m)%m;
		}
		x = (1LL*(x)%m*(x)%m)%m;
		n = n>>1;
	}
	return res;
}
int main() {

    int x, n, m;
    
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;
    cout << "Enter the modulus (m): ";
    cin >> m;

    int result = modularExponentiation(x, n, m);
    cout << "Result of " << x << "^" << n << " % " << m << " is: " << result << endl;

    return 0;
}
*/
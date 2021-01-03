//practice.cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// Problem Name: Print reverse
// Problem Constraints: 0 <= N <= 1000000000
// Take N as input, Calculate it's reverse also Print the reverse.
// Sample Input: 123456789
// Output Format: 
// Sample Output: 987654321
// int main(){
//     int n, ans=0;
//     cout<<"ENTER NUMBER : ";
//     cin>>n;
//     while(n!=0){
//         int digit = n % 10;
//         ans = ans*10 + digit;
//         n = n/10;
//     }
//     cout<<"REVERSED NUMBER IS : "<<ans;
// }

// Problem Name: Von Neuman Loves Binary
// Digits in binary representation is <=16.
// Problem Description:
// Given a binary number ,help Von Neuman to find out its decimal representation.
// For eg 000111 in binary is 7 in decimal.
// Input Format: The first line contains N , the number of binary numbers.
// Next N lines contain N integers each representing binary represenation of number.
// Sample Input: 4
// 101
// 1111
// 00110
// 111111
// Output Format: N lines,each containing a decimal equivalent of the binary number.
// Sample Output: 5
// 15
// 6
// 63
// int main(){
//     int i,n,a[10000];
//     int sum = 0;
//     int power = 1;
//     cout<<"ENTER N : ";
//     cin>>n;
//     for(i=0; i<n ;i++){
//         cin>>a[i];
//     }
    
//     for (int i = 0; i < n; i++){
//         while (a[i] != 0){
//         int digits;
//         digits = a[i]%10;
//         a[i] = a[i]/10;
//         sum = sum + digits*power;
//         power = power*2;
//         }
//     cout << sum << endl;
//     }
// }

// Problem Name: Print Series
// Problem Difficulty: None
// Problem Constraints: 0 < N1 < 100 
// 0 < N2 < 100
// Problem Description:
// Take the following as input.
// A number (N1)  
// A number (N2)
// Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.
// Input Format: 
// Sample Input: 10 
// 4
// Output Format: 
// Sample Output: 5 
// 11
// 14
// 17 
// 23 
// 26 
// 29 
// 35 
// 38 
// 41

// int main(){
//     int n1,n2;
//     cin>>n1>>n2;
//     int n=1;
//     int count=1;
//     while(count<=n1){
//         int ans=3*n+2;
//         if(ans%n2!=0){
//             cout<<ans<<endl;
//             count++;
//         }
//     n++;
//     }
// }



//gfg question
// int main(){
//     vector<int> v;
//     int n, a[10000];
//     int left;
//     cin>>n;
//     int i;
//     for(i=0; i<n; i++){
//         cin>>a[i];
//     }

//     //left = ;
//     for(i=0; i<n; i++){
//         if(a[i]<a[i+1]){
//             cout<<i<<" ";
//             //cout<<left<<" ";
//         }
//         else{
//             //cout<<i<<" ";
//             v.push_back(i);
//         }

//     }
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
// }

// Problem Name: Pythagoras Triplet
// Problem Difficulty: None
// Problem Constraints: N <= 10^9
// Problem Description:
// Given a number N (denoting one of the legs of the triangle), 
// Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".
// Input Format: A single integer N
// Sample Input: 3
// Output Format: Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet 
// in increasing order.
// Sample Output: 4 5

// int main(){
// ll x;

//     while( cin >> x){
//         if(x < 3){ printf("-1\n");  continue; }

//         if(x & 1)  printf("%lld %lld", (x*x-1)/2, (x*x+1)/2);
//         else{

//             printf("%lld %lld", ((x*x)/4)-1, ((x*x)/4)+1);
//         }
//     }
//     return 0;
//}


// Problem Name: Help Ramu
// Problem Difficulty: 2
// Problem Constraints: 1 <= T <= 1000 , where T is no of testcases <br>
// 1 ≤ c1, c2, c3, c4 ≤ 1000 <br>
// 1 ≤ n, m ≤ 1000 <br>
// 0 ≤ a<sub>i</sub> , b<sub>i</sub> ≤ 1000
// Problem Description:
// Ramu often uses public transport. The transport in the city is of two types: cabs and rickshaws. 
// The city has n rickshaws and m cabs, the rickshaws are numbered by integers from 1 to n, 
// the cabs are numbered by integers from 1 to m.

// Public transport is not free. There are 4 types of tickets:

// A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;  
// A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;  
// A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;  
// A ticket for an unlimited number of rides on all rickshaws and cabs. It costs c4 ruppees.  
// Ramu knows for sure the number of rides he is going to make and the transport he is going to use.
//  He asked you for help to find the minimum sum of ruppees he will have to spend on the tickets.
// Input Format: Each Test case has 4 lines which are as follows:
// The first line contains four integers c1, c2, c3, c4 (1 ≤ c1, c2, c3, c4 ≤ 1000) — the costs of the tickets. <br>
// The second line contains two integers n and m (1 ≤ n, m ≤ 1000) — the number of rickshaws and cabs Ramu is going to use. <br>
// The third line contains n integers ai (0 ≤ ai ≤ 1000) — the number of times Ramu is going to use the rickshaw number i. <br>
// The fourth line contains m integers bi (0 ≤ bi ≤ 1000) — the number of times Ramu is going to use the cab number 

//  n=2
// first test case:
// 1 3 7 19
// 2 3
// 2 5
// 4 4 4
// Sample Output: 12

// second test case:
// 4 3 2 1
// 1 3
// 798
// 1 2 3
// Sample Output: 1

// const int MAX = 1000;

// int minFare(int c1 , int c2 , int c3 , int freq[] , int num)
// {
// 	int cost = 0;

// 	for(int i = 0 ; i < num ; i++){
// 		cost += min( c2 , freq[i] * c1 );
// 	}
// 	int minFare = min( c3 , cost);
// 	return minFare;
// }

// int minSum( int c1 , int c2 , int c3 , int c4 , int rickshaws[] , int cabs[] , int n , int m)
// {
// 	int rickshawFare = minFare( c1 , c2 , c3 , rickshaws , n );
// 	int cabFare = minFare( c1 , c2 , c3 , cabs , m );

// 	int minFare = min( rickshawFare + cabFare , c4);
// 	return minFare;
// }

// int main()
// {
// 	int testCases;
// 	cin >> testCases;

// 	while(testCases > 0)
// 	{
// 		int c1 , c2 , c3 ,c4;
// 		cin >> c1 >> c2 >> c3 >> c4;

// 		int n,m;
// 		cin >> n >> m;

// 		int rickshaws[MAX];
// 		int cabs[MAX];

// 		for(int i = 0 ; i < n ; i++)
// 		{
// 			cin >> rickshaws[i];
// 		}

// 		for(int i = 0 ; i < m ; i++)
// 		{
// 			cin >> cabs[i];
// 		}

// 		int result = minSum( c1 , c2 , c3 , c4 , rickshaws , cabs , n , m);

// 		cout << result;
// 		cout << "\n";

// 		testCases--;
// 	}

// 	return 0;
// }

//find all permutations
// void PERMUTATION(string a, int left, int right){
//     if (left == right)
//         cout<<a<<endl;
//     else{
//         for (int i = left; i <= right; i++){
//             swap(a[left], a[i]);
//             PERMUTATION(a, left+1, right);
//             swap(a[left], a[i]);
//         }
//     }
// }

// int main(){
//     string s = "HISTORY";
//     int n = s.size();
//     PERMUTATION(s, 0, n-1);
//     return 0;
// }

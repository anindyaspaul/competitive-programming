#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

 int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

 	long long int t,n,prod,temp,q,k,sumsub,l,r,sume;
 	cin>>t;
 	int arr[200001];
 	vector<long long int> sum;
 	temp=t;
 	while(t--){
 		cin>>n>>q;
 		k=0;
 		for(int i=0;i<n;i++){
 			cin>>arr[i];
 		}
 		for(int i=0;i<n;i++){
 			sumsub = 0;
 			sumsub = arr[i];
 			sum.push_back(sumsub);
 			//cout<<sumsub<<'\n';

 			for(int j=i+1;j<n;j++){
 				sumsub+=arr[j];
 				sum.push_back(sumsub);
 				//cout<<sumsub<<'\n';

 			}
 		}

 		for(int i = 0; i < n; i++) cout << " " << arr[i];
 		cout << endl;
 		for(int i = 0; i < sum.size(); i++) cout << " " << sum[i];
 		cout << endl;

 		sort(sum.begin(), sum.end());
 		for(int i=0;i<q;i++){
 			cin>>l>>r;
 			sume=0;
 			for(int j=l-1;j<=r-1;j++){
 				sume+=sum[j];
 			}
 			if(i==0){
 				cout<<"Case #"<<temp-t<<":\n";
 			}
 			cout<<sume<<"\n";
 		}
 		sum.clear();
 		// for(int i=0;i<n*(n+1)/2;i++){
 		// 	cout<<sum[i]<<"\t";
 		// }
 		//cout<<"Case #"<<temp-t<<": "<<prod%1000000007<<'\n';
 	}
 	return 0;
 }

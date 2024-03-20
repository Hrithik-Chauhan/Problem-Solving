#include<bits/stdc++.h>
using namespace std;
int maxBooks(vector<int>& deskA,vector<int>& deskB, int K) {
    sort(deskA.begin(), deskA.end());
    sort(deskB.begin(), deskB.end());

    int countA = 0, countB = 0; 
    int totalTime = 0;
    int booksRead = 0; 
    while (countA < deskA.size() && countB < deskB.size() && totalTime < K) {
        if (deskA[countA] < deskB[countB]) {
            if (totalTime + deskA[countA] > K) break;
            totalTime += deskA[countA++];
        } else {
            if (totalTime + deskB[countB] > K) break;
            totalTime += deskB[countB++];
        }
        booksRead++;
    }
    while (countA < deskA.size() && totalTime + deskA[countA] <= K) {
        totalTime += deskA[countA++];
        booksRead++;
    }
    while (countB < deskB.size() && totalTime + deskB[countB] <= K) {
        totalTime += deskB[countB++];
        booksRead++;
    }

    return booksRead;
}

int main() {
    int K,n,m ;
    cout<<"enter"<<"\n";
    cin>>n>>m>>K; // 3 4 240
     vector<int> deskA(n) ; 
    vector<int> deskB(m);
    cout<<"Enter books of deskA:\n";
    for(int i=0;i<n;i++){
      cin>>deskA[i];
    }// 60 90 120
    cout<<"Enter books of deskB:\n";
    for(int i=0;i<m;i++){
      cin>>deskB[i];
    }// 80 150 80 150
    int result = maxBooks(deskA, deskB, K);
    cout << "Maximum number of books read: " << result <<endl;

    return 0;
}

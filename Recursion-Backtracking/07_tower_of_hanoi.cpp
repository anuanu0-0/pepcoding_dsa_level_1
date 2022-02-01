#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id){
  // Base case
  if(n<=0) return;
  // Move n-1 disks from t1 to tower t3 using t2 as auxilary tower.
  // Move nth disk from t1 tower to final tower t2.
  // Move the remaining disk from tower t3 to final tower t2 using t1 as an auxilary tower.

  toh(n-1, t1id, t3id, t2id);
  cout << n << "[" << t1id << " -> " << t2id << "]" << endl;
  toh(n-1, t3id, t2id, t1id);
}

int  main() {

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
  }
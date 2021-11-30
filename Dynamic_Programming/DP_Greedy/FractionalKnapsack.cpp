#include<bits/stdc++.h>
using namespace std;

class Item {
public:
    double val;
    double wt;

};

bool cmp(Item it1, Item it2) {
    double valPerWt1 = (double)it1.val/(double)it1.wt;
    double valPerWt2 = (double)it2.val/(double)it2.wt;

    return valPerWt1 > valPerWt2;
}

// Gets precision -> 1 or 2
int getPrecision(double profit) {
     string s = to_string(profit);
    bool dot = false;
    int count = 1;
    int precisionVal=1;
    for(int i=0; i<s.size(); i++) {
        if(dot) {
            if(count==0){
                if(s[i]!='0')
                    precisionVal = 2;
            }
            count--;
        }
        if(s[i]=='.')
            dot=true;
    }

    return precisionVal;
}

void fractionalKnapsack(int n, Item items[], int cap) {
   
   double profit = 0;
   sort(items, items+n, cmp);

   for(int i=0; i<n; i++) {
       if(cap==0)
           break;
       if(cap>=items[i].wt) {
           // Take full amount
           profit+=(double)items[i].val;
           cap-=items[i].wt;
       }
       else{
           // Take the fractional amount
            double valPerWt = (double)items[i].val/(double)items[i].wt;
            profit += (valPerWt*cap);
            cap=0;
       }
   }

   cout << fixed << setprecision(getPrecision(profit)) << profit << endl;
   
}

int main() {
    int n;
    cin>>n;
  
    Item items[n];
    for(int i=0; i<n; i++) {
        cin >> items[i].val;
    }

    for(int i=0; i<n; i++) {
        cin >> items[i].wt;
    }

    int cap;
    cin>>cap;

    fractionalKnapsack(n, items, cap);
}
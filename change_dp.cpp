#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int get_change(int m , vector<int> &denominations) {
  //std::vector<int> denomiantions = {4,3,1};
  vector<int> minNumCoins(m+1);
  minNumCoins[0]=0;
  for (int i = 1; i <= m; i++){
    minNumCoins[i] = INT_MAX;
    for(int j = 0; j < denominations.size();j++){
      if(i >= denominations[j]){
        int numCoins  = minNumCoins[i-denominations[j]] + 1;
        if(numCoins < minNumCoins[i]){
          minNumCoins[i] = numCoins;
        }
      }
    }
  }
  return minNumCoins[m];
}

int main() {
  int m;
  int denominationsNum;
  std::cin >> m;
  std::cin >> denominationsNum;
  vector<int> denominations(denominationsNum);

  for(int i = 0; i < denominationsNum;i++){
    std::cin >> denominations[i];
  }
  std::cout << get_change(m,denominations) << '\n';
}

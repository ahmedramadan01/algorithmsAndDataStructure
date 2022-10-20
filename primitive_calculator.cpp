#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> minOP(n+1);
  std::vector<int> sequence;
  if(n == 0){
    minOP[n] = 0;
  }
  else if (n==1){
    minOP[n]=0;
  }
  else{
    for(int i = 2; i <= n; i++){
      double p = log10(i) / log10(3);
      if(ceil(log2(i)) == floor(log2(i))){
        minOP[i] = ceil(log2(i));
      }
      else if(p - (int)p == 0){
        minOP[i] = (int)p;
      }
      else if(i % 3 == 0 ){
        minOP[i] = std::min(1 + minOP[i/3],minOP[i-1] +1);
      }
      else if(i%2 == 0){
        minOP[i] = std::min(1 + minOP[i/2], minOP[i-1] + 1);
      }
      else{
        minOP[i] = minOP[i-1] + 1;
      }
    } 
  }

  int j = n;
  while(j > 1){
    sequence.push_back(j);
    if (minOP[j-1] == minOP[j]-1)
			j = j-1;
		else if (j%2 == 0 && (minOP[j/2] == minOP[j]-1))
			j = j/2;
		else if (j%3 == 0 && (minOP[j/3] == minOP[j]-1))
			j = j/3;
  }
  sequence.push_back(1);
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

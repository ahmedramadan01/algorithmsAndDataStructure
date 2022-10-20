#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  if(str1 == str2) return 0;
  int n = str1.size();
  int m = str2.size();

 vector<vector<int>> matrix(
   101,
    vector<int>(101,0)
  );
  for(int i = 0; i <= n ;i++){
    matrix[i][0] = i;
  }
  for(int j = 0; j <= m;j++){
    matrix[0][j] = j;
  }
  for(int i = 1; i <= n;i++){
    for(int j = 1; j <= m;j++){
      int insertion = matrix[i][j-1] + 1;
      int deletion = matrix[i-1][j] + 1;
      int match = matrix[i-1][j-1];
      int mismatch = matrix[i-1][j-1] + 1;

      if(str1[i-1] == str2[j-1]){
        matrix[i][j] = std::min(insertion,deletion);
        matrix[i][j] = std::min(matrix[i][j],match);
      }
      else{
        matrix[i][j] = std::min(insertion,deletion);
        matrix[i][j] = std::min(matrix[i][j],mismatch);
      }
    }
  }
  return matrix[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;

  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

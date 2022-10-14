#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int frequency(vector<int> &a,int left,int right,int element){
  int count = 0;
  for(int i = left; i <= right; i++){
    if(a[i] == element ){
      count++;
    }

  }
  return count; 
}

int get_majority_element(vector<int> &a, int left, int right) {
	if(left==right){
		return a[left];
	}
	int mid = (right - left)/2 +left;
	int left_majority = get_majority_element(a,left,mid);
	int right_majority = get_majority_element(a,mid+1,right);
	if(left_majority == right_majority){
		return left_majority;
	}
	int left_count = frequency(a,left,right,left_majority);
	int right_count = frequency(a,left,right,right_majority);

	if(left_count > (right - left + 1)/2 && left_count > right_count){
		return left_majority;
	}
	else if(right_count > (right - left + 1)/2 && right_count > left_count){
		return right_majority;
	}
	else{
		return -1;
	}
	return -1;

}


int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
#include <iostream>

int add(int a, int b) {
  return a + b;
}

void add_to(int & a, int b) {
  a += b;
}

void another_add_to(int * a, int b) {
  *a += b;
}

int main() {
  const int x{10};
  int y = add(x, x);
  another_add_to(&y, y);
  add_to(y, 2);
  std::cout << y << std::endl;
  
  return 0;
}

int         count_a_occurences(std::string& s);
void        update_loop(const float& dt, std::string*& errors_out);
bool        are_all_positives(std::vector<int>& values, int* negative_indices_out, size_t* negative_count_out);
std::string* concatenate(char* str1, char* str2);
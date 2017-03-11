#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[]) {
  int n, k;
  int i=0;

  cin >> n >> k;
  char *passwd=(char*)malloc(n*sizeof(char));

  passwd[i]='a';

  for (i=1; i<k; ++i)
     (passwd[i-1]=='z') ? (passwd[i]='a') : (passwd[i]=passwd[i-1]+1);

  int j=0;

  for (i=k; i<n; ++i){
    if (passwd[i]==passwd[k-1]){
      passwd[i]=passwd[0];
      j=0;
    }else {
      passwd[i]=passwd[j];
    }
    ++j;
  }

  std::cout << passwd << std::endl;

  return 0;
}

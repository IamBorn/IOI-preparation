#include <vector>
#include <string>
using namespace std;


int cur;
string v[1000000];
int idx[1000000];

void Init(){
  cur = 0;
}
void TypeLetter(char L){
  cur++;
  v[cur] = v[cur-1] + L;
}
void UndoCommands(int U){
  cur++;
  v[cur] = v[cur-U-1];
}
char GetLetter(int P){
  return v[cur][P];
}
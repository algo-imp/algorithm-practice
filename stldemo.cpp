#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())



void test1(){
  vector<int> v(20);
  for(int i=0; i<20; i++){
    v[i] = i+1;
  }

  v.resize(25);
  for(int i=20;i<25; i++){
    v.push_back(i*2); //Writes to elements with indices [25..30], not [20..25] !
  }
  for(int i : v){
    cout << i << " ";
  }
  
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    *it++; //Increment the value iterator is pointint to;
  }

  for(int i : v){
    cout << i << " ";
  }


}

void fin(const string& s){
  // Construct an object to parse strings
  istringstream is(s);

  //Vector to store data
  vector<int> v;

  // Read integer while possible and add it to the vector
  int tmp;
  while(is >> tmp){
    v.push_back(tmp);
  }
  cout << "After fin: ";
  for(int i : v){
    cout << i << " ";
  }
}

void fout(const vector<int>& v){

  // Construct an object to do formatted output
  ostringstream os;

  // Copy all elements from vector<int> to string stream as text
  tr(v,it){
    os << ' ' << *it;
  }

  // Get string from string stream
  string s = os.str();

  //Remove first space character
  if(!s.empty()){
    s = s.substr(1);
  }

  cout << "After fout: " << s << endl;
}

void cp_map_to_vector(){
	/*
  map<string, int> M;
  //...
  vector< pair<string, int> > V(all(M));
	*/
}

void merge_lists(){
  int data1[] = {1, 2, 5, 6, 7, 8, 9, 10};
  int data2[] = {0, 2, 4, 5, 6, 9, 11, 12};

  vector<int> v1(data1, data1 + sizeof(data1)/sizeof(data1[0]));
  vector<int> v2(data2, data2 + sizeof(data2)/sizeof(data2[0]));

  vector<int> tmp(max(v1.size(), v2.size()));

  vector<int> res = vector<int>(tmp.begin(), set_intersection(all(v1), all(v2), tmp.begin()));
}

/*
int main(){
  test1();
  cout << endl;
  string s("1 2 3 4 5");
  fin(s);
  vector<int> v(5);
  fout(v);
  return 0;
}
*/

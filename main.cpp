#include <iostream>
using namespace std;

class Object {
public:
  string name_m;
  int param1 = -1, param2 = -1, param3 = -1;
  Object() = delete;
  Object(string name, int height, int weight, int age){
    name_m = name;
    param1 = height;
    param2 = weight;
    param3 = age;
  }
};

class Compare {
public:
  virtual int compare(Object *h1, Object *h2) = 0;
};

class CompareHeight : public Compare {
public:
  int compare (Object *h1, Object *h2){
    if (h1->param1 < h2->param1) return -1;
    else if (h1->param1 > h2->param1) return 1;
    else return 0;
  }
};

class CompareWeight : public Compare {
public:
  int compare (Object *h1, Object *h2){
    if (h1->param2 < h2->param2) return -1;
    else if (h1->param2 > h2->param2) return 1;
    else return 0;
  }
};

class CompareAge : public Compare {
public:
  int compare (Object *h1, Object *h2){
    if (h1->param3 < h2->param3) return -1;
    else if (h1->param3 > h2->param3) return 1;
    else return 0;
  }
};

class Comparator {
private:
  Compare *comparator = nullptr;
public:
  Comparator () = delete;
  Comparator (Compare *comparator){ this->comparator = comparator; }
  int compare(Object *h1, Object *h2){
    if(this->comparator) return comparator->compare(h1, h2);
    return -2;
  }
};

int main(){
  Object *h1 = new Object("x", 150, 50, 21);
  Object *h2 = new Object("y", 170, 70, 20);
  Comparator *cw = new Comparator(new CompareWeight);
  Comparator *ch = new Comparator(new CompareHeight);
  Comparator *ca = new Comparator(new CompareAge);

  cout << cw->compare(h1, h2) << endl;
  cout << ch->compare(h1, h2) << endl;
  cout << ca->compare(h1, h2) << endl;

  return 0;
}

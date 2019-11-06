#include <iostream>
#include <fstream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ofstream;

struct Person{
  char name[20];
  int age;
};

int main(int argc, char* argv[]){
  char filename[20];
  cout << "Please input the people filename: ";
  cin >> filename;

  ofstream outputFile(filename, ofstream::app);
  if (outputFile.fail()){
    cerr << "Cannot open file " << filename << endl;
    return 1;
  }

  Person person;
  cout << "Name: ";
  cin >> person.name;
  cout << "Age: ";
  cin >> person.age;

  outputFile << person.name << " " << person.age << endl;

  outputFile.close();
  return 0;

}

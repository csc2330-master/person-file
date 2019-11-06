#include <iostream>
#include <fstream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;

struct Person{
  char name[20];
  int age;
};

void WritePerson(ostream&, const Person&);
bool ReadPersonFromKeyboard(istream&, Person&);
void ReadPerson(istream&, Person&);

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
  do{
    if (!ReadPersonFromKeyboard(cin, person))
      break;
    WritePerson(outputFile, person);
  }while (true);

  outputFile.close();

  cout << endl << endl << endl << "Showing the contents of the file"
       << endl << endl;
  cout << "Input file: ";
  cin >> filename;
  ifstream inputFile(filename);
  if (inputFile.fail()){
    cerr << "Could not open the file for reading " << filename << endl;
    return 1;
  }
  ReadPerson(inputFile, person);
  while (!inputFile.fail()){
    WritePerson(cout, person);
    ReadPerson(inputFile, person);
  }
  inputFile.close();
  return 0;

}

void WritePerson(ostream& output, const Person& person){
  output << person.name << " " << person.age << endl;
}
bool ReadPersonFromKeyboard(istream& input, Person& person){
  cout << "Name: ";
  input >> person.name;
  if (strcmp(person.name, "finish") == 0){
    return false;
  }

  cout << "Age: ";
  input >> person.age;
  while (input.fail()){
    cerr << "Wrong input!" << endl;
    input.clear();
    input.ignore(255, '\n');
    cout << "Age: ";
    input >> person.age;
  }
  return true;
}
void ReadPerson(istream& input, Person& person){
  input >> person.name >> person.age;
}

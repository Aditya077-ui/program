#include<iostream>
#include<map>
#include<cstring>
using namespace std;
enum Grade{A, A_minus, B, B_minus, C, C_minus, D, F};
map<int,string> m {
    {0, "A"},
    {1, "A_minus"},
    {2, "B"},
    {3, "B_minus"},
    {4, "C"},
    {5, "C_minus"},
    {6, "D"},
    {7, "F"}
};

class student{
    private:
    string name;
    long booksID[5];
    int count=0;
    Grade g;
    public:
    string getname();
    void setName(string name);
    void issuebook(long ID);
    long getissuedbooks();
    void setGrade(Grade);
    void getGrade();
};

  void student::setName(string name){
     this->name=name;
  }
    string student::getname()
  {
      return name;
  }
  void student::issuebook(long ID){
      if(count<5){
          booksID[count] = ID;
         
      }
      else{
          cout<<"the number of books borrowed has reached its limit."<<endl;
      } 
       count++;
  }
    long student::getissuedbooks()
    { int i;
        for(i=0;i<count;i++){
            cout<<booksID[i]<<endl;
        }
        cout<<"the number of books borrowed is: ";
        return booksID[count];
    

    }    
    void student::setGrade(Grade g){
    this->g = g;
}
    void student::getGrade(){
    cout<<endl<<"Grade of the student is "<< m[g];
    }
  
   int main()
   {
        student s1;
       
       s1.setName("Aditya");
       
       cout<<s1.getname()<<endl;
       s1.issuebook(201901);
       s1.issuebook(201902);
       s1.issuebook(201903);
       s1.issuebook(201904);
       s1.issuebook(201905);
       cout<<"the borrowed books IDs are: "<<"\n"<<s1.getissuedbooks();
        s1.setGrade(B_minus);
        s1.getGrade();

      return 0;
   }
    
   
   



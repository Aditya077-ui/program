#include<iostream>
using namespace std;

class student{
    private:
    string name;
    long booksID[5];
    int count=0;
    public:
    string getname();
    void setName(string name);
    void issuebook(long ID);
    long getissuedbooks();
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

      return 0;
   }
    
   
   



#include<iostream>
#include<cstring>
using namespace std;

class book_shop{
    private:
    char *author, *title, *publisher;
    float *price;
    int *stock_position;
    int count=0;
    public:
    book_shop() {                      //constructor
        author = new char[50];
        title = new char[50];
        publisher = new char[50];
        price = new float;
        stock_position = new int ;
    }
    void getdata(void);
    void display_info(void);
    void search(void);
    void buybook();
};

void book_shop::getdata(void){
    cout<<"enter the title of the book: "<<"\n";
    cin>>title;
    cout<<"enter the author of the book: "<<"\n";
    cin>>author;
    cout<<"enter the publisher of the book: "<<"\n";
    cin>>publisher;
    cout<<"enter the price of the book: "<<"\n";
    cin>>*price;
    cout<<"enter the stock position of the book: "<<"\n";
    cin>>*stock_position;

}
void book_shop::display_info(void){
    cout<<"title of book is: "<<title<<endl;
    cout<<"author of book is: "<<author<<endl;
    cout<<"publisher of book is: "<<publisher<<endl;
    cout<<"price is: "<<*price<<endl;
    cout<<"stock_position is: "<<*stock_position<<endl;
}
void book_shop:: search(void){
    char name[50],writer[50];
    cout<<"enter book name:"<<"\n";
    cin>>name;
    cout<<"enter writer name: "<<"\n";
    cin>>writer;
    if ((strcmp(title,name)==0) && (strcmp(author,writer)==0))
    {
       cout<<"entered information book is available."<<endl;
    }
else{
    cout<<"the book you are searching is not available.sorry!!!"<<endl;
}
} 
 void book_shop::buybook(){
     int count;
     cout<<"enter the number of copies you want to buy: "<<"\n";
     cin>>count;
     if(count<=*stock_position){
         *stock_position=*stock_position-count;
     }
     cout<<"books bought successfully!!"<<endl;
     cout<<" total price of books: "<<(*price)*count<<endl;

 }

 int main(){
     book_shop book;
     book.getdata();
     book.display_info();
     book.search();
     book.buybook();
 }







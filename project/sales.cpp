
#include"sales.h"
#include<iostream>

void menu::main_menu(void){
    char ch;
    while (1)
    {
    
        cout <<"S A L E S M A N A G E M E N T"<<endl;
        cout <<"1: PURCHASE PRODUCTS"<<"\n" ;
        cout <<"2: LIST OF PRODUCTS"<<"\n" ;
        cout <<"3: EDIT PRODUCTS FILE"<<"\n" ;
        cout <<"4: BILLS REPORT"<<"\n" ;
        cout <<"0: QUIT"<<"\n" ;
        
        cout <<"Enter Your Choice :  "<<endl ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.purchase() ;
        }
        else if (ch == '2')
        {
            product p ;
            p.list_of_item() ;
        }
        else if (ch == '3')
            edit_menu() ;
        else if (ch == '4')
        {
            bill a ;
            a.bill_list();
        }
        else if (ch == '0')
            break ;
    }
}
void menu :: edit_menu(void)
{
    char ch ;
    while (1)
    {
        cout <<"E D I T M E N U"<<"\n" ;
        cout <<"1: ADD PRODUCTS"<<"\n" ;
        cout <<"2: MODIFY PRODUCTS"<<"\n" ;
        cout <<"3: DELETE PRODUCTS"<<"\n" ;
        cout <<"0: EXIT"<<"\n" ;
        cout <<"Enter Choice:  "<<"\n" ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.add_item() ;
            break ;
        }
        else if (ch == '2')
        {
            product p ;
            p.delete_item() ;
            break ;
        }
        else if (ch == '0')
            break ;
    }
}
int product :: last_code(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(product)))
        t = itemcode ;
    file.close() ;
    return t ;
}
void product :: list_of_item(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0) ;
    cout<<"LIST OF ITEMS"<<endl;
    while (file.read((char *) this, sizeof(product)))
    {
       cout<<"itemcode : "<<itemcode;
       cout<<"itemname : "<<itemname;
       cout<<"itemcost : "<<itemcost;
       cout<<"itemprice : "<<itemprice;
        getche() ;
    file.close () ;
}
}
void product::add_item(void){
     int tcode, valid ;
    char ch, t_itemcost[10], t_itemprice[10] ;
    tcode = last_code() ;
    tcode++ ;
    do
{
      
        cout <<"ADDITION OF PRODUCTS"<<"\n" ;
        cout <<"Item Code : " <<tcode ;
        cout <<"Item Name : "<<"\n" ;
        cout <<"Item Cost : "<<"\n" ;
        cout <<"Item Price : "<<"\n" ;
do
        {
            valid = 1 ;
            cout<<"ENTER ITEM NAME TO ADD IN THE MENU"<<"\n" ;
            
            cout <<"Item Name : "<<"\n" ;
            gets(itemname) ;
            if (itemname[0] == '0')
                return ;
            if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
            {
                valid = 0 ;
            cout <<"\7 Range = 1..20" ; 
          getch();
              }
        }
        while (!valid) ;    
        do
        {
            valid = 1 ;
           
            cout<<"ENTER ITEM COST TO ADD IN THE MENU"<<"\n" ;
            
            cout <<"Item Cost : "<<"\n" ;
            gets(t_itemcost) ;
            itemcost = atof(t_itemcost) ;
            if (t_itemcost[0] == '0')
                return ;
            if (itemcost < 1 || itemcost > 800)
            {
                valid = 0 ;
               
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
            
            cout<<"ENTER ITEM PRICE TO ADD IN THE MENU"<<"\n" ;
            
            cout<<"Item Price : "<<"\n" ;
            gets(t_itemprice) ;
            itemprice = atof(t_itemprice) ;
            if (t_itemprice[0] == '0')
                return ;
            if (itemprice < itemcost || itemprice > 1000)
            {
                valid = 0 ;
                
                cout <<"\7 Range = " <<itemcost <<"..1000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            
            cout <<"Do you want to save this record (y/n) : "<<"\n" ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'Y')
        {
            itemcode = tcode ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::out | ios::app ) ;
            file.write((char *) this, sizeof(product)) ;
            file.close() ;
            tcode++ ;
        }
        do
        {
            
            cout<<"Do you want to add more records (y/n) : "<<"\n" ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
} 
void product :: display_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
         
            cout <<"Item Code : "<<itemcode <<endl;
           
            cout <<"Item Name : "<<itemname<<endl ;
          
            cout <<"Item Cost : "<<itemcost<<endl ;
            
            cout <<"Item Price : "<<itemprice<<endl ;
            break ;
        }
    }
    file.close() ;
}
int product :: item_found(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}
int product :: recordno(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        found++ ;
        if (itemcode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}
void product :: delete_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("PRODUCT.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
}
void product :: delete_item(void)
{
    char t_code[5], ch ;
    int t, tcode ;

    cout <<"Press <ENTER> to see list of items."<<"\n" ;
    cout <<"Enter Item Code of the item to be deleted : "<<"\n" ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
        
       
        cout <<"Press <ENTER> to Exit"<<"\n" ;
       
        cout <<"Enter Item Code of the item to be deleted : "<<"\n" ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }

    if (!item_found(tcode))
    {
        
        cout <<"\7Record not found"<<"\n" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        
        
        cout <<"Do you want to delete this record (y/n) : "<<"\n" ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    delete_record(tcode) ;

    cout <<"\7Record Deleted"<<endl ;
    getch() ;
}


void product :: sort(void)
{
    int i=0,j ;
    product arr[100] ;
    product temp ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(product)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
        {
            if (arr[j].itemcode > arr[j+1].itemcode)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    file.open("PRODUCT.DAT", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(product)) ;
    file.close() ;
}
void product :: purchase(void)
{
    bill a ;
    int t_billno, purchased=0 ;
    t_billno = a.last_billno() ;
    t_billno++ ;
    char t_code[5], ch;
    float t_quantity ;
    int t, tcode, i=0, valid ;
    float qty ;
    int t_itemcode ;
    float t_qty, t_cost, t_price ;
    char t_itemname[30] ;
    int d1, m1, y1 ;

    do
    {
    
        cout <<"Press <ENTER> to see the list" ;
        cout <<"Enter Item Code of the item to be Purchase : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        if (tcode == 0)
        {
            list_of_item() ;
          
            cout <<"Press <ENTER> to Exit" ;

            cout <<"Enter Item Code of the item to be Purchase : " ;
            gets(t_code) ;
            t = atoi(t_code) ;
            tcode = t ;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
        }
    
        if (!item_found(tcode))
        {
        
            cout <<"\7Item Code not found" ;
            getch() ;
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        
        cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
        display_record(tcode) ;
        do
        {
            valid = 1 ;
            
            cout <<"ENTER QUANTITY TO BE PURCHASE IN Kg." ;
            cout <<"Quantity : " ;
            cin>>t_quantity ;
            qty=t_quantity ;
            if (t_quantity == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
            if (qty < 1 || qty > 800)
            {
                valid = 0 ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            
            cout <<"Do you want to cancel this purchase (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'N')
        {
            purchased = 1 ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::in) ;
            file.seekg(0,ios::beg) ;
            while (file.read((char *) this, sizeof(product)))
            {
                if (itemcode == tcode)
                {
                    t_itemcode = itemcode ;
                    strcpy(t_itemname,itemname) ;
                    t_cost = itemcost ;
                    t_price = itemprice ;
                    t_qty = qty ;
                    a.add_bill(t_billno,t_itemcode,t_itemname,t_qty,t_cost,t_price) ;
                    i++ ;
                    break ;
                }
            }
            file.close() ;
        }
        do
        {
            
            cout <<"Do you want to purchase more (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
    a.prepare_bill(t_billno) ;
}

   


#include"sales.h"
#include<iostream>
#include<fstream>
#include<cstring>

int bill::last_billno(void){
    fstream file;
    file.open("BILL.DAT",ios::in);
    file.seekg(0,ios::beg);
    int t=0;
    while(file.read((char*) this, sizeof (bill)))
    t=billno;
    file.close();
    return t;
}
void bill :: add_bill(int t_billno, int t_itemcode, char t_itemname[30], float t_qty, float t_cost, float t_price)
{
    int d1, m1, y1 ;
    code = t_itemcode ;
    strcpy(name,t_itemname) ;
    cost = t_cost ;
    price = t_price ;
    quantity = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILL.DAT", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(bill)) ;
    file.close() ;
}
void bill :: prepare_bill(int t_billno)
{
    int d1, m1, y1 ;
    float total=0.0, total_bill=0.0 ;
    cout <<"CUSTOMER BILL" ;

    cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1<<endl;
    
    cout <<"ITEMS PURCHASED"<<endl ;
    cout <<"Item code\t Item name\t Cost Price\t Qty Total";
         
    int row=11 ;
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    while (file.read((char *) this, sizeof(bill)))
    {
        if (billno == t_billno)
        {
            
            cout <<"BILL NO. # " <<billno ;
            
            cout <<code<<endl ;
            
            cout <<name<<endl ;
            
            cout <<cost<<endl ;
        
            cout <<price<<endl ;
        
            cout <<quantity<<endl ;
            total = quantity * price;
    
            cout <<total<<endl ;
            total_bill = (total_bill + total);
            row++ ;
        }
    }
    file.close() ;

    cout <<"TOTAL BILL: Rs." <<total_bill <<" /=" ;
    getch() ;
}
void bill :: bill_list(void)
{
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total=0.0, total_bill=0.0 ;

    cout <<"LIST OF BILLS" ;
    
    cout <<"Billno.\t Date\t Item Code\t Item name\t Cost Price\t Qty Total" ;
    while (file.read((char *) this, sizeof(bill)))
    {
        row++ ;
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {

                cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
                total_bill = 0.0 ;
                row++ ;
            }

            cout <<billno ;
        }
        flag = 1 ;
        
        cout <<dd <<"/" <<mm <<"/" <<yy ;
        
        cout <<code<<endl ;
    
        cout <<name<<endl ;
        
        cout <<cost<<endl ;
        
        cout <<price<<endl ;
        
        cout <<quantity<<endl ;
        total = (quantity * price) ;
        
        cout <<total ;
        total_bill = total_bill + total ;
        if ( row >= 23 )
        {
            row = 5 ;
        
            cout <<"Page no. : " <<pageno ;
            pageno++ ;
    
            cout <<"Press any key to continue..." ;
            getche() ;
        
            
            cout <<"LIST OF BILLS" ;
            
            cout <<"Billno.\t Date\t Item Code\t Item name\t CostPrice\t Qty Total" ;
    
        }
        prev_billno = billno ;
    }
    row++ ;
    
    cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
    if ( !found )
    {
        
        cout <<"\7Records not found" ;
    }
    
    cout <<"Page no. : " <<pageno ;

    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}


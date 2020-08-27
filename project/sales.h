#pragma once
#include<iostream>
#include<fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
using namespace std;

class menu
{
    private :
    void edit_menu(void) ;
public :
    void main_menu(void) ;

} ;
class product
{
    
    
    private :
    int itemcode ;
    char itemname[30] ;
    
    float itemcost, itemprice ;
    int last_code(void) ;
    void delete_record(int) ;
    void display_record(int) ;
    int item_found(int) ;
    int recordno(int) ;
    void sort(void) ;


public :
    
    void add_item(void) ;
    void list_of_item(void) ;
    void delete_item(void) ;
    void purchase(void);


} ;
class bill
{
    private :
    int code, billno, length ;
    int dd, mm, yy ;
    float cost, price, quantity ;
    char name[30] ;
public :
    void bill_list(void);
    void prepare_bill(int) ;
    int last_billno(void) ;
    void add_bill(int, int t_itemcode, char *t_itemname, float t_qty,
                  float t_cost, float t_price) ;

} ;


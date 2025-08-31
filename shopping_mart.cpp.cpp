#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class dmart
{
    private:
        char name[10][20];   // Stores product names
        int p[10],q[10],t[10],c; // p = price, q = quantity, t = total price per product, c = counter

    public:
        dmart()
        {
            c=0;  // Initialize product count
        }

        void get();
        void show();
        void calculate();
        void search_data();
        void replace_product();
        void remove_product();
        void quantity_change();
        void show_list();  // NEW FUNCTION to display full list
};

// Function to change quantity of existing item
void dmart::quantity_change()
{
    int d=0,flag=0,i;
    char n1[20];
    cout<<"\n Enter your item to search: ";
    cin>>n1;

    for(i=0;i<c;i++)
    {
        d=strcmp(name[i],n1);
        if (d==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"Enter new quantity: ";
        cin>>q[i];
        t[i]=p[i]*q[i];
        cout<<"\n Quantity updated successfully!";
    }
    else
        cout<<"\n Item not available! Press 1 to add new items.";
}

// Function to replace product details
void dmart::replace_product()
{
    int d=0,flag=0,i;
    char n1[20];
    cout<<"\n Enter your item to search : ";
    cin>>n1;

    for(i=0;i<c;i++)
    {
        d=strcmp(name[i],n1);
        if (d==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
       cout<<"\n Enter name, price and quantity of item : ";
        cin>>name[i]>>p[i]>>q[i];
        t[i]=p[i]*q[i];
        cout<<"\n Item replaced successfully!";
    }
    else
        cout<<"\n Item not available! Press 1 to add new items.";
}

// Function to remove product
void dmart :: remove_product()
{
    int d=0,flag=0,i;
    char n1[20];
    cout<<"\n Enter your item to remove: ";
    cin>>n1;

    for(i=0;i<c;i++)
    {
        d=strcmp(name[i],n1);
        if (d==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
       for(int j=i+1;j<c;j++)
       {
           strcpy(name[i],name[j]);
           p[i]=p[j];
           q[i]=q[j];
           t[i]=t[j];
       }
       c--;
       cout<<"\n Item removed successfully!";
    }
    else
        cout<<"\n Item not available! Press 1 to add new items.";
}

// Function to add new product
void dmart::get()
{
    cout<<"\n Enter product name: ";
    cin>>name[c];
    cout<<" Enter product price: ";
    cin>>p[c];
    cout<<" Enter product quantity: ";
    cin>>q[c];
    t[c]=p[c]*q[c];
    c++;
}

// Function to show entered products in simple list
void dmart::show()
{
    for(int i=0;i<c;i++)
    {
         cout<<"\n"<<name[i]<<"\t"<<p[i]<<"\t"<<q[i]<<"\t"<<t[i];
    }
}

// Function to calculate total items and total bill
void dmart::calculate()
{
    int t_items=0,sm=0;

    for(int i=0;i<c;i++)
    {
        sm=sm+t[i];
        t_items=t_items+q[i];
    }
    cout<<"\n Total items : "<<t_items;
    cout<<"\n Total amount to be paid : "<<sm;
}

// Function to search a product
void dmart::search_data()
{
    int d=0,flag=0,i;
    char n1[20];
    cout<<"\n Enter your item to search : ";
    cin>>n1;

    for(i=0;i<c;i++)
    {
        d=strcmp(name[i],n1);
        if (d==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\n Item is available:";
        cout<<"\n-----------------------------------------------------";
        cout<<"\n"<<name[i]<<"\t"<<p[i]<<"\t"<<q[i]<<"\t"<<t[i];
        cout<<"\n-----------------------------------------------------";
    }
    else {
        cout<<"\n Item is not available!";
        cout<<"\n Please press 1 to add items.";
    }
}

// NEW FUNCTION: Show full list in table format
void dmart::show_list()
{
    cout<<"\n-----------------------------------------------------";
    cout<<"\n No. \tName\tPrice\tQty\tTotal";
    cout<<"\n-----------------------------------------------------";
    for(int i=0;i<c;i++)
    {
        cout<<"\n "<<i+1<<"\t"<<name[i]<<"\t"<<p[i]<<"\t"<<q[i]<<"\t"<<t[i];
    }
    cout<<"\n-----------------------------------------------------";
}

int main()
{
    dmart d;
    int ch=0;

    // 🎉 WELCOME BANNER
    cout<<"\n===============================================";
    cout<<"\n     WELCOME TO SHOPPING MART MANAGEMENT SYSTEM";
    cout<<"\n===============================================\n";

    do
    {
        cout<<"\n\n";
        cout<<"\n 1: Add new product";
        cout<<"\n 2: Show simple product list";
        cout<<"\n 3: Calculate total amount";
        cout<<"\n 4: Search product";
        cout<<"\n 5: Replace product details";
        cout<<"\n 6: Remove product";
        cout<<"\n 7: Change product quantity";
        cout<<"\n 8: Show full product list (with numbering)";
        cout<<"\n 0: Exit ";
        cout<<"\n Select your choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            d.get();
            break;

        case 2:
            d.show();
            break;
        case 3:
            d.calculate();
            break;
        case 4:
            d.search_data();
            break;
        case 5:
            d.replace_product();
            break;
        case 6:
            d.remove_product();
            break;
        case 7:
            d.quantity_change();
            break;
        case 8:
            d.show_list();  // Call the new function
            break;
        case 0:
            cout<<"\n Thank you for using Shopping Mart! Goodbye!\n";
            break;

        default:
            cout<<"Choose the correct option!";
        }

    }while(ch!=0);

    getch();
}

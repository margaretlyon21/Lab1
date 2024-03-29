#include <iostream> 
#include <iomanip>
using namespace std;

//function Prototypes 
void calcSales(const int[], const double[], double[], int);
void showOrder(const double[], const int[], int);
void dualSort(int[],double[],int);
void showTotals(const double[],const int[],int);
void swap(double&, double&);
void swap(int&, int&); 

int main()
{
    //NUM_PRODS is the number of products produced. 
    const int NUM_PRODS = 9;
    struct salesinfo{
        int id[NUM_PRODS] = { 914, 915, 916, 917, 918, 919, 920, 921, 922};
        int units[NUM_PRODS] = {842, 416, 127, 514, 437, 269, 97, 492, 212};
        double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95};
        double sales[NUM_PRODS];
    };

    salesinfo info;
    

    //Calculate each products sales
    calcSales(info.units, info.prices, info.sales, NUM_PRODS);

    //Sort the elements into the sales array in descending
    //order and shuffle the ID numbers in the id array to
    //keep them in parallel. 
    dualSort(info.id, info.sales, NUM_PRODS);

    //Set the numeric output formatting. 
    cout << setprecision(2) << fixed << showpoint;

    //Display the products and sales amounts. 
    showOrder(info.sales, info.id, NUM_PRODS);

    //Display total units sold and total sales. 
    showTotals(info.sales, info.units, NUM_PRODS);
    return 0;
}
    //Definition of calcSales. Accepts units, prices, and sales
    //arrays as arguments. The size of these arrays s passed
    //into the num parameter. this function calculates each
    //products sales by multiplying its units sold by each units
    //price. The result is stored in the sales array.

    void calcSales(const int units[], const double prices[], double sales[], int num){
        for (int index = 0; index < num; index++)
            sales[index] = units[index] * prices[index];
    }

    //Definition of function dualsort. Accepts id and sales arrays
    // as arguments, The size of these arrays is passed into size.
    // This fucntion perfroms in a decending order selection sort on 
    // the sales array. the elements of the id array are exchanged
    //identically as those of the sales array. Size is the number
    //of elements in each array. 

    void dualSort(int id[], double sales[], int size){
        int start, maxIndex, tempid;
        double maxValue;

        for (start = 0; start < (size - 1); start++){
            maxIndex = start;
            maxValue = sales[start];
            tempid = id[start];
            for (int index = start + 1; index < size; index++){
                if (sales[index] > maxValue){
                    maxValue = sales[index];
                    tempid = id[index];
                    maxIndex = index;
                }
            }
            swap(sales[maxIndex], sales[start]);
            swap(id[maxIndex], id[start]);
        }
    }
    //the swap function swaps double a and b in memory
    void swap(double &a, double &b){
        double temp = a;
        a = b;
        b = temp;
    }

    // the swap function swaps ints a and b in memory
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    //Definition of showOrder function. Accepts sales and id arrays
    //as arguments. The side of these arrays is passed into num. 
    //The function first displays a heading, then the stored list
    //of product numbers and sales.
    void showOrder(const double sales[], const int id[], int num){
        cout << "Product Number\tSales\n";
        cout <<"-------------------------\n";
        for (int index = 0; index < num; index++){
            cout << id[index] << "\t\t$";
            cout << setw(8) << sales[index] << endl;
        }
        cout << endl;
    }

    //Definition of ShowTotals function. Accepts sales and ID arrays
    // as arguments. The size of these arraus is passed into num. 
    // The funtion first calculates the total units (of all
    //products) sold and the total sales. It then displays these
    // amounts. 

    void showTotals(const double sales[], const int units[], int num){
        int totalUnits = 0;
        double totalSales = 0.0;

        for (int index = 0; index < num; index++){
            totalUnits += units[index];
            totalSales += sales[index];
        }
        cout <<"Total units Sold:      " << totalUnits << endl;
        cout <<"Total sales:     $" << totalSales << endl;
    }


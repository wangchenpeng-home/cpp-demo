#include <iostream>
#include <string>

const int STKS = 4;

using namespace std;

class Stock
{
private:
    string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();
    Stock(const string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);//the number of shares bought
    void sell(long num, double price);
    void update(double price);// update shares price
    void show() const;
    const Stock & topval(const Stock & s) const;
};

Stock::Stock() // default constructor
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const string &co, long n, double pr)
{
    company = co;

    if(n < 0)
    {
        cout << "Number of shares can't be negative; "
            << company << " shares set to 0;\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

//class destructor
Stock::~Stock()
{
}

void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        cout << "Number of shares can't be negative; "
        << " Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if(num < 0)
    {
        cout << "Number of shares can't be negative; "
        << " Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        cout << "You can't sell more than you have! "
        << "transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);

    cout << "Company: " << company << endl;
    cout << "Shares:  " << shares << endl;
    cout << "Share Price: $" << share_val << endl;

    cout.precision(2);
    cout << "Total Worth: $" << total_val << endl;

    cout << endl;
    //restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
    {
        return s;
    }
    else
    {
        return *this;
    }
}


int main(void)
{
    //create an arry initialized objects
    Stock stocks[STKS] =
    {
        {"NanoSmart",12,20.0},
        {"Boffo Objects",200,2.0},
        {"Monolithic",130,3.25},
        {"Fleep Enterprises",60,6.5}
    };
    int st;
    for(st = 0; st < STKS; st++)
        stocks[st].show();

    //set pointer to first element
    const Stock * top = &stocks[0];
    for(st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);

    cout << "\nNost valuable holding:\n";
    top->show();

    return 0;
}

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val;}
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num,double price);
    void update(double price);
    void show() const;
    Stock();//Default constructor
    Stock(const std::string & co, long n=0,double pr = 0.0);
    ~Stock();
    const Stock & topval(const Stock & s) const;
};

class Time
{
private:
    int hours;
    int minute;
public:
    Time();
    Time(int h,int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0,int m = 0);
    Time Sum(const Time & t) const;
    void Show() const;
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const;
    friend Time operator*(double m, const Time & t);
    friend ostream & operator<<(ostream & os, const Time & t);
};

using std::string;
class Tennis
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    Tennis(const string & fn = "None",const string & ln = "None",bool ht = false);
    void Name();
    bool HasTable() {return hasTable;};
    void ResetTable(bool v) {hasTable = v;};
};

class RatedPlayer:public Tennis
{
private:
    unsigned int rating;
public:
    RatedPlayer ( unsigned int r = 0, const string & fn = "None",const string & ln = "None", bool ht = false);
    RatedPlayer( unsigned int r, const Tennis & tp);
    unsigned int Rating() const { return rating;};
    void ResetRating ( unsigned int r) {rating = r;};
};
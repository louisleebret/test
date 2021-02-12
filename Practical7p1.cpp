#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Date{
  protected:
    int day;
    int month;
    int year;

  public:
    Date(const int day, const int month, const int year){
      this->day = day;
      this->month = month;
      this->year = year;
    }

    int get_day(){
      return this->day;
    }

    int get_month(){
      return this->month;
    }

    int get_year(){
      return this->year;
    }

};


class Blood{
  protected:
    int sys;
    int dias;
    Date date;

  public:
    Blood(int sys,int dias, Date date):date(date){
      this->sys = sys;
      this->dias = dias;
      this->date = date;
    }

    int get_sys(){
      return this->sys;
    }

    int get_dias(){
      return this->dias;
    }

    Date get_Date(){
      return this->date;
    }

    void print_record(){
      cout<<"Systolic: "<<sys<<" Diastolic: "<<dias<<" taken on: "<<date.get_day()<<", "<<date.get_month()<<" ,"<<date.get_year()<<endl;
    }



};

class Patient {       
  private:            
    string name;
    vector<Blood> blood_records;

  public:

  Patient(string name){
    this->name=name;
    this->blood_records = vector<Blood>();
  }

  void addRecord(Blood record){
    this->blood_records.push_back(record);
  }

  void print_patient_records(){
    cout<<"-------Patient: "<<this->name<<" ---------"<<endl;
    for(int i = 0;i<this->blood_records.size();i++){
      this->blood_records[i].print_record();
    }
  }

  void printReport(){
    vector<Blood> abnormal = vector<Blood>();

    int max = 140;
    double avg_dias = 0;

    for(int i = 0;i<this->blood_records.size();i++){

      avg_dias += blood_records[i].get_dias();

      if(blood_records[i].get_sys()>max){
        abnormal.clear();
        abnormal.push_back(blood_records[i]);
        max = blood_records[i].get_sys();
      }
      else if (blood_records[i].get_sys()==max){
        abnormal.push_back(blood_records[i]);
      }
    }

    cout<<"----Patient: "<<this->name<<" ------"<<endl;

    if(abnormal.size()==0){
      cout<<"no abnormal measurments"<<endl;
    }
    else{
      cout<<"Abnormal systolic preasure: "<<endl<<endl;
      for(int i = 0;i<abnormal.size(); i++){
        cout<<"systp "<<abnormal[i].get_sys()<<" diasp "<<abnormal[i].get_dias()<<" taken on: "<<abnormal[i].get_Date().get_day()<<", "<<abnormal[i].get_Date().get_month()<<" ,"<<abnormal[i].get_Date().get_year()<<endl;

        
      }
      avg_dias = avg_dias/this->blood_records.size();
      cout<<"The average diastolic pressure is: "<<avg_dias<<endl<<endl;
    }


  }
 

};


int main()
{
  Patient mary = Patient("Mary");
  Patient john = Patient("John");
  mary.addRecord(Blood(94,61, Date(2,5,2013))); 
  mary.addRecord(Blood(97,65, Date(3,5,2013))); 
  mary.addRecord(Blood(144,99, Date(4,5,2013)));
  mary.addRecord(Blood(123,88, Date(5,5,2013)));
  mary.addRecord(Blood(177,110, Date(6,5,2013)));
  mary.addRecord(Blood(145,89, Date(7,5,2013)));

  john.addRecord(Blood(88,57, Date(15,5,2013)));
  john.addRecord(Blood(95,61, Date(16,5,2013)));
  john.addRecord(Blood(114,80, Date(17,5,2013)));
  john.addRecord(Blood(151,96, Date(18,5,2013)));
  john.addRecord(Blood(176,104, Date(19,5,2013)));
  john.addRecord(Blood(176,110, Date(20,5,2013)));

  mary.printReport();
  cout<<endl;
  john.printReport();
}
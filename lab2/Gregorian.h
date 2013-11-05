
namespace lab2 {

  class Gregorian : Middle {
    private: 
      bool isLeepYear() const;

    public:
      int year() const; 

      int month() const; 

      int day() const; 

      int week_day() const; 

      int days_per_week() const; 

      int days_this_month() const; 

      int months_per_year() const;

      std::string week_day_name() const; 

      std::string month_name() const;

      void add_month(int n = 1);

  }

}


class Sales_item {
public:
    inline double avg_price() const;
    bool same_isbn(Sales_item &it) const {
        return it->isbn == isbn;
    }
    Sales_item():units_sold(0), revenue(0.0) {
    }
private:
    string isbn;
    int units_sold;
    double revenue;
}

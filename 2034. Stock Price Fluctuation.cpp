class StockPrice {
private:
    std::map<int, int> timestampPriceMap;
    std::map<int, int> priceMap;


public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        auto it = timestampPriceMap.find(timestamp);
        if (it != timestampPriceMap.end()) {
            priceMap[it->second]--;
            if (priceMap[it->second] == 0)
                priceMap.erase(it->second);
        }
        timestampPriceMap[timestamp] = price;
        priceMap[price]++;
    }
    
    int current() {
        auto it = (--timestampPriceMap.end());
        return it->second;
    }
    
    int maximum() {
        auto it = (--priceMap.end());
        return it->first;
    }
    
    int minimum() {
        auto it = priceMap.begin();
        return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
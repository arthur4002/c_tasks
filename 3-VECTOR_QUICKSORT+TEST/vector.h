#include <iostream>
using u64 = uint64_t;
const u64 DefaultVectorSize = 8;
class Vector {
    private:
    u64 * data;
    size_t size, reserved;

    void realloc() {
        size_t new_reserved = reserved * 2;
        u64 * new_data = new u64[new_reserved];
        for(u64 i = 0; i < size; ++i) {
            new_data[i]=data[i];
        }
        delete [] data;
        data=new_data;
        reserved=new_reserved;
        return;
    }

    u64 separation (u64 start, u64 stop, bool reverse) { 
    u64 i = start - 1;
    for (u64 j = start; j<=stop; j++) {
        if (data[j] < data[stop]) {
            i++;
            std::swap(data[i],data[j]);
        }
    }
    std::swap(data[i+1], data[stop]);
    return i+1;
    }

    public:
    Vector(u64 user_size = DefaultVectorSize) {
        data = new u64[user_size];
        reserved = user_size;
        size = 0;
    }
    ~Vector () {
        delete [] data;
    }

    void push_back(u64 value) {
        if (size<reserved) {
            data[size]=value;
            ++size;
            return;
        }
        realloc();
        data[size]=value;
        ++size;
        return;
    }

    void PrintVector() {
        std::cout << "[";
        for(u64 i = 0; i < size; ++i) {
            std::cout << data[i] << ", ";
        }
        std::cout << "]" << std::endl;
        return;
    }

    void pop_back() {
        size--;
        return;
    }

    u64 get_element(u64 index) {
        return data[index];
    }

    void QuickSort(bool reverse = true) {
    u64 start = 0;
    u64 stop = size;    
    if (start-stop<=1) {
        return;
    }

    u64 element = separation(start,stop, reverse);
    separation(start,element-1, reverse);
    separation(element+1,stop, reverse);
    }
};
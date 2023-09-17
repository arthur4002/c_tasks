using u64 = uint64_t

const size_t kVectorDefaultReserved = 8;

struct Vector {
    u64 * data;
    size_t size, reserved;
    // size - number of real elements
    // reserved - how much space we have
}

    void PopBack() {
        --size;
    }
    void Realloc_(){
        size_t new_reserve = reserved * 2;
        u64 * new_data = new u64[new_reserve];
    
    for (size_t i = 0;i < size; ++i) {
        new_data[i]=data[i];
    }
    }
    void PushBack(u64 new_element) {
        if (size >= reserved) {
            Realloc_();
        }
      
        data[size] = new_element;
        ++size;
        return;
    }
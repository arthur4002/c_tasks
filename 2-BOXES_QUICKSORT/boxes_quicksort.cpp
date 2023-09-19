#include <iostream>
#include <vector>


struct box {
    uint32_t height;
    uint32_t width;
    uint32_t length;
};

void PrintBox(const box& a) {
    std::cout << "h = " << a.height << " ----- " << "w= " << a.width << " ----- " << "l= " << a.length << std::endl;
}

void SwapBoxes(box& a, box& b) {
    box c;
    c = a;
    a = b;
    b = c;
}

bool BoxComparison(const box& a, const box& b) {
    return (a.height * a.width * a.length) < (b.height * b.width * b.length);
}
uint32_t separation (std::vector<box>& a, uint32_t start, uint32_t stop) { 
    uint32_t i = start - 1;
    for (uint32_t j = start; j<=stop; j++) {
        if (BoxComparison(a[j], a[stop])) {
            i++;
            SwapBoxes(a[i],a[j]);
        }
    }
    SwapBoxes(a[i+1], a[stop]);
    return i+1;
}
void QuickSort(std::vector<box>& a, uint32_t start, uint32_t stop) {
    if (start-stop<=1) {
        return;
    }

    uint32_t element = separation(a,start,stop);
    QuickSort(a,start,element-1);
    QuickSort(a,element+1,stop);
}

int main() {
    size_t N = 10;
    
    std::vector<box> boxes(N);

    for (size_t i = 0; i < N; ++i) {
        boxes[i].height = std::rand() % 100;
        boxes[i].width = std::rand() % 100;
        boxes[i].length = std::rand() % 100;
        PrintBox(boxes[i]);
    }
    
    std::cout << "-----Sort------" << std::endl;
    QuickSort(boxes,0,(N-1));

    for (size_t i = 0; i < N; ++i) {
        PrintBox(boxes[i]);
    }

    return 0;
}


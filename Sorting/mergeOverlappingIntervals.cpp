//
// Created by Pranay Kamble on 05/07/24.
//
#include <iostream>
class Interval {
public:
    int start;
    int end;

    Interval(const int start, const int end) {
        this->start = start;
        this->end = end;
    }

    bool operator> (const Interval &other) const {
        if (this->start == other.start)
            return false;
        return (this->start > other.start);
    }
    bool operator<(const Interval &other) const {
        if (this->start == other.start)
            return false;
        return !(*this > other);
    }

    bool operator==(const Interval &other) const {
        return (this->start == other.start);
    }

};

int hoarePartition(Interval arr[], const int &low, const int &high) {
    const Interval pivot {arr[low]};
    int i {low-1}, j {high+1};

    while (true) {
        do { ++i; } while (arr[i] < pivot);
        do { --j; } while (arr[j] > pivot);
        if (i>=j) return j;
        std::swap(arr[i], arr[j]);
    }
}

void quickSort(Interval arr[], const int &low, const int &high) {
    if (low < high) {
        int p = hoarePartition(arr,low,high);
        quickSort(arr,low,p);
        quickSort(arr,p+1,high);
    }
}

/*bool isOverlapping(const Interval &interval1, const Interval &interval2) {
    Interval larger {interval1 > interval2? interval1 : interval2};
    Interval smaller {interval1 > interval2 ? interval2 : interval1};
    if (larger.start >= smaller.start && larger.start <= smaller.end)
        return true;
    return false;
}

Interval mergeInterval(Interval i1, Interval i2) {
    Interval ret(std::min(i1.start,i2.start), std::max(i1.end,i2.end));
    return ret;
}

void deleteInterval(Interval arr[], int filled, int index) {
    for (int i {index}; i<filled; ++i) {
        arr[i] = arr[i+1];
    }
}

int mergeOverlappingIntervals(Interval arr[],const int size, int filled) {
    quickSort(arr,0,size-1);   //Time Complexity = O(n*log(n))
    int i {0};

    while(i < filled) {
        if (isOverlapping(arr[i], arr[i+1])) {
            arr[i] = mergeInterval(arr[i],arr[i+1]);
            deleteInterval(arr,filled,i+1);
            --filled;
        }else
            ++i;

    }
    return filled;
}*/

int mergeOverlappingIntervals(Interval arr[],const int size) {
    quickSort(arr,0,size-1);

    int index {0};
    for (int i{1}; i<size; ++i) {
        if (arr[index].end >= arr[i].start) {   //Merging of intervals is possible
            arr[index].start = std::min(arr[index].start,arr[i].start);
            arr[index].end = std::max(arr[index].end, arr[i].end);
        }
        else {  //Merging not possible, so we add the Interval seperately without merging
            ++index;
            arr[index] = arr[i];
        }
    }
    return index+1; //Indicates the number of elements present in the array
}

int main() {
    Interval arr[]{Interval(5,10),Interval(2, 3), Interval(6, 8),Interval(1 , 7)};
    const int size {std::size(arr)};
    int filled {std::size(arr)};

    filled = mergeOverlappingIntervals(arr,size);
    for (int i{}; i<filled; ++i)  {
        std::cout << arr[i].start << " " << arr[i].end << "\n";
    }
}

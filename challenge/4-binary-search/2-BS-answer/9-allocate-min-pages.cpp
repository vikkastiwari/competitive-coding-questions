#include <bits/stdc++.h>
using namespace std;

/**
 * @problem  Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
 * There are a ‘m’ number of students, and the task is to allocate all the books to the students.
 * 
 * Allocate books in such a way that:
 * 1. Each student gets at least one book.
 * 2. Each book should be allocated to only one student.
 * 3. Book allocation should be in a contiguous manner. (Maintain the sequence)
 * 
 * You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
 * If the allocation of books is not possible. return -1
 */

int countStudents(vector <int> books, int pages){
    int numberOfStudents = 1;
    int pagesPerStudent = books[0];

    for(int i=1;i<books.size();i++){
        if((pagesPerStudent+books[i]) <= pages){
            pagesPerStudent += books[i];
        }else{
            numberOfStudents += 1;
            pagesPerStudent = books[i];
        }
    }

    return numberOfStudents;
}

/**
 * @brief brute force
 * TC: O(N * (sum(arr[])-max(arr[])+1))
 * SC:O(1)
 */
int allocateBooks(vector <int> books, int s) {
    int n = books.size();
    if(s>n) return -1; // number of students are greater than number of books
    int minAllocPossible = *max_element(books.begin(), books.end());
    int maxAllocPossible = accumulate(books.begin(),books.end(),0);
    for(int pages=minAllocPossible; pages<=maxAllocPossible; pages++){
        if(countStudents(books,pages) == s) {
            return pages;
        }
    }
    return -1;
}

/**
 * @brief binary search
 * TC: O(logn)
 * SC:O(1)
 */
int allocateBooksOpt(vector <int> books, int s) {
    int n = books.size();
    if(s>n) return -1; // number of students are greater than number of books
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(),books.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        // if count of students are more then given
        // means we can assign more pages wrt given number of students
        if(countStudents(books,mid) > s) {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24 }; 
    int s = 4; // number of students
    int ans = allocateBooksOpt(arr, s);
    cout << ans << endl;
    return 0;
}
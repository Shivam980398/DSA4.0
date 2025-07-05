// Book Allocaftion Problem
//  Problem: Allocate books to students such that the maximum number of pages allocated to a student is minimized.
//  Input: Number of books, number of students, and an array representing the number of pages in each book.
//  Output: The minimum possible value of the maximum number of pages allocated to a student.
#include <bits/stdc++.h>
using namespace std;

int checkStudents(int arr[], int n, int pages)
{
    int students = 1;
    int current_pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_pages + arr[i] <= pages)
        {
            current_pages += arr[i];
        }
        else
        {
            students++;
            current_pages = arr[i];
        }
    }
    return students;
}
int allocateBooks(int arr[], int n, int students)
{
    int low = *max_element(arr, arr + n);
    int high = accumulate(arr, arr + n, 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int no_of_students = checkStudents(arr, n, mid);

        if (no_of_students > students)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int books[] = {25, 46, 28, 49, 24};
    int students = 4;
    int n = sizeof(books) / sizeof(books[0]);
    cout << "Minimum pages: " << allocateBooks(books, n, students) << endl;
    return 0;
}
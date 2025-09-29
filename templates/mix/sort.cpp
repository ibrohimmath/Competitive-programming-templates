// Puts sorted elements from the end of the array
void bubbleSort(vector<int>& a) {
    int n = a.size();    
    for (int i = n - 1; i >= 1; i--) {
        bool isSorted = true;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted) break;
    }
}

// Puts sorted elements from the beginning of the array
void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int mnInd = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mnInd]) {
                mnInd = j;
            }
        }
        if (i != mnInd) swap(a[i], a[mnInd]);
    }
}

// In each iteration for index i, contructs a sorted array from range [0, i]
void insertionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1; 
        int x = a[i + 1];
        while (j > 0 && a[j - 1] > x) {
            a[j] = a[j - 1];
            a[j - 1] = x;
            j--;
        } 
    }
}

void quickSort(vector<int> &a, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < a[mid]) i++;
        while (a[j] > a[mid]) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quickSort(a, l, j);
    quickSort(a, i, r);
}
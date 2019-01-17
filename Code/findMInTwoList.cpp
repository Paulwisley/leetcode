class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int mid = (m + n) / 2 + 1;
    int i,j;
    vector<int> vec;
    for ( i = 0, j = 0; i<m&&j<n;)
    {
        if (A[i] > B[j])
            vec.push_back(B[j++]);
        else
            vec.push_back(A[i++]);
        if (vec.size() == mid)
            break;
    }
    while(vec.size() != mid)
    {
        if (i < m)
            vec.push_back(A[i++]);
        if (j < n)
            vec.push_back(B[j++]);
    }
    if ((m+n) % 2 == 0)
        return (vec[vec.size() - 1] + vec[vec.size() - 2]) / 2.0;
    return *(vec.end()-1);
}
};
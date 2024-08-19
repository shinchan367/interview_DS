void nBinaryTriangle(int n) {
    // Write your code here.
    for(int i=0;i<n;i++){
        int stars=1;
        if(i%2==0)stars=1;
        else stars=0;
        for(int j=0;j<=i;j++){
            cout<<stars<<" ";
            stars=1-stars;
        }
        cout<<endl;
    }
}

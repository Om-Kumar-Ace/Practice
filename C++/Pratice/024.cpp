int totalSteps(int n, int k, vector<int> &flowers) {
    //    Write your code here
    int steps =0;
    int current_water=k;
    for(int i=0;i<n;i++){
        if(current_water>=flowers[i]){
            steps++;
            current_water-=flowers[i];
        }else{
            steps+=2*i+1;
            current_water=k-flowers[i];
        }
    }
    return steps;
}
  int max = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
            {
                max = arr[i];
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==max)
            arr[i] = -1;
            
        }
        int max2 = -1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max2)
            max2 = arr[i];
        }
        return max2;
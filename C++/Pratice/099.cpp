string smallestWindow (string str, string p)
    {
        int arr[26]={0},siz=p.length(),j=0,n=str.length();
        int brr[26]={0},mini=INT_MAX,idx=-1;
        char c;
        for(auto i:p) arr[i-'a']++;
        for(int i=0;i<n;i++)
        {
            c=str[i];
            if(arr[c-'a']>=1&&brr[c-'a']<arr[c-'a'])
                siz--;
            brr[c-'a']++;
            while(siz==0)
            {
                if(mini>(1+i-j))
                {
                    mini=1+i-j;
                    idx=i;
                }
                c=str[j];
                j++;
                brr[c-'a']--;
                if(arr[c-'a']>brr[c-'a'])
                    siz++;
            }
            
        }
        if(mini==INT_MAX)
        return "-1";
        return str.substr(1+idx-mini,mini);
    }